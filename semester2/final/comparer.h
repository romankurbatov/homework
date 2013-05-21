#pragma once

template<typename T>
class Comparer
{
public:
    typedef int compareFunctionType(const T &a, const T &b);
    Comparer(compareFunctionType *compareFunction);
    int compare(const T &a, const T &b);
private:
    const compareFunctionType *compareFunction;
};

template<typename T>
Comparer<T>::Comparer(compareFunctionType *compareFunction) : compareFunction(compareFunction)
{
}

template<typename T>
int Comparer<T>::compare(const T &a, const T &b)
{
    return (*compareFunction)(a, b);
}
