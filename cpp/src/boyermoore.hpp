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
#include<vector>
#include<string>
#ifndef BOYERMOORE_H
#define BOYERMOORE_H

namespace RS{
    class BoyerMoore{
    private:
        int _R;
        typedef std::vector<int> VI;
        VI _right;
        typedef std::string string;
        string _pattern;
    public:
        BoyerMoore(string pattern, int R = 256):_R(R),_pattern(pattern){
            _right.resize(R);
            for(VI::iterator i = _right.begin(); i < _right.end(); i++){
                *i = -1;
            }
            for(unsigned int j = 0; j < _pattern.size(); j++){
                _right[(int)(pattern[j])] = j;
            }
        }
        int search(string text){
            int M = _pattern.length();
            int N = text.length();
            int skip;
            for(int i = 0; i <= N - M; i+=skip){
                skip = 0;
                for(int j = M - 1; j >= 0; j--){
                    if(_pattern[j] != text[i+j]){
                        skip = std::max(1,j - _right[(int)(text[i+j])]);
                    }
                }
                if(skip == 0) return i;
            }
            return -1;
        }

    };

}


#endif // BOYERMOORE_H
