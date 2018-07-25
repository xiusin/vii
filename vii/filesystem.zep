namespace Vii;

use Vii\Exceptions\FileNotExistsException;

/**
 * 文件管理类库
 *
 */
class FileSystem
{
    protected static _self = null;

    public function __construct(){
        if !self::_self {
            let self::_self = new self();
        }
    }

    private function exception(path){
        throw new FileNotExistsException("file ".path." is not exists");
    }

    public function exists(string! path){
        return file_exists(path);
    }

    public function get(string! path){
        if this->exists(path) {
            return file_get_contents(path);
        }
        this->exception(path);
    }

    public function requireFile(string! path)
    {
            if this->exists(path) {
                return require(path);
            }
            this->exception(path);
    }

    public function put(string! path,string! content,flag = 0)
    {
        return file_put_contents(path,content,flag);
    }

    public function prepend(string! path,string! content){
        if !this->exists(path) {
            return this->put(path,content,LOCK_EX);
        }
        return this->put(path,content . this->get(path),LOCK_EX);
    }

    public function delete(var paths){
        var success,path;
        let success = true;
        if typeof paths != "array" {
            let paths = func_get_args();
        }
        for _,path in paths {
            if  !unlink(path) {
                let success = false;
            }
        }
        return success;
    }

    /**
     * 将一个文件移动到一个新的位置。
     *
     * @param  string  $path
     * @param  string  $target
     * @return bool
     */
    public function move(path, target)
    {
        return rename(path, target);
    }

    /**
     * 将一个文件复制到一个新的位置。
     *
     * @param  string  $path
     * @param  string  $target
     * @return bool
     */
    public function copy(path, target)
    {
        return copy(path, target);
    }

    /**
     * 从文件路径提取文件名。
     *
     * @param  string  $path
     * @return string
     */
    public function name(path)
    {
        return pathinfo(path, PATHINFO_FILENAME);
    }

    /**
     * 从文件路径提取文件扩展名。
     *
     * @param  string  $path
     * @return string
     */
    public function extension(path)
    {
        return pathinfo(path, PATHINFO_EXTENSION);
    }

    /**
     * 获取给定文件的文件类型。
     *
     * @param  string  $path
     * @return string
     */
    public function type(path)
    {
        return filetype(path);
    }

    /**
     * 获取给定文件的文件大小。
     *
     * @param  string  $path
     * @return int
     */
    public function size(path)
    {
        return filesize(path);
    }

    /**
     * 获取文件的最后修改时间。
     *
     * @param  string  $path
     * @return int
     */
    public function lastModified(path) -> int
    {
        return filemtime(path);
    }

    /**
     * 确定给定的路径是否是一个目录。
     *
     * @param  string  $directory
     * @return bool
     */
    public function isDirectory(directory)->bool
    {
        return is_dir(directory);
    }

    /**
     * 确定路径目录是否可写
     *
     * @param  string  $path
     * @return bool
     */
    public function isWritable(path) -> bool
    {
        return is_writable(path);
    }

    /**
     * 确定给定的路径是否是一个文件。
     *
     * @param  string  $file
     * @return bool
     */
    public function isFile(file) -> bool
    {
        return is_file(file);
    }

    /**
     * Find path names matching a given pattern.
     *
     * @param  string  $pattern
     * @param  int     $flags
     * @return array
     */
    public function glob(pattern, flags = 0) -> array
    {
        return glob(pattern, flags);
    }

    /**
     * 获取目录中的所有文件的数组。
     *
     * @param  string  $directory
     * @return array
     */
    public function files(directory) -> array
    {
        var glob;
        let glob = glob(directory ."/*");

        if !glob {
            return [];
        }
        return array_filter(glob, function(file)
        {
            return filetype(file) == "file";
        });
    }


    /**
     * Create a directory.
     * @param  string  $path    路径
     * @param  int     $mode    权限
     * @param  bool    $recursive   是否递归创建
     * @return bool
     */
    public function makeDirectory(path, mode = 0755, recursive = false)
    {
        return mkdir(path, mode, recursive);
    }

    /**
     * 将目录从一个位置复制到另一个位置。
     *
     * @param  string  $directory
     * @param  string  $destination
     * @param  int     $options
     * @return bool
     */
    public function copyDirectory(directory, destination, options = null)
    {
        if ! this->isDirectory(directory){
            return false;
        }
        let options = options ?options: \FilesystemIterator::SKIP_DOTS;
        if ! this->isDirectory(destination){
            this->makeDirectory(destination, 0777, true);
        }
        var item,items,target,path;
        let items = new \FilesystemIterator(directory, options);
        for _,item in items {
            let target = destination."/".item->getBasename();
            if item->isDir() {
                let path = item->getPathname();
                if ! this->copyDirectory(path, target, options) {
                    return false;
                }
            }else {
                if ! this->copy(item->getPathname(), target) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * 递归删除目录。 目录本身可以选择保留
     * @param  string  $directory
     * @param  bool    $preserve 是否保留目录
     * @return bool
     */
    public function deleteDirectory(directory, bool preserve = false)
    {
        var item,items;
        if (!this->isDirectory(directory)){
             return false;
        }
        let items = new \FilesystemIterator(directory);
        for _,item in items {
            if item->isDir() {
                this->deleteDirectory(item->getPathname());
            }else {
                this->delete(item->getPathname());
            }
        }
        if (! preserve) {
            rmdir(directory);
        }
        return true;
    }

    /**
     * 清空文件夹下所有的文件和文件夹
     * @param  string  $directory
     * @return bool
     */
    public function cleanDirectory(directory)
    {
        return this->deleteDirectory(directory, true);
    }



}
