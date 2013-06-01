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
