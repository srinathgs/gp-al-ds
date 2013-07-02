#ifndef SORT_HPP
#define SORT_HPP

//base class for all sorting algos
//sort member function is not defined here. It is defined in specific implementations
namespace RS{
template<class T>
class Sort{
protected:
    virtual int less(T a, T b){
        if(a == b){
            return 0;
        }
        else if(a < b){
            return 1;
        }
            return -1;
    }
    virtual void swap(T& a, T& b){
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

public:
    Sort(){}
};
}
#endif // SORT_HPP
