/*The MIT License (MIT)

Copyright (c) 2013 Srinath G.S.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include "sort.hpp"
#include<vector>

namespace RS{
template<class T>
class QuickSort:public Sort<T>{
private:
    typedef Sort<T> _parent;
    typedef std::vector<T> VT;
    unsigned int partition(VT &a, int low,int high){
        T piv = a[low];
        int i = low;
        int j = high + 1;
        while(1){
            while(less(a[i++],piv) > 0)
                if(i == high) break;
            while(less(piv,a[j--]) > 0)
                if( j == low) break;
            if(i >= j) break;
            swap(a[i],a[j]);
        }
        swap(a[low],a[j]);
        return j;

    }
    void sort(VT &a,int low,int high){
        if(low < high){
        int part = partition(a,low,high);
        sort(a,low,part-1);
        sort(a,part+1, high);
        }
    }

public:
    void sort(VT &a){
        sort(a, 0, a.size()-1);
    }
};
}
#endif // QUICKSORT_HPP
