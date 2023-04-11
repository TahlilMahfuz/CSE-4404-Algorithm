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
        if(!root){return {};}
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* node = q.front();
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
