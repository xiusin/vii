namespace Vii;

use Vii\Ioc;

//代码来源 @ice
class Dump
{

    protected detailed = false { get, set };
    protected plain = false { get, set };
    protected skipIoc = true { get, set };
    protected methods = [];
    protected styles = [];
    
    public function __construct(boolean detailed = true, var styles = [])
    {
        if typeof styles == "array" {
            this->setStyles(styles);
        } elseif typeof styles == "boolean" {
            let this->plain = styles;
        }
        let this->detailed = detailed;
    }

    /**
     * 打印所有传入的变量
     */
    public function all(var data) -> string
    {
        return call_user_func_array([this, "vars"], data);
    }

    protected function getStyle(string! type) -> string
    {
        var style;

        if fetch style, this->styles[type] {
            return style;
        } else {
            return "color:gray";
        }
    }

    public function setStyles(array styles = []) -> array
    {
        var defaultStyles;

        if typeof styles != "array" {
            throw new \Exception("设置的样式参数必须为数组");
        }

        let defaultStyles = [
            "pre": "background-color:#f9f9f9; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333",
            "arr": "color:red",
            "bool": "color:green",
            "float": "color:fuchsia",
            "int": "color:blue",
            "null": "color:black",
            "num": "color:navy",
            "obj": "color:purple",
            "other": "color:maroon",
            "res": "color:lime",
            "str": "color:teal"
        ];

        let this->styles = array_merge(defaultStyles, styles);
        return this->styles;
    }

    public function one(variable, string name = null) -> string
    {
        return this->variable(variable, name);
    }

    protected function output(variable, name = null, tab = 1) -> string
    {
        var key, value, output, space, type, attr;

        let space = "  ",
            output = "";

        if name {
            let output = name . " ";
        }

        if typeof variable == "array" {
            let output .= strtr((this->plain ? "array (:count) (\n" : "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n"), [":style": this->getStyle("arr"), ":count": count(variable)]);

            for key, value in variable {
                let output .= str_repeat(space, tab) . strtr((this->plain ? "[:key] => " : "[<span style=':style'>:key</span>] => "), [":style": this->getStyle("arr"), ":key": key]);

                if tab == 1 && name != "" && !is_int(key) && name == key {
                    continue;
                } else {
                    let output .= this->output(value, "", tab + 1) . "\n";
                }
            }
            return output . str_repeat(space, tab - 1) . ")";
        }

        if typeof variable == "object" {
            var className;

            let className = get_class(variable),
                output .= strtr((this->plain ? "object :class" : "<b style=':style'>object</b> :class"), [":style": this->getStyle("obj"), ":class": className]);

            if get_parent_class(variable) {
                let output .= strtr((this->plain ? " extends :parent" : " <b style=':style'>extends</b> :parent"), [":style": this->getStyle("obj"), ":parent": get_parent_class(variable)]);
            }
            let output .= " (\n";

            if this->skipIoc && variable instanceof Ioc {
                // Skip 跳过打印Ioc数据
                let output .= str_repeat(space, tab) . "[skipped]\n";
            } elseif !this->detailed {
                // 只打印public 属性
                for key, value in get_object_vars(variable) {
                    let output .= str_repeat(space, tab) . strtr((this->plain ? "->:key (:type) = " :  "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = "), [":style": this->getStyle("obj"), ":key": key, ":type": "public"]);
                    let output .= this->output(value, "", tab + 1) . "\n";
                }
            } else {
                // 打印所有属性
                do {
                    let attr = each(variable);

                    if !attr {
                        continue;
                    }
                    let key = attr["key"],
                        value = attr["value"];

                    if !key {
                        continue;
                    }

                    // 通过字符 "\x00" 拆分数据
                    let key = explode(chr(0), key),
                        type = "public";

                    if isset key[1] {
                        let type = "private";

                        if key[1] == "*" {
                            let type = "protected";
                        }
                    }
                    let output .= str_repeat(space, tab) . strtr((this->plain ? "->:key (:type) = " : "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = "), [":style": this->getStyle("obj"), ":key": end(key), ":type": type]),
                        output .= this->output(value, "", tab + 1) . "\n";
                } while attr;
            }

            let attr = get_class_methods(variable),
                output .= str_repeat(space, tab) . strtr((this->plain ? ":class methods: (:count) (\n" : ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n"), [":style": this->getStyle("obj"), ":class": className, ":count": count(attr)]);

            if in_array(className, this->methods) {
                let output .= str_repeat(space, tab) . "[already listed]\n";
            } else {
                for value in attr {
                    if !in_array(className, this->methods) {
                        let this->methods[] = className;
                    }
                    if value == "__construct" {
                        let output .= str_repeat(space, tab + 1) . strtr((this->plain ? "->:method(); [constructor]\n" : "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n"), [":style": this->getStyle("obj"), ":method": value]);
                    } else {
                        let output .= str_repeat(space, tab + 1) . strtr((this->plain ? "->:method();\n" : "-><span style=':style'>:method</span>();\n"), [":style": this->getStyle("obj"), ":method": value]);
                    }
                }
                let output .= str_repeat(space, tab) . ")\n";
            }
            return output . str_repeat(space, tab - 1) . ")";
        }

        if is_int(variable) {
            return output . strtr((this->plain ? "integer (:var)" : "<b style=':style'>integer</b> (<span style=':style'>:var</span>)"), [":style": this->getStyle("int"), ":var": variable]);
        }

        if is_float(variable) {
            return output . strtr((this->plain ? "float (:var)" : "<b style=':style'>float</b> (<span style=':style'>:var</span>)"), [":style": this->getStyle("float"), ":var": variable]);
        }

        if is_numeric(variable) {
            return output . strtr((this->plain ? "numeric string (:length) \":var\"" : "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\""), [":style": this->getStyle("num"), ":length": strlen(variable), ":var": variable]);
        }

        if is_string(variable) {
            return output . strtr((this->plain ? "string (:length) \":var\"" : "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\""), [":style": this->getStyle("str"), ":length": strlen(variable), ":var": nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))]);
        }

        if is_bool(variable) {
            return output . strtr((this->plain ? "boolean (:var)" : "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)"), [":style": this->getStyle("bool"), ":var": (variable ? "true" : "false")]);
        }

        if is_null(variable) {
            return output . strtr((this->plain ? "null" : "<b style=':style'>null</b>"), [":style": this->getStyle("null")]);
        }
        return output . strtr((this->plain ? "(:var)" : "(<span style=':style'>:var</span>)"), [":style": this->getStyle("other"), ":var": variable]);
    }

    public function variable(variable, string name = null) -> string
    {
        return strtr((this->plain ? ":output" : "<pre style=':style'>:output</pre>"), [":style": this->getStyle("pre"), ":output": this->output(variable, name)]);
    }


    /**
     * 输出传入变量内容
     * @return string
     */
    public function vars() -> string
    {
        var key, value, output;

        let output = "";

        for key, value in func_get_args() {
            let output .= this->one(value, "var " . key);
        }

        return output;
    }
}
