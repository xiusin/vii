namespace Vii\Mvc\View\Engine\Tiny;
class Tag extends Taglibarys
{
    public tags = [
        "else"      : ["attr" : "", "block" : 0],
        "elseif"    : ["attr" : "condition", "block" : 0],
        "php"       : ["attr" : "like", "block" : 1],
        "if"        : ["attr" : "condition", "block" : 1, "level" : 2],
        "foreach"   : ["attr" : "item,value,key", "block" : 1, "level" : 2],
        "list"      : ["attr" : "data,item", "block" : 1],
        "js"        : ["attr" : "src", "block" : 0]
    ];

    public function _php(params , content)
    {
        return "<?php " . content . "?>";
    }

    public function _if(params, content = null)
    {
        var condition,str;
        let condition = isset(params["condition"]) ? params["condition"] : false;
        if (condition) {
            throw new \Exception("if标签内必须有condition属性");
        }
        let str = "<?php if(" . condition . ") : ?>" .content . "<?php endif; ?>";
        return str;
    }

    public function _else()
    {
        return "<?php  else:  ?>";
    }

    public function _js(params)
    {
        return "<script type=\"text/javascript\" src=\"" . params["src"] . "\"></script>";
    }

    public function _css(params)
    {
        return "<link rel=\"stylesheet\" type=\"text/css\" href=\"" . params["link"] . "\" />";
    }

    public function _foreach(params, content)
    {
        //return "<?php\n\$i=0;\nforeach(" . params['item'] . " as \$key=>" . params['value'] . ") :\n\$i++;
   // \n?>\n" . preg_replace("/\s/", " ", content) . "\n<?php\nendforeach;?>\n";
    }

    public function _list(params, content)
    {
        return  "<?php foreach(".params["data"]." as  ".params["item"]."): ?>".content."<?php endforeach;?>";
    }

}
