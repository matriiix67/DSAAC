//
//  chain.h
//  
//
//  Created by Bourne on 16/5/16.
//
//

#ifndef chain_h
#define chain_h

#include "chainNode.h"
#include "linearList.h"

#include <iostream>
#include<sstream>

using namespace std;


template <class T>
class chain : public linearList<T> {
public:
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    ~chain();

    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    void setSize(int theSize);
protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;
    int listSize;
};


template<class T>
void chain<T>::checkIndex(int theIndex) const
{
  if(theIndex < 0 || theIndex >= listSize)
  {
    ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    // throw illegalIndex(s.str());
  }
}

template<class T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        //throw illegalParameterValue(s.str());
    }

    firstNode = nullptr;
    listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;

    if(listSize == 0)
    {
        firstNode = nullptr;
        return ;
    }

    chainNode<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;

    while(sourceNode != nullptr)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }

    targetNode->next = nullptr;
}

template <class T>
chain<T>::~chain()
{
    while(firstNode != NULL)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}


template<class T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);

    chainNode<T>* currentNode = firstNode;
    for(int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;
    return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0;

    while(currentNode != nullptr && currentNode->element != theElement)
    {
        currentNode = currentNode->next;
        index++;
    }

    if(currentNode == nullptr)
        return -1;
    else
        return index;
}

template<class T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);

    chainNode<T>* deleteNode;
    if(theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T>* p = firstNode;
        for(int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next;
    }

    listSize--;
    delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        //throw illegalIndex(s.str());
    }

    if(theIndex == 0)
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        chainNode<T>* p = firstNode;
        for(int i = 0; i < theIndex; i++)
            p = p->next;

        p->next = new chainNode<T>(theElement, p->next);
    }

    listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const
{
    for(chainNode<T>* currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next)
        out << currentNode->element << " ";
}

template<class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}

template<class T>
void chain<T>::setSize(int theSize)
{
    if(theSize >= this.theSize)
        this.theSize = theSize;
    else
    {
        chainNode<T>* p = firstNode;
        for(auto i = 0; i < theSize; i++)
        {
            p = p->next;
        }

        deleteNode = p->next;
        while(deleteNode)
        {
            p = deleteNode->next;
            delete deleteNode;
        }

        this.theSize = theSize;
    }
    
}


#endif /* chain_h */
