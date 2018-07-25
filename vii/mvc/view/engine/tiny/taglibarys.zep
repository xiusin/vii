namespace Vii\Mvc\View\Engine\Tiny;

class Taglibarys
{
    public static left_delimiter = "{";
    public static right_delimiter = "}";
    private tags = [];
    private current_tag = "";
    private tpl = null;
    public function checkAttr(attr, currtag)
    {
        var tagAttr,v;
        if !isset this->tags[currtag] || !isset this->tags[currtag]["attr"]{
            throw new \Exception("tag ".currtag." is not fully defined");
        }
        let tagAttr = explode(",", this->tags[currtag]["attr"]);
        for _,v in tagAttr {
            if !in_array(v,attr) {
                throw new \Exception("tag ".currtag." is not support attr:".v);
            }
        }
        return this;
    }

    public function parse(string! content)->string
    {
        var tags = [];
        var key,value,_function,param_attr,arr,attrs,attr_str,preg,content,level;
        let tags = this->tags;
        for key,value in tags {
            let _function = "_" . key;
            let param_attr = "";
            let arr = [];
            let attrs = [];
            let attr_str = "[^\\".Taglibarys::right_delimiter."]*";
            if isset value["block"] && !value["block"] {
                let this->current_tag = key;
                let preg = "/\\" . Taglibarys::left_delimiter . key . "\s+(" . attr_str . ")\s*\/\\".Taglibarys::right_delimiter."/isU";
                if (!preg_match(preg, content, arr)) {
                    continue;
                }
                let content = preg_replace_callback(preg, [this, "callback"], content);
            }elseif !isset value["block"] || (isset value["block"] && value["block"]) {
                let level = isset(value["level"]) ? value["level"] : 1;
                let preg = "/\\" . Taglibarys::left_delimiter . key . "\s+(" . attr_str . ")\\".Taglibarys::right_delimiter."(.*?)\\".Taglibarys::left_delimiter."\/" . key . "\\".Taglibarys::right_delimiter."/is";
                let this->current_tag = key;
                var i;
                for i in range(0,level) {
                   let content = preg_replace_callback(preg, [this, "callback"], content);
                }
            }
        }
        return content;
    }

    private function _attr(string! param_attr)->array
    {
        var xml,_array;
        if (param_attr == "") {
            return [];
        }
        let xml = simplexml_load_string("<tpl><tag " . param_attr . "/></tpl>");
        if typeof xml != "object" ||  typeof xml->tag!="object"  {
            throw new \Exception("XML标签属性错误," . param_attr);
        }
        let xml = (array)(xml->tag->attributes());
        let _array = array_change_key_case(xml["@attributes"]);
        return _array;
    }

    public function callback(array! arr)
    {
        var _function,param_attr,param_content,attrs,attr_key;
        if (count(arr) === 0) {
            return "";
        }
        let _function = "_" . this->current_tag;
        let param_attr = arr[1];
        let param_content = !isset arr[2] ? "" : arr[2];
        let attrs = this->_attr(param_attr);
        let attr_key = array_keys(attrs);
        if(!method_exists(this,_function)){
            throw new \Exception("tag function "._function . "not exists");
        }
        return this->checkAttr(attr_key, this->current_tag)->{_function}(attrs, param_content);
    }
}
