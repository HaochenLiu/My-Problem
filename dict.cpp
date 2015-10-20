#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class dict;

class dict {
private:
    unordered_set<string> words;

public:
    dict(vector<string> v) {
        int n = v.size();
        for(int i = 0; i < n; i++) {
            words.insert(v[i]);
        }
    }
  
    bool Exists(string str) {
        return (words.find(str) != words.end());
    }
  
    bool isCompound(string str) {
        if(str.empty()) return false;
        return isCompoundRecur(str, 0);
    }

    bool isCompoundRecur(string str, int start) {
        int n = str.size();
        if(start == n) return true;
        for(int i = start; i < n; i++) {
            string t = str.substr(start, i - start + 1);
            if(words.find(t) != words.end()) {
                if(isCompoundRecur(str, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
  
    /*
    once
    */
    bool isCompound2(string str) {
        if(str.empty()) return false;
        unordered_set<string> used;
        return isCompoundRecur2(str, 0, used);
    }
  
    bool isCompoundRecur2(string str, int start, unordered_set<string>& s) {
        int n = str.size();
        if(start == n) return true;
        for(int i = start; i < n; i++) {
            string t = str.substr(start, i - start + 1);
            if(words.find(t) != words.end() && s.find(t) == s.end()) {
                s.insert(t);
                if(isCompoundRecur2(str, i + 1, s)) {
                    return true;
                }
                s.erase(t);
            }
        }
        return false;
    }  
};

int main() {
    vector<string> v;
    v.push_back("abc");
    v.push_back("def");
    dict d(v);
    if(d.Exists("abc")) {
        cout<<"find abc"<<endl;
    }
    if(d.Exists("def")) {
        cout<<"find def"<<endl;
    }
    if(d.Exists("ab")) {
        cout<<"find ab"<<endl;
    }

    if(d.isCompound("abcdef")) {
        cout<<"isCompound abcdef"<<endl;
    } else {
        cout<<"is not Compound abcdef"<<endl;
    }

    if(d.isCompound("defabc")) {
        cout<<"isCompound defabc"<<endl;
    } else {
        cout<<"is not Compound defabc"<<endl;
    }

    if(d.isCompound("abc")) {
        cout<<"isCompound abc"<<endl;
    } else {
        cout<<"is not Compound abc"<<endl;
    }

    if(d.isCompound("abcabc")) {
        cout<<"isCompound abcabc"<<endl;
    } else {
        cout<<"is not Compound abcabc"<<endl;
    }

    if(d.isCompound("abcabf")) {
        cout<<"isCompound abcabf"<<endl;
    } else {
        cout<<"is not Compound abcabf"<<endl;
    }
  
    if(d.isCompound2("abcdef")) {
        cout<<"isCompound abcdef"<<endl;
    } else {
        cout<<"is not Compound abcdef"<<endl;
    }

    if(d.isCompound2("defabc")) {
        cout<<"isCompound defabc"<<endl;
    } else {
        cout<<"is not Compound defabc"<<endl;
    }

    if(d.isCompound2("abc")) {
        cout<<"isCompound abc"<<endl;
    } else {
        cout<<"is not Compound abc"<<endl;
    }

    if(d.isCompound2("abcabc")) {
        cout<<"isCompound abcabc"<<endl;
    } else {
        cout<<"is not Compound abcabc"<<endl;
    }

    if(d.isCompound2("abcabf")) {
        cout<<"isCompound abcabf"<<endl;
    } else {
        cout<<"is not Compound abcabf"<<endl;
    }

    return 0;
}
