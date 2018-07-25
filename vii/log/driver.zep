namespace Vii\Log;

abstract class Driver
{
    public static _recordLevel = [];
    public static _enable = true;
    public static _logFileSize = 1;

    //设置日志记录级别
    public function setRecordLevel(array! recordLevel = []){
        let Driver::_recordLevel = recordLevel;
    }

    //禁用日志记录
    public function disable(){
        let Driver::_enable = false;
    }

    //设置日志文件分隔尺寸 单位 MB
    public function setLogFileSize(int _size = 1){
        let Driver::_logFileSize = _size;
    }

    //派生类必须实现的方法
    public function log(string! logLevel , string! message,array placeholders = []) -> void;
}
