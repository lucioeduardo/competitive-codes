/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    
    bool cached;
    int nextCache;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    this->cached = false;

	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(this->cached) {
            return this->nextCache;
            this->cached = false;
        }
        this->nextCache = Iterator::next();
        this->cached  = true;
        
        return nextCache;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    
        if(this->cached) {
            this->cached = false;
            return nextCache;
        }
        
        return Iterator::next();
	}
	
	bool hasNext() const {
	    return this->cached || Iterator::hasNext();
	}
};