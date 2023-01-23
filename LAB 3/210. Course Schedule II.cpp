#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n,0);
        vector<int>ans;
        map<int,vector<int>>mp;
        for(auto e:pre){
            mp[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        // for(auto e:mp){
        //     cout<<e.first<<"=>";
        //     for(auto x:e.second){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(auto e:indegree){
        //     cout<<e<<" ";
        // }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto e:mp[x]){
                indegree[e]--;
                if(indegree[e]==0){
                    q.push(e);
                }
            }
        }
        // for(auto e:ans){
        //     cout<<e<<" ";
        // }
        // cout<<endl;
        if(ans.size()==n){
            for(auto e:ans){
                cout<<e<<" ";
            }
            cout<<endl;
            return ans;
        }
        else{
            ans.clear();
            for(auto e:ans){
                cout<<e<<" ";
            }
            cout<<endl;
            return ans;
        }
    }
};

signed main(){
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    Solution sol;
    sol.findOrder(n,v);
}