namespace Vii;

use Vii\Exceptions\UploadFileException;

class UploadFileInfo
{
    public info = [];
    public error = "";

    public function __construct(fileinfo)
    {
        if !isset(fileinfo["tmp_name"]) {
            throw new UploadFileException("上传文件信息传入错误");
        }
        let this->info = fileinfo;
    }

    public function isUploadFile()
    {
        return is_uploaded_file(this->info["tmp_name"]);
    }

    protected function hasError()
    {
        switch (this->info["error"]) {
            case 1:
                let this->error = "文件大小超出了服务器的空间大小";
                break;
            case 2:
                let this->error = "文件超出了表单承载范围.";
                break;
            case 3:
                let this->error = "该文件只被部分上传";
                break;
            case 4:
                let this->error = "没有找到要上传的文件";
                break;
            case 5:
                let this->error = "服务器临时文件夹丢失";
                break;
            case 6:
                let this->error = "文件写入到临时文件夹出错";
                break;
            default:
                return false;
        }
        return true;
    }

    public function getSize()
    {
        return this->info["size"];
    }

    public function getName()
    {
        return this->info["name"];
    }

    public function getType()
    {
        return this->info["type"];
    }

    public function getExt()
    {
        var finfo = explode(".", this->getName());
        return end(finfo);
    }

    public function getTmpName()
    {
        return this->info["tmp_name"];
    }

    public function moveTo(destination_file)
    {
        if empty(destination_file) || !is_dir(dirname(destination_file)) {
            throw new UploadFileException("移动临时文件到目标目录失败，原因：不存在");
        }
        if this->hasError() {
            return false;
        }
        if move_uploaded_file(this->getTmpName(), destination_file) {
            return true;
        }
        let this->error = "移动文件失败";
        return false;
    }
}
