#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<int>ans;
    void dfs(TreeNode* root){
        if(root){
            if(root->left){
                if(root->left->left==nullptr && root->left->right==nullptr){
                    ans.push_back(root->left->val);
                }   
                dfs(root->left);
            }
            if(root->right){
                dfs(root->right);
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return accumulate(ans.begin(),ans.end(),0);
    }
};