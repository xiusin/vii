namespace Vii;

class UrlManager
{
    protected baseUri = "/";

    protected staticBaseUri = "/";

    protected basePath = "";

    /**
     * @param $baseUri string 所有地址的前缀不包含host
     */
    public function setBaseUri(baseUri)
    {
        let this->baseUri = baseUri;
        return this;
    }

    /**
     * @param $staticBaseUri string 设置静态文件的基本URI
     */
    public function setStaticBaseUri(staticBaseUri)
    {
        let this->staticBaseUri = staticBaseUri;
        return this;
    }

    public function getBaseUri()
    {
        return this->baseUri;
    }

    public function getStaticBaseUri()
    {
        return this->staticBaseUri;
    }


    /**
     * 设置本地文件绝对路径前缀
     * @param $basePath string 本地文件的绝对路径前缀
     * @return $this
     */
    public function setBasePath(basePath) ->string
    {
        let this->basePath = basePath;
        return this;
    }

    public function getBasePath() -> string
    {
        return this->basePath;
    }

    /**
     * 获取本地文件地址字符串
     * @param $path string 本地文件字符串地址
     */
    public function path(path)
    {
        return trim(this->basePath) . path;
    }

    /**
     * 获取静态文件网络资源地址
     * @param $uri string|array 静态文件URI字符串
     */
    public function getStatic(uri) -> string
    {
        return this->staticBaseUri . uri;
    }

    /**
     * 获取URI地址
     * @param $uri  string 需要拼接的字符串
     * @param array $params 其他额外参数
     * @return string
     */
    public function get(uri,array params=[]) -> string
    {
        return this->baseUri . uri  . this->buildParams(params);
    }

    /**
     * 组建参数字符串
     * @param array $params 参数数组
     * @return string
     */
    protected function buildParams(array params) -> string
    {
        if(empty(params)){
            return "";
        }
        return "?" . http_build_query(params);
    }
}
