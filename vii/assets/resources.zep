namespace Vii\Assets;

use Vii\Exceptions\AssetsException;

/**
 * 资源对象
 * Class Resources
 * @package Slothful\Assets
 */
class Resources
{

    protected type;

    protected path = "";

    protected local = true;

    /**
     * Resources constructor.
     * @param $type string
     * @param $path string
     * @param bool $local
     * @demo new Resource();
     */
    public function __construct(type, path, local = true)
    {
        this->checkType(type);
        this->setType(type)->setPath(path)->setLocal(local);
    }

    public function getType()
    {
        return this->type;
    }

    public function getPath()
    {
        return this->path;
    }

    public function getLocal()
    {
        return this->local;
    }

    public function setType(type)
    {
        this->checkType(type);
        let this->type = type;
        return $this;
    }


    public function setPath(path)
    {
        let this->path = path;
        return this;
    }


    public function setLocal($local)
    {
        let this->local = local;
        return this;
    }

    private function checkType(type){
        if type != "js" && type!= "css" {
            throw new AssetsException("the resource key $type is not support!");
        }
    }
}
