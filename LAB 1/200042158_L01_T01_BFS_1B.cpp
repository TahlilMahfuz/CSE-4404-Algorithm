#include<bits/stdc++.h>

using namespace std;

void bfs(int s,vector<vector<int>>&v,vector<int>vis){
    vis[s]=true;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto e:v[top]){
            if(!vis[e]){
                vis[e]=true;
                q.push(e);
            }
        }
    }
}
 
signed main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    int count=0;
    vector<int>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i,v,vis);
            count++;
        }
    }
    cout<<count<<endl;

    // for(int i=0;i<n;i++){
    //     for(auto e:v[i]){
    //         cout<<e<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}