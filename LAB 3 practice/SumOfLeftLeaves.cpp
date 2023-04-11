#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef long long int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.rbegin(),v.rend()

using namespace std;
vector<int>ans;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        val=0;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x,TreeNode *left,TreeNode *right){
        val=x;
        left=left;
        right=right;
    }
};
 

void dfs(TreeNode * root){
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
    return accumulate(all(ans),0);
}

signed main(){
    fio;
    
    

    return 0;
}