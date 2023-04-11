#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define testvec(v) for(auto e:v){for(auto x:e){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()



vector<vector<int>>adj;
vector<bool>vis;
vector<int>col;
bool bipartite;

void color(int u,int currcolor){//dfs
    if(col[u]!=-1 && col[u]!=currcolor){
        bipartite=false;
        return;
    }
    col[u]=currcolor;
    if(vis[u])return;
    vis[u]=true;
    for(auto e:adj[u]){
        color(e,currcolor^1);   
    }
}

signed main(){
    fio;
    bipartite=true;
    int n,m;cin>>n>>m;
    adj= vector<vector<int>>(n);
    vis= vector<bool>(n,false);
    col=vector<int>(n,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            color(i,0);
        }
    }
    if(bipartite){
        cout<<"Bicolorable"<<endl;
    }
    else    
        cout<<"NotBicolorable"<<endl;

    return 0;
}













