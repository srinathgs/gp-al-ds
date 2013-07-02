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
#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP
#include "sort.hpp"
#include <vector>
namespace RS{
template<class T>
class SelectionSort:public Sort<T>{
private:
    typedef std::vector<T> VT;
    typedef Sort<T> _parent;
public:
    void sort(VT &a){
        int N = a.size();
        for(unsigned int i = 0; i < N; i++){
            int min = i;
            for(unsigned int j = i + 1; j < N; j++){
                if(less(a[j],a[min]) > 0) {
                    min = j;
                }
            }
            swap(a[i],a[min]);
        }
    }
};
}

#endif // SELECTIONSORT_HPP
