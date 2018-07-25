namespace Vii\Interfaces;

interface DbInterface
{
    public function findOne(string! from, var where = [], array options = [], array fields = []);
}
