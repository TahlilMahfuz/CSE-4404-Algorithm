#include<bits/stdc++.h>

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
        if(root==nullptr){return ans;}
        queue<Node*>q;
        vector<int>level; 
        q.push(root);
        while(!q.empty()){
            level.clear();
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* node=q.front();   
                q.pop();
                level.push_back(node->val);
                for(auto e:node->children){
                    q.push(e);
                }
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};