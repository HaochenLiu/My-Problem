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

class Tree;
class TreeNode;

class Tree {
public:
    TreeNode* root;
    Tree(int v = 0);
    Tree(TreeNode* node = NULL);    
    vector<vector<int>> verTraversal();
};

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v = 0);
};

Tree::Tree(int v) {
    root = new TreeNode(v);
}

Tree::Tree(TreeNode* node) {
    root = node;
}

vector<vector<int>> Tree::verTraversal() {
    vector<vector<int>> res;
    if(root == NULL) return res;
    unordered_map<TreeNode*, int> idxm;
    idxm[root] = 0;
    unordered_map<int, vector<int>> m;
    int minVal = 0;
    int maxVal = 0;
    queue<TreeNode*> cur; 
    queue<TreeNode*> next;
    cur.push(root);

    while(!cur.empty()) {
        while(!cur.empty()) {
            TreeNode* node = cur.front();
            cur.pop();
            int idx = idxm[node];
            m[idx].push_back(node->val);
            if(node->left) {
                idxm[node->left] = idx - 1;
                minVal = min(minVal, idx - 1);
                next.push(node->left);
            }
            if(node->right) {
                idxm[node->right] = idx + 1;
                maxVal = max(maxVal, idx + 1);
                next.push(node->right);
            }
        }
        swap(cur, next);
    }
        
    for(int i = minVal; i <= maxVal; i++) {
        res.push_back(m[i]);
    }

    return res;
}

TreeNode::TreeNode(int v) {
    val = v;
    left = NULL;
    right = NULL;
}

void printvv(vector<vector<int>> vec) {
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        int sz = vec[i].size();
        for(int j = 0; j < sz; j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    } 
}

void printv(vector<int> vec) {
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        cout<<vec[i]<<" ";
    } 
    cout<<endl;
}

void verTraversalTest() {
    Tree* t = new Tree(1);
    TreeNode* node1 = t->root;
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node2->left = node4;
    node2->right = node5;

    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node3->left = node6;
    node3->right = node7;

    TreeNode* node8 = new TreeNode(8);
    node6->right = node8;

    TreeNode* node9 = new TreeNode(9);
    node7->right = node9;

    TreeNode* node10 = new TreeNode(10);
    node5->right = node10;

    TreeNode* node11 = new TreeNode(11);
    node10->right = node11;
    
    printvv(t->verTraversal());
}

int main() {
    verTraversalTest();

    int wait = 0;
    cin>>wait;

    return 0; 
}
