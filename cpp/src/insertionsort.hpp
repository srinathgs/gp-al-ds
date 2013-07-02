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
#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP
#include "sort.hpp"
#include <vector>
namespace RS {
template<class T>
class InsertionSort:public Sort<T>{
private:
    typedef Sort<T> _parent;
    typedef std::vector<T> VT;
public:
    InsertionSort(){_parent();}
    void sort(VT &a){
        int N = a.size();
        for(int i = 0; i < N; i++){
            for(int j = i; j > 0 && less(a[j],a[j-1]); j--){
                swap(a[j],a[j-1]);
            }
        }
    }
};

}
#endif // INSERTIONSORT_HPP
