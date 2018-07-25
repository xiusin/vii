namespace Vii\Assets;
use Vii\Exceptions\AssetsException;
class Manager
{

    
    protected collection = [];
    protected options = [];

    public function __construct(prefix = "")
    {
        let this->collection["css"] = this->collection("css")->setPrefix(prefix);
        let this->collection["js"] = this->collection("js")->setPrefix(prefix);
    }

    public function setOptions (array options){
        let this->options = options;
    }

    public function getOptions () {
        return this->options;
    }

    public function set(id, <Collection> collection)
    {
        if this->hasCollection(id) {
            throw new AssetsException("the collection key ".id." is exists");
        }
        let this->collection[id] = collection;
        return this;
    }

    public function get(id)
    {
        if !this->hasCollection(id) {
            throw new AssetsException("the collection key ".id." is not exists");
        }
        return this->collection[id];
    }


    public function addCss(path, local = true)
    {
        this->collection["css"]->add(new Resources("css", path, local));
        return this;
    }

    public function addJs(path, local = true)
    {
        this->collection["js"]->add(new Resources("js", path, local));
        return this;
    }

    public function addInlineCss(content)
    {
        this->collection["css"]->addInlineCss(content);
        return this;
    }

    public function addInlineJs(content)
    {
        this->collection["js"]->addInlineJs(content);
        return this;
    }

    public function addResource(<Resources> resources)
    {
        this->collection[strtolower(resources->getType())]->addResource(resources);
        return this;
    }

    // /**
    //  * 获取或创建一个资源集合
    //  * @param $name
    //  * @return Collection
    //  * @throws AssetsException
    //  */
    public function collection(name)
    {
        if !name {
            throw new AssetsException("the collection name is empty");
        }
        if !$this->hasCollection(name) {
            let this->collection[name] = new Collection();
        }
        return this->collection[name];
    }

    protected function hasCollection(name)
    {
        return isset(this->collection[name]);
    }

    public function getCss()
    {
        return this->collection("css");
    }

    public function getJs()
    {
        return this->collection("js");
    }

    public function output(collectionName = "", type = "")
    {
        if(type == "css" || empty(type)) {
            this->outputCss(collectionName);
        }
        if(type == "js" || empty(type)){
            this->outputJs(collectionName);
        }
    }

    public function outputinline(collectionName = "", type = "")
    {
        if(type == "css" || empty(type)){
                this->outputInlineCss(collectionName);
        }
        if(type == "js" || empty(type)){
            this->outputInlineJs(collectionName);
        }
    }

    public function outputCss(collectionName = "")
    {
        var collection,v,prefix,res;
        let collection = this->collection(collectionName ? collectionName : "css");
        let prefix = collection->getPrefix();
        let res = collection->getResources();
        for v in res["css"] {
            echo "<link rel=\"stylesheet\" type=\"text/css\" href=\"" . rtrim(prefix, "/") . "/" . trim(v->getPath(), "/") . "\">" . "\r\n";
        }
    }

    public function outputInlineCss(collectionName = "")
    {
        var v;
        var collection = $this->collection(collectionName ? collectionName : "css");
        var res = $collection->getInline("css");
        echo "<style>";
        for v in res {
            echo v->getContent();
        }
        echo "</style>\r\n";
    }

    public function outputJs(collectionName = "")
    {
        var v;
        var collection = this->collection(collectionName ? collectionName : "js");
        var prefix = collection->getPrefix();
        var res = collection->getJs();
        for v in res {
            echo "<script type=\"text/javascript\" src=\"" . rtrim(prefix, "/") . "/" . trim(v->getPath(), "/") . "\"></script>" . "\r\n";
        }
    }

    public function outputInlineJs(collectionName = "")
    {
        var v;
        var collection = this->collection(collectionName ? collectionName : "js");
        var res = collection->getInline("js");
        echo "<script>";
        for v in res {
            echo v->getContent();
        }
        echo "</script>\r\n";
    }

    public function getCollections()
    {
        return this->collection;
    }
}
