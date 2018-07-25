namespace Vii;

/**
 * 全局可用注册类库,不共享实例
 */
final class Registry implements \ArrayAccess, \Countable, \Iterator
{
     private _data;
     public final function __construct(){
        let this->_data = [];
     }

     public final function offsetExists (var offset ) {
         return isset(this->_data[offset]);
     }

     public final function offsetGet (var offset ) {
         return this->_data[offset];
     }

     public final function offsetSet (var offset , var value ) {
         let this->_data[offset] = value;
     }

     public final function offsetUnset ( var offset ) {
         unset(this->_data[offset]);
     }

     public final function count(){
         return count(this->_data);
     }

     public final function current(){
         return current(this->_data);
     }

     public final function key(){
         return key(this->_data);
     }

     public final function next (){
         return next(this->_data);
     }

     public final function rewind(){
         return reset(this->_data);
     }

     public final function valid(){
         return key(this->_data) !== null;
     }
}
