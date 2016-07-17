//
// Created by Bourne on 7/17/16.
//

#ifndef DSAAC_SKIPLIST_H
#define DSAAC_SKIPLIST_H

#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class K, class E>
struct skipNode{
    typedef  pair<const K, E> pairType;
    pairType element;
    skipNode<K, E> **next;

    skipNode(pairType& thePair, int size) : element(thePair) { next = new skipNode<K, E>* [size]; }
};

template<class K, class E>
class skipList{
public:
    skipList(K largeKey, int maxPairs, float prob);
    pair<const K, E>* find(const K& theKey) const;
    int level() const;
    skipNode<K, E>* search(const K& theKey) const;
    void insert(const pair<const K, E>& thePair);
    void erase(const K& theKey);

private:
    float cutOff;
    int levels;
    int dSize;
    int maxLevel;
    K tailKey;
    skipNode<K, E>* headerNode;
    skipNode<E, E>* tailNode;
    skipNode<K, E>** last;

};

#endif //DSAAC_SKIPLIST_H

template <class K, class E>
skipList<K, E>::skipList(K largeKey, int maxPairs, float prob) {
    cutOff = prob * RAND_MAX;
    maxLevel = (int) ceil(logf((float) maxPairs) / logf(1/prob)) - 1;
    levels = 0;
    dSize = 0;
    tailKey = largeKey;

    pair<K, E> tailPair;
    tailPair.first = tailKey;
    headerNode = new skipNode<K, E> (tailPair, maxLevel + 1);
    tailNode = new skipNode<K, E> (tailPair, 0);
    last = new skipNode<K, E> *[maxLevel + 1];

    for(int i = 0; i <= maxLevel; i++)
        headerNode->next[i] = tailNode;
}


template <class k, class E>
pair<const K, E>* skipList<K, E>::find(const K &theKey) const {
    if(theKey >= tailKey)
        return nullptr;

    skipNode<K, E>* beforeNode = headerNode;
    for(int i = levels; i >= 0; i--)
        while(beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];

    if(beforeNode->next[0]->element.first == theKey)
        return &beforeNode->next[0]->element;

    return nullptr;
}


template <class K, class E>
int skipList<K, E>::level() const {
    int lev = 0;
    while(rand() <= cutOff)
        lev++;

    return (lev <= maxLevel) ? lev : maxLevel;
}


template <class K, class E>
skipNode<K, E>* skipList<K, E>::search(const K &theKey) const {
    skipNode<K, E>* beforeNode = headerNode;
    for(int i = levels; i >=0; i--){
        while(beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];
        last[i] = beforeNode;
    }

    return beforeNode->next[0];
}


template <class K, class E>
void skipList<K, E>::insert(const pair<const K, E> &thePair) {
    
}
