#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if (!root)return ans;
        vector<int>temp;
        vector<Node*> pre, each,cur;
        pre.push_back(root);
        while (pre.size()>0) {
            for (auto i : pre) {
                temp.push_back(i->val);
                if(i->children.size())
                    each = i->children;
                for (auto j : each)                    
                        cur.push_back(j);
            }
            pre = cur;
            cur.clear();
            //each.clear();
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
int main() {
    return 0;
}