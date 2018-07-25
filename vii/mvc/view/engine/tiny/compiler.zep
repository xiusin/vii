namespace Vii\Mvc\View\Engine\Tiny;
use Vii\Exceptions\TemplateException;
class Compiler
{
    public left_delimiter = "{";  //变量左边界符
    public right_delimiter = "}"; //变量右边界符
    public content = "";
    public view = null;
    private block = [];
    public nocache = [];          //不缓存数据
    protected varPath = [];
    protected ioc = null;
    protected taglibarys = [];

    public function __construct(view)
    {
        let this->view = view;
    }

    /**
     * 编译模板内容
     */
    public function compile(string! content)
    {
        let this->content = content;
        return this
            ->parsePartial()    //解析片段
            ->parseVar()        //解析变量
            ->parseVarPath()    //解析模板变量
            ->parseTags()      //解析标签
            ->getContent();
    }

    /**
     * 返回解析完成以后的内容
     */
    private function getContent(){
        return this->content;
    }

    /**
     * 设置模板替换变量
     */
    public function setVarPath(array! varpath){
        let this->varPath = varpath;
        return this;
    }

    /**
     * 解析替换模板变量
     */
    public function parseVarPath()
    {
        var key,value;
        for key,value in this->varPath {
            let this->content = str_replace(key,value,this->content);
        }
        return this;
    }


    public function setTagLibarys(array! taglibarys){
        let this->taglibarys = taglibarys;
    }

    /**
     * 解析模板标签
     */
    public function parseTags()
    {
        var tagHandler,v;
        if Empty this->taglibarys {
            let this->taglibarys[] = "Vii\\Mvc\\View\\Engine\\Tiny\\Tag";
        }
        for _,v in this->taglibarys {
            let tagHandler = {v}();
            if !(tagHandler instanceof Taglibarys) {
                throw new TemplateException("标签解析类库必须继承Taglibarys类");
            }
            let this->content = tagHandler->parse(this->content);
        }

        return this;
    }

    public function parseVar()
    {
        var preg ;
        //匹配模板内变量
        let  preg = "#\\" . this->left_delimiter . "((\$.+){0,1}(\|.+){0,1})\\" . this->right_delimiter . "#U";
        //执行回调匹配替换
        let this->content = preg_replace_callback(preg, function (match) {
            var vars,_func,_var,arrayhtml,_default,func,str,v,size;
            let vars = isset match[2] ? match[2] : "";
            let _func = isset match[3] ? ltrim(match[3], "|") : "";
            if vars == "" && _func != "" {
                return "<?php echo " . ltrim(_func, "|") . "; ?>";
            }
            let size = explode(".", vars);
            let _var = array_shift(size);
            let arrayhtml = "";
            for _,v in size{
                if (int) v || v!= 0 {
                    let arrayhtml.= "[".v."]";
                }
            }
            if strpos(_func, "default=") !== false  {   //解析含有default的变量
                let _func = explode("=", _func);
                let _default = _func[1];
                return "<?php if(!isset(" . _var . arrayhtml . ")) echo "._default."; else echo " . _var . arrayhtml . "; ?>";
            }
            if !Empty _func {    //解析函数的变量
                let func = strrpos(_func, "=") === false && strrpos(_func, "(") === false ? _func . "=###" : _func;
                let func = strrpos(_func, "###") === false ? func . ",###" : func;
                let func = explode("=", func);
                let str = str_replace("|", "(", func[0]) . "(";
                let str .= str_replace("###", _var . arrayhtml, func[1]) . str_repeat(")", substr_count(func[0], "|") + 1);
            } else {
                let str = _var . arrayhtml;
            }
            return "<?php  echo  ".str.";  ?>";
        }, this->content);
        let this->content = str_replace("?><?php", "", this->content);
        return this;
    }

    public function parsePartial()
    {
        var preg;
        let preg = "#\\".this->left_delimiter."partial\s+([\'|\"])(.*?)\\1\s*\/\\".this->right_delimiter."#U";
        let this->content = preg_replace_callback(preg,[this,"_partial"],this->content);
        return this;
    }

    public function _partial(array! metchs){
        if Empty metchs[0] || Empty metchs[2]{
            return "";
        }
        return this->view->partial(metchs[2]);
    }

}
