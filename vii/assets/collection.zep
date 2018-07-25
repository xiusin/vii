namespace Vii\Assets;

class Collection
{

    private prefix = "";
    private join = false;
    private local = true;
    private css = [];
    private js = [];
    private _inline = ["css":[],"js":[]];
    private targetPath = "";
    private targetUri = "";

    public function getPrefix()
    {
        return this->prefix;
    }

   public function getLocal()
    {
        return this->local;
    }

    public function getCss(){
        return this->css;
    }

    public function getJs(){
        return this->js;
    }

    public function getInline(type=""){
        if(type) {
            return this->_inline[type];
        }
        return this->_inline;
    }

    public function getResources()
    {
        return ["css" : this->css, "js" : this->js, "inline" : this->_inline];
    }

    public function add(<Resources> _resource)
    {
        var type;
        let type = _resource->getType();
        if type == "js" {
            let this->js[] = _resource;
        }  
        if type == "css" {
            let this->css[] = _resource;
        }
        return this;
    }

    public function addCss(path, local = true)
    {
        let this->css[] = new Resources("css", path, local);
        return this;
    }

    public function addInlineCss(content)
    {
        let this->_inline["css"][] = new Inlines("css", content);
        return this;
    }

    public function addJs(path, local = true)
    {
        let this->js[] = new Resources("js", path, local);
        return this;
    }

    public function addInlineJs(content)
    {
        let this->_inline["js"][] = new Inlines("js", content);
        return this;
    }

    public function setPrefix(prefix)
    {
        let this->prefix = prefix;
        return this;
    }

    public function setLocal(local)
    {
        let this->local = local;
        return this;
    }

    public function join(join)
    {
        let this->join = join;
        return this;
    }

    // 设置最终输出文件
    public function setTargetPath(targetPath)
    {
        let this->targetPath = targetPath;
        return true;
    }

    // 设置HTML需要引用的HTML地址
    public function setTatgetUri(targetUri)
    {
        let this->targetUri = targetUri;
        return this;
    }

}