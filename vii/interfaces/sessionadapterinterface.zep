namespace Vii\Interfaces;

interface SessionAdapterInterface
{
        public function start();
        public function get(var index,var defaultValue="");
        public function set(var index,var value);
        public function has(var index);
        public function remove(var index);
        public function getId();
        public function isStarted();
        public function destroy();
}
