#include <iostream>
using namespace std;
template <class T>  

class Simple
{
private:
    int index = 0;
    T after;
public:
    Simple();
    Simple(int index, T after);
    ~Simple();
    void setIndex(int index);
    void setAfter(T after);
    int getIndex();
    T getAfter();
};

template <class T>
Simple<T>::Simple() {

}

template <class T>
Simple<T>::Simple(int index, T after) {
    index = this->index;
    after = this->after;
}

template <class T>
Simple<T>::~Simple()
{
}

template <class T>
void Simple<T>::setIndex(int index)
{
    index = this->index;
}

template <class T>
void Simple<T>::setAfter(T after)
{
    after = this->after;
}

template <class T>
int Simple<T>::getIndex()
{
    return index;
}

template <class T>
T Simple<T>::getAfter()
{
    return after;
}
