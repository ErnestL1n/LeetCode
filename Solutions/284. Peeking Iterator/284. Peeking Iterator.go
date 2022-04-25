/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *       
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
    hasnext bool
    peekElement int
    iterator *Iterator
}

func Constructor(iter *Iterator) *PeekingIterator {
    return &PeekingIterator{
        hasnext:iter.hasNext(),
        peekElement:iter.next(),
        iterator:iter,
    }
}

func (this *PeekingIterator) hasNext() bool {
    return this.hasnext
}

func (this *PeekingIterator) next() int {
    res:=this.peekElement
    if this.iterator.hasNext(){
        this.peekElement=this.iterator.next()
    }else{
        this.hasnext=false
    }
    return res
}

func (this *PeekingIterator) peek() int {
    return this.peekElement
}