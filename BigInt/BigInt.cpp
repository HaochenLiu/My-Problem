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

using namespace std;

class BigInt;

class BigInt {
private:
    string str;
    
public:
    BigInt(string s = "0");
    BigInt add(BigInt badd);
    string toString();
};

BigInt::BigInt(string s) {
    str = s;
}
    
BigInt BigInt::add(BigInt badd) {
    string additive = badd.toString();
    if(additive == "0") {
        BigInt sum(str);
        return sum;
    }
    if(str == "0") {
        BigInt sum(additive);
        return sum;
    }
    int n = str.size();
    int m = additive.size();
    string sum(max(n, m) + 1, '0');
    int sz = sum.size();
    int carry = 0;
    for(int i = 0; i < sz; i++) {
        int part1 = 0;
        if(i < n) {
            part1 = str[n - 1 - i] - '0';
        } 
            
        int part2 = 0;
        if(i < m) {
            part2 = additive[m - 1 - i] - '0';
        } 
            
        sum[sz - 1 - i] = (part1 + part2 + carry) % 10 + '0';
        carry = (part1 + part2 + carry) / 10;
    }
        
    while(sum.size() > 1 && sum[0] == '0') {
        sum.erase(sum.begin());
    }
        
    BigInt bsum(sum);

    return bsum;
}
    
string BigInt::toString() {
    return str;
}

void BigIntTest() {
    BigInt a("00099999");
    BigInt b("99999");
    BigInt c = a.add(b);

    cout<<a.toString()<<endl;
    cout<<b.toString()<<endl;
    cout<<c.toString()<<endl;
}

int main() {
    BigIntTest();

    int wait = 0;
    cin>>wait;

    return 0; 
}
