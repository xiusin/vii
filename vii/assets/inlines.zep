namespace Vii\Assets;

class Inlines
{
    protected type;
    protected content;

    public function getType()
    {
        return this->type;
    }

    public function getContent()
    {
        return this->content;
    }

    public function __construct(type, content)
    {
        this->setType(type)->setContent(content);
    }

    public function setType(type)
    {
        let this->type = type;
        return this;
    }

    public function setContent(content)
    {
        let this->content = content;
        return this;
    }

}