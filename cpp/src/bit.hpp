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
#ifndef BIT_HPP
#define BIT_HPP
#include<vector>
template<class T>
struct BITNode{
    T freq;
    T cuf;
    BITNode(){
        freq = 0;
        cuf = 0;
    }
};
template<class T>
class BIT{
private:
    typedef std::vector<BITNode<T> > VN;
    void _setElem(int idx,T freq,T cuf){
        elems[idx - 1].freq = freq;
        elems[idx - 1].cuf = cuf;
    }

    BITNode<T> _getElem(unsigned int idx){
        return elems[idx - 1];
    }

    void _propUp(int idx, T change){
        if(change == 0){
            return;
        }

        while(idx <= size){
            BITNode<T> old = _getElem(idx);
            _setElem(idx,old.freq,old.cuf + change);
            idx += (idx & -idx);
        }
    }
public:
    VN elems;
    int size;
    BIT(int size = 0){
        elems.resize(size);
        for(int i = 0; i < size; i++){
            elems[i].freq = 0;
            elems[i].cuf = 0;
        }
         this->size = size;
    }



    void calc(int idx, T val){
        T cuf = val;
        int targetIdx = idx - (idx & -idx);
        int i = idx - 1;
        while(i > targetIdx){
            cuf += _getElem(i).cuf;
            i -= (i & -i);
        }
        _setElem(idx,val,cuf);
    }



    void update(int idx, T val){
        if(idx > size){
            for(int i = size; i < idx; i++){
                BITNode<T> tmp;
                elems.push_back(tmp);
            }
            for(int i = size + 1; i < idx + 1; i++){
                calc(i,0);
            }
            size = idx;
        }
        BITNode<T> old = _getElem(idx);
        T change = val - old.freq;
        _setElem(idx,val,old.cuf);
        _propUp(idx,change);
    }
    T sum(int idx){
        T sum = 0;
        while(idx > 0){
            sum += _getElem(idx).cuf;
            idx -= (idx & -idx);
        }
        return sum;
    }

    void display(){
        for(int i = 0; i < size;i++){
            std::cout << i+1 <<": ("<<elems[i].freq<<", "<<elems[i].cuf<<"): "<<sum(i+1)<<std::endl;
        }
    }
};

#endif // BIT_HPP
