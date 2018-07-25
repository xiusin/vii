namespace Vii;
use Vii\Dump;
class Helper
{
        /**
         * 对象转数组方法
         * @return {array}
         */
        public static function obj2arr (object! obj) -> array
        {
            var arr,key,val;
            let arr = get_object_vars(obj);
            for key,val in arr
            {
               let val = (is_array(val) || is_object(val)) ? self::obj2arr(val) : val;
               let arr[key] = val;
            }
            return arr;
        }

        //手机系统
        public static function getOs() -> string
        {
            var browser;
            if stripos(_SERVER["HTTP_USER_AGENT"], "iphone") || stripos(_SERVER["HTTP_USER_AGENT"], "ipod") {
                let browser = "ios";
            } elseif (stripos(_SERVER["HTTP_USER_AGENT"], "ipad")) {
                let browser = "ios";
            } elseif (stripos(_SERVER["HTTP_USER_AGENT"], "android")) {
                let browser = "android";
            } else {
                let browser = "other";
            }
            return browser;
        }

       /**
        * 返回Http请求方法
        * @return
        */
        public static function  getHttpMethod() -> string
        {
            return strtoupper(_SERVER["REQUEST_METHOD"]);
        }

        /**
         * 获取文件扩展
         */
        public static function getFileExtension(string! path)->string
        {
            return substr(path,strrpos(path,"."));
        }

        //检测文件是否是以某个字符串开始的
        public static function start_with(string! _string,string! _find) -> boolean
        {
            return starts_with(_string,_find);
        }

        /**
         * I18n快速助手
         * @type {Array}
         */
        public static function _t(string! strOrId , array! value = []) -> string
        {
            return I18n::getDefault()->translate(strOrId , value);
        }

        /**
         * Dump助手
         * @output string
         * @return void
         */
        public static function dump() -> void
        {
            var dump;
            let dump = new Dump();
            echo dump->all(func_get_args());
            exit();
        }

}
