namespace Vii;
use Vii\Exceptions\FileNotExistsException;
/**
 * <code>
 * @创建
 * $i18n = Vii\I18n::getDefault([
 *      "lang"=>"zh",
 *      "dir"=>"app/lang/"
 * ]);
 *
 * @配置文件
 * app/lang/zh.php
 * return [
 *      "MESSAGE_ERROR"=>"消息错误",
 *      "CURR"  =>" :attr: 是替换出来的"
 * ];
 *
 * @使用
 * Vii\Httper::_t("MESSAGE_ERROR");
 * Vii\Httper::_t("CURR",['attr'=>'我是attr']);
 *
 * </code>
 */
class I18n
{
        protected static i18n;
        protected _options = [];
        protected _messages;
        private function __construct(var options = []){
                this->setOptions(options)->getMessage();    //设置参数
        }
        private function __clone(){}
        public static function getDefault(var options = [])
        {
            if !self::i18n {
                let self::i18n = new self(options);
            }
            return self::i18n;
        }
        /**
         * 获取语言配置
         */
        public function getMessage (){
            var file;
            if !isset this->_options["lang"] || this->_options["dir"]{
                throw new \Exception("没有i18n对应的参数options[lang] or options[dir]");
            }
            let file = this->_options["dir"] . this->_options["lang"] . ".php";
            if !file_exists (file) {
                throw new FileNotExistsException("语言配置文件:".file."不存在");
            }
            let this->_messages = require file;
            if typeof this->_messages != "array" {
                throw new \Exception("语言配置文件必须返回为数组");
            }
            return this;
        }
        /**
         * 设置配置参数
         */
        public function setOptions(var options = []){
            let this->_options = options;
            return this;
        }
        /**
         * 获取配置参数
         */
        public function getOptions(){
            return this->_options;
        }

        /**
         * 翻译
         * @param str string 要翻译的内容
         * @param value array 翻译内容内部占位符替换数组
         */
        public function translate(string! strOrId , array! value = []){
            var message;
            if isset this->_messages[strOrId] {
                let message = this->_messages[strOrId];
            }else{
                let message = strOrId;
            }
            if count(value) {
                var k,v,tmp = [];
                for k,v in value {
                    let tmp [":".k.":"] = v;
                }
                return strtr(message,tmp);
            }
            return message;
        }
}
