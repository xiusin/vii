namespace Vii\Log;
use Vii\Interfaces\LogInterface;
use Vii\Log;
use Vii\Exceptions\LogException;
//日志记录
class File extends Driver implements LogInterface
{
    private _file ;
    private _timeFormat;
    private _logformat;
    public function __construct(string! filePath) {
        var filename,ext;
        //防止日志过大,分割文件尺寸
        if file_exists(filePath) && filesize(filePath) >= 1024 * 1024 * Driver::_logFileSize {   //按照设置的文件尺寸分隔
            let ext = substr(filePath,strrpos(this->_file,".") );
            let filename = strtr(filePath,ext,"");
            rename(filePath,filename . count(glob(filename . "*")) . ext);
        }
        this->createLogFile(filePath);
        let this->_file = filePath;
        this
        ->setTimeFormat("Y-m-d H:i:s")
        ->setLogFormat( "[".Log::PLACEHOLDER_TIME."] " . Log::PLACEHOLDER_LEVEL . ": " . Log::PLACEHOLDER_MESSAGE);
    }

    //设置时间格式
    public function setTimeFormat (string! timeFormat){
        let this->_timeFormat = timeFormat;
        return this;
    }

    private function createLogFile(string! filePath){
        var _dirname;
        let _dirname = dirname(filePath);
        if !is_dir(_dirname) {
            mkdir(_dirname , 0777 , true);
        }
        if touch(filePath) {    //创建这个文件
            throw new LogException("日志文件[".filePath."]创建失败");
        }
        if !is_writable(filePath) {
            throw new LogException("日志文件".filePath."]无写权限");
        }
    }

    public function setLogFormat(string! logformat){
        let this->_logformat = logformat;
        return this;
    }
    //placeholders为message里的占位符，可以从占位符内替换变量
    public function debug(string message,array placeholders  = []){
        this->log(Log::DEBUG,message,placeholders);
    }

    public function info(string message,array placeholders  = []){
        this->log(Log::INFO,message,placeholders);
    }

    public function alert(string message,array placeholders  = []){
        this->log(Log::ALERT,message,placeholders);
    }

    public function error(string message,array placeholders  = []){
        this->log(Log::ERROR,message,placeholders);
    }

    public function notice(string message,array placeholders  = []){
        this->log(Log::NOTICE,message,placeholders);
    }

    public function warning(string message,array placeholders  = []){
        this->log(Log::WARNING,message,placeholders);
    }

    private function _replacePlaceholders (string! message ,array placeholders  = []){
        var k,v,_replacePlaceholders;
        for k,v in placeholders {
            let _replacePlaceholders["{".k."}"] = v;
        }
        strtr(message,_replacePlaceholders);
    }

    public function log(string! logLevel , string! message,array placeholders = []) -> void
    {
        //不启用日志记录
        if !Driver::_enable {
            return ;
        }
        //调试机制记录级别
        if !in_array(Driver::_recordLevel,logLevel) && ! Empty Driver::_recordLevel {
            return ;
        }
        var line;
        let line =  strtr(this->_logformat,[
            Log::PLACEHOLDER_TIME : date(this->_timeFormat),
            Log::PLACEHOLDER_LEVEL : strtoupper(logLevel),
            Log::PLACEHOLDER_MESSAGE : this->_replacePlaceholders(message,placeholders)
        ]) . PHP_EOL;
        file_put_contents(this->_file,line,FILE_APPEND);
    }
}
