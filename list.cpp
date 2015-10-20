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

class List;
class ListNode;

class List {
public:
    ListNode* head;
    List(int v = 0);
    List(vector<int> v);
    void print();
};

class ListNode {
public:
    ListNode* next;
    int val;
    ListNode(int v = 0);
};

List::List(int v) {
    head = new ListNode(v);
}

List::List(vector<int> v) {
    int n = v.size();
    if(n == 0) {
        cout<<"Empty vector"<<endl;
        return;
    }
    if(n == 1) {
        head = new ListNode(v[0]);
        return;
    }
    vector<ListNode*> l(n, NULL);
    for(int i = 0; i < n; i++) {
        l[i] = new ListNode();
        l[i]->val = v[i];
    }
    for(int i = 0; i < n - 1; i++) {
        l[i]->next = l[i + 1];
    }
    head = l[0];
    return;
}

void List::print() {
    ListNode* node = head;
    while(node) {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
}

ListNode::ListNode(int v) {
    val = v;
    next = NULL;
}

void printv(vector<int> vec) {
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        cout<<vec[i]<<" ";
    } 
    cout<<endl;
}

void ListNodeTest() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    List l(v);
    l.print();
}

int main() {
    ListNodeTest();

    int wait = 0;
    cin>>wait;

    return 0; 
}
