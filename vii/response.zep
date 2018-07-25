
namespace Vii;
class Response
{
    private content = "";
    private issent = false;
    private rawHeader = [];
    protected statuses = [];

    public function __construct(){
        let this->statuses = [
            100 : "Continue",
            101 : "Switching Protocols",
            102 : "Processing",
            200 : "OK",
            201 : "Created",
            202 : "Accepted",
            203 : "Non-Authoritative Information",
            204 : "No Content",
            205 : "Reset Content",
            206 : "Partial Content",
            207 : "Multi-Status",
            208 : "Already Reported",
            226 : "IM Used",
            300 : "Multiple Choices",
            301 : "Moved Permanently",
            302 : "Found",
            303 : "See Other",
            304 : "Not Modified",
            305 : "Use Proxy",
            307 : "Temporary Redirect",
            308 : "Permanent Redirect",
            400 : "Bad Request",
            401 : "Unauthorized",
            402 : "Payment Required",
            403 : "Forbidden",
            404 : "Not Found",
            405 : "Method Not Allowed",
            406 : "Not Acceptable",
            407 : "Proxy Authentication Required",
            408 : "Request Timeout",
            409 : "Conflict",
            410 : "Gone",
            411 : "Length Required",
            412 : "Precondition Failed",
            413 : "Request Entity Too Large",
            414 : "Request-URI Too Long",
            415 : "Unsupported Media Type",
            416 : "Requested Range Not Satisfiable",
            417 : "Expectation Failed",
            418 : "I\"m a Teapot",
            422 : "Unprocessable Entity",
            423 : "Locked",
            424 : "Failed Dependency",
            426 : "Upgrade Required",
            428 : "Precondition Required",
            429 : "Too Many Requests",
            431 : "Request Header Fields Too Large",
            500 : "Internal Server Error",
            501 : "Not Implemented",
            502 : "Bad Gateway",
            503 : "Ioc Unavailable",
            504 : "Gateway Timeout",
            505 : "HTTP Version Not Supported",
            506 : "Variant Also Negotiates",
            507 : "Insufficient Storage",
            508 : "Loop Detected",
            509 : "Bandwidth Limit Exceeded",
            510 : "Not Extended",
            511 : "Network Authentication Required"
        ];
    }

    public function setStatusCode(code)
    {
        this->setRawHeader("HTTP/1.1  " . code . this->statuses[code]);
    }
    public function setHeader(name, value)
    {
        this->setRawHeader(name . ": " . value);
        return this;
    }
    public function setRawHeader(header)
    {
        let this->rawHeader[] = header;
    }
    public function redirect()
    {
    }
    public function setContent(content)
    {
        let this->content = content;
        return this;
    }
    public function setJsonContent(content, option = 0, depth = 512)
    {
        this->setHeader("Content-type", "application/json");
        let this->content = json_encode(content, option, depth);
        return this;
    }
    public function appendContent(content)
    {
        let this->content = this->getContent() . content;
        return this;
    }
    public function getContent()
    {
        return this->content;
    }
    public function resetHeaders()
    {
        let this->rawHeader = [];
    }
    public function isSend()
    {
        return this->issent;
    }
    public function sendHeaders()
    {
        var v;
        for v in this->rawHeader{
            header(v);
        }
        return this;
    }
    public function sendContent()
    {
        return this->content;
    }
    public function send()
    {
        let this->issent = true;
        return this->sendHeaders()->sendContent();
    }
    public function hasHeader()
    {
        return count(this->rawHeader);
    }

}
