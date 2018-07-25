
namespace Vii\Mvc\View\Engine;

use Vii\Exceptions\ViewException;
use Vii\Ioc;
use Vii\Mvc\View\Engine\Sleet\Compiler;
use Vii\Interfaces\ViewInterface;
use Vii\Interfaces\IocInterface;
use Vii\Interfaces\EngineInterface;

/**
 * Sleet template engine. Syntax is similar to Twig, Volt or Django.
 */
class Sleet implements EngineInterface
{
    protected compiler { get };
    protected view;
    protected options { set };
    protected di;

    public function __construct(<ViewInterface> view, <IocInterface> ioc = null)
    {
        let this->view = view;
        if !ioc {
            let this->di = Ioc::getDefault();
        }
        let this->di = ioc;
    }

    /**
     * Compile the .sleet file.
     *
     * @param string path 编译的文件
     * @return string Path 编译文件地址
     */
    public function compile(string! path)
    {
        var compileDir, compile, trim, dir, file, compiledPath, old, compiled;

        fetch trim, this->options["trimPath"];
        fetch compileDir, this->options["compileDir"];
        fetch compile, this->options["compile"];

        let dir = rtrim(compileDir, DIRECTORY_SEPARATOR) . str_replace(trim, "", realpath(dirname(path))),
            file = basename(path, ".sleet"),
            compiledPath = dir . DIRECTORY_SEPARATOR . file . ".phtml";


        switch compile {
            case Compiler::NEVER:
                let compile = false;
            break;
            case Compiler::NOT_EXIST:
                let compile = !file_exists(compiledPath);
            break;
            case Compiler::IF_CHANGE:
                if !file_exists(compiledPath) {
                    let compile = true;
                } else {
                    let compile = md5_file(compiledPath);
                }
            break;
            default: // Compiler::ALWAYS:
                let compile = true;
            break;
        }

        if compile {
            let this->compiler = new Compiler(this),
                compiled = this->compiler->compile(path);

            // Check if file was changed
            if typeof compile == "string" {
                if compile != md5(compiled) {
                    let compile = true;
                }
            }

            if compile === true {
                if !is_dir(dir) {
                    let old = umask(0);
                    mkdir(dir, 0777, true);
                    umask(old);
                }

                if file_put_contents(compiledPath, compiled) === false {
                    throw new ViewException("模板编译目录不可写");
                }
            }
        }

        return compiledPath;
    }

    public function render(string! path, array data = [])
    {
        let path = this->compile(path);

        extract(data);
        ob_start();

        require path;
        return ob_get_clean();
    }

    /**
     * Get the view content.
     *
     * @return string
     */
    public function getContent() -> string
    {
        return this->view->getContent();
    }

    /**
     * Load some view.
     *
     * @param string path
     * @param array data
     */
    public function load(string! path, array data = []) -> string
    {
        return this->view->load(path, data);
    }

    /**
     * Load some partial view.
     *
     * @param string path
     * @param array data
     */
    public function partial(string! path, array data = []) -> string
    {
        return this->view->partial(path, data);
    }
}
