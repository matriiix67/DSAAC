//
//  chainNode.h
//  
//
//  Created by Bourne on 16/5/16.
//
//

#ifndef chainNode_h
#define chainNode_h

template<class T>
struct chainNode
{
    T element;
    chainNode<T> *next;
    
    chainNode() {}
    chainNode(const T& element)
    {
        this->element = element;
    }
    
    chainNode(const T& element, chainNode<T>* next)
    {
        this->element = element;
        this->next = next;
    }

};


#endif /* chainNode_h */
