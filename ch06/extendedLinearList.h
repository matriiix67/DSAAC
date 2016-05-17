

#ifndef _EXTENDEDLINEARLIST_H
#define _EXTENDEDLINEARLIST_H

template<class T>
class extendedLinearList : linearList<T>
{
public:
    virtual ~extendedLinearList() {}
    virtual void clear() = 0;
    virtual void push_back(const T& theElement) = 0;
};

#endif