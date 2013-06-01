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
#include<string>
#include<stdexcept>
#ifndef RABINKARP_H
#define RABINKARP_H
namespace CLRS {


class RabinKarp{
    int _d; //radix (cardinality of the alphabet set). Here we assume only ascii characters. So, initialising it to 256.
    int _h; //(pow (_d, length(pattern) - 1) % _q) used to calculate the next rolling hash.
    int _q; //some prime number.
    typedef std::string string; //shortcuts
    typedef string::iterator iterator; //shortcuts
    string _text; //The text
    string _pattern;//The pattern
    int _t;
    int _p;
    int calcH(){
        for(iterator i = _pattern.begin();i <_pattern.end()-1;i++)
            _h = (_h * _d) % _q;
        return _h;
    }
    void firstHash() throw(){
        int tl = _text.length();
        int pl = _pattern.length();

        if(tl < pl)
            throw std::out_of_range("Text is smaller than the pattern");
        for(iterator i = _pattern.begin(), j = _text.begin(); i != _pattern.end(); i++, j++){
            _p = (_d*_p + int(*i))%_q;
            _t = (_d*_t + int(*j))%_q;
        }
    }

public:
    RabinKarp(string text = "",string pattern = "",int d = 256,int q = 101)
        :_d(d),_h(1),_q(q),_text(text),_pattern(pattern),_t(0),_p(0){
        calcH();
        firstHash();

    }
    int getH(){
        return _h;
    }
    int getP(){
        return _p;
    }
    int getT(){
        return _t;
    }

    string getPattern(){
        return _pattern;
    }
    string getText(){
        return _text;
    }

    int search(){
        int pat_l = _pattern.length();
        for(iterator i = _text.begin();i <= _text.end() - pat_l; i++){
            if (_p == _t){
                iterator k = _pattern.begin();
                for(iterator j = i; k< _pattern.end(); k++,j++){
                    if(*j!=*k)
                        break;
                }
                if((k-_pattern.end()) == 0){
                    return (i - _text.begin());
                }
            }
            _t = (_d*(_t - int(*i)*_h) + int(*(i+pat_l))) % _q;
            if(_t < 0){
                _t += _q;
            }
        }
        return -1;
    }

};
}

#endif // RABINKARP_H
