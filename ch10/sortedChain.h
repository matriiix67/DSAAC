//
// Created by Bourne on 7/17/16.
//

#ifndef DSAAC_SORTEDCHAIN_H
#define DSAAC_SORTEDCHAIN_H

#include "dictionary.h"

template<class K, class E>
struct pairNode{
    pair<const K, E> element;
    pairNode<K, E>* next;

    pairNode() {}
};

template<class K, class E>
class sortedChain : public dictionary{
    pairNode<K, E> find(const K& theKey) const;
    void insert(const pair<const K, E>& thePair);
    void erase(const K& theKey);
};



#endif //DSAAC_SORTEDCHAIN_H
