namespace Vii\Mvc\View\Engine;

use Vii\Exceptions\ViewException;
use Vii\Ioc;
use Vii\Mvc\View\Engine\Tiny\Compiler;
use Vii\Interfaces\ViewInterface;
use Vii\Interfaces\IocInterface;
use Vii\Interfaces\EngineInterface;

class Tiny implements EngineInterface
{
    protected compileDir {get};
    protected options {set, get};
    protected compiler;
    protected view;
    protected di;
    protected extension;
    public function __construct(<ViewInterface> view, <IocInterface> ioc = null)
    {
        let this->view = view;
        if !ioc {
            let this->di = Ioc::getDefault();
        }
        let this->di = ioc;
    }

    /**
     * 获取编译组件
     */
    public function getComiler(){
        if !this->compiler {
            let this->compiler = new Compiler(this);
        }
        return this->compiler;
    }

    /**
     * 渲染模板
     * @type {Array}
     */
    public function render(string! path , array! data = [])
    {
        var compiled,compile_file;
        if this->compileDir {
            let compile_file = this->compileDir . "/" . basename(path). ".phtml"; //编译文件
        }else{
            let compile_file = dirname(path) . "/" . basename(path). ".phtml"; //编译文件
        }
        ob_start();
        extract(data, EXTR_OVERWRITE);
        let compiled = this->getComiler()->compile(file_get_contents(path));
        if !is_dir(dirname(compile_file)) {
            mkdir(dirname(compile_file),true);
        }
        file_put_contents(compile_file, compiled);
        require(compile_file);
        let compiled = ob_get_clean();
        this->view->setContent(compiled);   //向view内填充解析内容
        return compiled;
    }

    public function partial(string! path, array data = []) -> string
    {
        return this->view->partial(path, data);
    }

    public function getContent(){
        return this->view->getContent();
    }

}
