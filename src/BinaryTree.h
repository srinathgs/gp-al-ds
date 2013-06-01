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
#ifndef BINARYTREE_H
#define BINARYTREE_H
//hDel Method is based on Algorithms in Java by Robert Sedgewick
namespace RS{
template <class Key>
class TNode{
public:
    Key _key;
    TNode* _left;
    TNode* _right;
    TNode():_left(0),_right(0){}
    TNode(Key key):_key(key),_left(0),_right(0){}
    ~TNode(){
        delete _left;
        delete _right;
    }
};
template<class Key>
class BinaryTree{
protected:
    TNode<Key>* _root;
    void putHelper(TNode<Key>*& rt,Key key){
        if(rt == 0){
            rt = new TNode<Key>(key);
        }
        else if(rt->_key > key){
            putHelper(rt->_left,key);
        }
        else if (rt->_key < key){
            putHelper(rt->_right,key);
        }
        else{
            return;
        }
    }
    TNode<Key>* searchHelper(TNode<Key>*&rt,Key k){
        if(rt==0){
            return NULL;
        }
        else if(rt->_key < k){
            return searchHelper(rt->_right,k);
        }
        else if(rt->_key > k){
            return searchHelper(rt->_left,k);
        }
        return rt;
    }
    void delLeftNull(TNode<Key>* parent, TNode<Key>* node){

            if(parent->_key > node->_key){
                parent->_left = node->_right;
            }
            else{
                parent->_right = node->_right;
            }
            node->_right = 0;
            delete node;
    }
    void delRightNull(TNode<Key>* parent, TNode<Key>* node){

            if(parent->_key > node->_key){
                parent->_left = node->_left;
            }
            else{
                parent->_right = node->_left;
            }
            node->_left = 0;
            delete node;
    }
    //delete procedure written after analyzing all the cases.
    //the recursive implementation is more simple and readable. Check hDel method for more details.
    void delHelper(TNode<Key>* &rt, Key val){

        TNode<Key>* parent = getParent(rt,val);
        TNode<Key>* node = searchHelper(rt,val);
        if(parent!=0){
            if(node->_left == 0 && node->_right == 0){
                if(parent->_key > node->_key){
                    parent->_left = 0;
                }
                else if(parent->_key < node ->_key){
                    parent->_right = 0;
                }
                delete node;
            }
            else if(node->_left == 0){
                delLeftNull(parent,node);
            }
            else if(node->_right == 0){
                delRightNull(parent, node);
            }
            else{
                TNode<Key>* minNode = getMinHelper(node->_right);
                node->_key = minNode->_key;
                delHelper(node->_right,minNode->_key);
            }
        }
        else{
            if(node!=0){//Deleting the Root Node.
                if(node->_left == 0 && node->_right == 0){
                    delete node;
                }
                else if(node->_left == 0){
                    TNode<Key>* tmp = node->_right;
                    node->_right = 0;
                    delete node;
                    rt = tmp;
                }
                else if(node->_right == 0){
                    TNode<Key>* tmp = node->_left;
                    node->_left = 0;
                    delete node;
                    rt = tmp;
                }
                else{
                    TNode<Key>* minNode = getMinHelper(node->_right);
                    node->_key = minNode->_key;
                    delHelper(node->_right,minNode->_key);
                }

            }
        }
    }

    TNode<Key>* getParent(TNode<Key>* node,Key val){
        //std::cout << "getParHelper" <<std::endl;
        if(node == 0){
            return 0;
        }
        //std::cout << node->_key <<std::endl;
        if(node->_right && (node->_key < val)){
            if(node->_right->_key < val)
                return getParent(node->_right->_right,val);
            else if(node->_right->_key > val){
                return getParent(node->_right->_left,val);
            }
            return node;
        }
        else if (node->_left && (node->_key > val)){
            if(node->_left->_key < val)
                return getParent(node->_left->_right,val);
            else if(node->_left->_key > val){
                return getParent(node->_left->_left,val);
            }
            return node;
        }
        return 0;
    }

    TNode<Key>* getMinHelper(TNode<Key>* node){
        if(node->_left)
        {
            return getMinHelper(node->_left);
        }
        return node;
    }

    TNode<Key>* getMaxHelper(TNode<Key>* node){
        if(node->_right)
        {
            return getMaxHelper(node->_right);
        }
        return node;
    }
    void inOrderHelper(TNode<Key>* node){
        if(!node){
            return;
        }
        inOrderHelper(node->_left);
        std::cout << node->_key << " ";
        inOrderHelper(node->_right);

    }

    TNode<Key>* hDel(TNode<Key>* node, Key val){
        if(node == 0) return 0;
        if(node->_key > val) node->_left = hDel(node->_left,val);
        else if(node->_key < val) node->_right = hDel(node->_right,val);
        else{
            if(node->_left != 0 && node->_right!=0){
            node->_key = getMinHelper(node->_right)->_key;
            deleteMin(node->_right);
            }
            else if(node->_left == 0) {
                TNode<Key>* x = node->_right;
                node->_right = 0;
                delete node;
                return x;
            }
            else if(node->_right == 0){
                TNode<Key>* x = node->_left;
                node->_left = 0;
                delete node;
                return x;
            }

        }
        return node;
    }

    void deleteMin(TNode<Key>*& node){
        if(node == 0){
            return;
        }
        else if(node->_left !=0){

        deleteMin(node->_left);
        }
        else{
            TNode<Key>* tmp = node;
            node = node->_right;
            tmp->_right = 0;
            delete tmp;
        }

    }
    void inOrderMorris(TNode<Key>* rt){
        TNode<Key>* curr = rt;
        while(curr != 0){
            if(curr->_left == 0){
                std::cout<<curr->_key<<" ";
                curr = curr->_right;
            }
            else{
                TNode<Key>* rMost = curr->_left;
                while(rMost->_right != 0 && rMost->_right != curr)
                    rMost = rMost->_right;
                if(rMost->_right == 0){
                    rMost->_right = curr;
                    curr = curr->_left;
                }
                else{
                    rMost->_right = 0;
                    std::cout<<curr->_key<<" ";
                    curr = curr->_right;
                }
            }
        }
    }

public:
    BinaryTree():_root(0){}
    ~BinaryTree(){
        delete _root;
    }
    void put(Key key){
        putHelper(_root,key);
    }
    TNode<Key>* search(Key k){
        return searchHelper(_root,k);
    }


    TNode<Key>* operator[](Key k){
        return search(k);
    }
    void del(Key val){
        //delHelper(_root,val);
        _root = hDel(_root,val);
    }
    TNode<Key>* getMin(){
        return getMinHelper(_root);
    }
    TNode<Key>* getMax(){
        return getMaxHelper(_root);
    }

    void inOrder(){
        inOrderHelper(_root);
    }
    void inOrderNoStack(){
        inOrderMorris(_root);
    }
};
}
#endif // BINARYTREE_H
