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
#include<iostream>
#ifndef LLIST_H
#define LLIST_H
namespace CLRS{
template<class T>
class LList
{

public:
    class LNode
    {

    public:
        T _data;
        LNode* _next;
        LNode():_data(0),_next(0){}
        LNode(T data):_data(data),_next(0){}
        ~LNode(){

            delete _next;
            //std::cout<< _data<<std::endl;
        }
    };

    LNode* _head;

    LList():_head(0){}

    int insert(T data){
        int i = 0;
        if(_head == 0){
            _head = new LNode(data);
            return i;
        }
        else{
            LNode* curr = _head;
            //std::cout<<"in else"<<std::endl;
            while(curr->_next != 0){
                curr = curr->_next;
            }
            curr->_next = new LNode(data);
        }
        return i;
    }
    void revList(LNode* &head){
        if(!head) return;
        LNode* other = head->_next;
        if(!other) return;
        revList(other);
        head->_next->_next = head;
        head->_next = 0;
        head = other;
    }
    void reverse(){
        revList(_head);
    }

    void print(){
        LNode* curr = _head;
        while(curr!=0){
            std::cout<<curr->_data<<std::endl;
            curr = curr->_next;
        }
    }

    void del(T val){
        LNode* curr = _head;
        if(curr == 0){
            return;
        }
        if(curr->_next == 0){
            if(curr->_data == val){
                delete curr;
                return;
            }
            return;
        }
        while(curr->_next != 0){
            if(curr->_next->_data == val){
                LNode* temp = curr->_next;
                curr->_next = curr->_next->_next;
                temp->_next = 0;
                delete temp;
            }
            curr = curr->_next;
        }
    }

    ~LList(){
        delete _head;
    }
};
}
#endif // LLIST_H
