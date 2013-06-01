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
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
using namespace std;

template< typename comparable> void insertionSort(vector<comparable> &a);
template< typename comparable> void shellSort(vector<comparable> &a);
template <typename comparable> void mergeSort(vector<comparable> &a);
template <typename comparable> void mergeSort(vector<comparable> &a,
                               vector<comparable> &tmpArray,
                               int left,
                               int right);
template <typename comparable> void myMerge(vector<comparable> &a,
                                            vector<comparable> &tmpArray,
                                            int leftPos,
                                            int rightPos,
                                            int rightEnd);
template<typename comparable> void quickSort(vector<comparable> &a);
template<typename comparable> void quickSort(vector<comparable> &a, int low,int high);
template<typename comparable> int partition(vector<comparable> &a,int low, int high);
int main()
{
    vector<int> array;

    for(int i = 0;i<10;i++){
        array.push_back(i%3==0?i:i+13);
    }
    cout<<"Before:\n";
    copy(array.begin(),array.end(),ostream_iterator<int>(cout,"\n"));
    shellSort(array);
    cout<<"After:\n";
    copy(array.begin(),array.end(),ostream_iterator<int>(cout,"\n"));
    return 0;
}

template< typename comparable> void insertionSort(vector<comparable> &a){
    for(unsigned int p = 1;p<a.size();p++){

        comparable temp = a[p];

        unsigned int q;
        for(q = p;q>0 && temp < a[q-1];q--){
            a[q] = a[q-1];
        }
        a[q] = temp;
        //cout<<" 1."<<endl;
        //copy(a.begin(),a.end(),ostream_iterator<int>(cout,"\n"));
    }
}

template<typename comparable> void shellSort(vector<comparable> &a){
    unsigned int i,gap,j;
    for(gap = a.size()/2;gap>0;gap = (gap==2?1:gap/=2.2)){
        for(i = gap;i<a.size();i++){
            comparable temp = a[i];
            j = i;
            for(;j>=gap && temp<a[j-gap];j-=gap)
                a[j] = a[j-gap];
            a[j] = temp;
        }
        cout<<" 1."<<endl;
        copy(a.begin(),a.end(),ostream_iterator<int>(cout,"\n"));
    }
}

template<typename comparable> void mergeSort(vector<comparable>&a){
    vector<comparable> tmpArray(a.size());
    mergeSort(a,tmpArray, 0,a.size()-1);
}

template<typename comparable> void mergeSort(vector<comparable>&a,
                                             vector<comparable>&tmpArray,
                                             int left,
                                             int right){

    if(left<right){
        int center = (left + right)/2;
        mergeSort(a,tmpArray,left,center);
        mergeSort(a,tmpArray,center+1,right);
        myMerge(a,tmpArray,left,center+1,right);
    }
}

template<typename comparable> void myMerge(vector<comparable> &a,
                                           vector<comparable> &tmpArray,
                                           int leftPos,
                                           int rightPos,
                                           int rightEnd){
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElems = rightEnd - leftPos + 1;
    while(leftPos<=leftEnd && rightPos <=rightEnd){
        if(a[leftPos]<=a[rightPos])
            tmpArray[tmpPos++] = a[leftPos++];
        else
            tmpArray[tmpPos++] = a[rightPos++];
    }
    while(leftPos<=leftEnd){
        tmpArray[tmpPos++] = a[leftPos++];
    }
    while(rightPos<=rightEnd){
        tmpArray[tmpPos++] = a[rightPos++];
    }

    for(int i=0;i<numElems;i++,rightEnd--){
        a[rightEnd] = tmpArray[rightEnd];
    }
}

template<typename comparable> void quickSort(vector<comparable>&a){
    quickSort(a,0,a.size()-1);
}

template<typename comparable> void quickSort(vector<comparable>&a, int low, int high){
    if(low<high){
        int part = partition(a,low,high);
        quickSort(a,low,part-1);
        quickSort(a,part+1,high);
    }
}
template<typename comparable> int partition(vector<comparable> &a,int low, int high){
    int pivot = a[high];
    int i = low-1;
    for(int j = low;j<high;j++){
        if(a[j]<pivot){
            ++i;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
