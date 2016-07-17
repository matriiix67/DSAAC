#ifndef _ITERATOR_H
#define _ITERATOR_H

class iterator{
public:
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef  ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    iterator(T* thePosition =  0) { position = thePosition; }

    T& operator*() const { return *position; }
    T* operator->() const { return &*position; }
    iterator& operator++() {
        ++position;
        return *this;
    }
    iterator operator++(int){
        iterator old = *this;
        ++position;
        return old;
    }

    iterator& operator--() {
        --position;
        return *this;
    }
    iterator operator--(int){
        iterator old = *this;
        --position;
        return old;
    }

    bool operator!=(const iterator right) const { return position != right.position; }
    bool operator==(const iterator right) const { return position == right.position; }
protected:
    T* position;
}

#endif
