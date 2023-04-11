#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.rbegin(),v.rend()

using namespace std;

void dfs(int s, vector<vector<int>>&v, vector<bool>&vis){
    vector<int>connIndex;
    vis[s]=true;
    for(int i=0;i<v.size();i++){
        if(v[s][i]==1){
            connIndex.push_back(i);
        }
    }
    for(auto e:connIndex){
        if(!vis[e]){
            dfs(e,v,vis);
        }
    }
}

signed main(){
    int n;cin>>n;
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    vector<bool>vis(n,false);
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i,v,vis);
        }
    }
    cout<<count<<endl;


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}