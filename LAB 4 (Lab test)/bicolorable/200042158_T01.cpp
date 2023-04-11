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


vector<bool>visited(100,false);
void DFS(int u,vector<bool> &visited,vector<int> adj[])
{
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if (visited[v]==false)
        {
            visited[v] = true;
            DFS(v, visited, adj);
        }
    }
      
}

int unreachablenodescount(vector<int>adj[],int nodes,int start)
{
    int count=0;
    for (int i =1; i<nodes;i++)
    {
        visited[i]=false;
    }
    DFS(start, visited, adj);
    for (int u = 1; u <= nodes; u++) {
        if (visited[u] == false) {
            count+=1;
        }
    }
    return count;
}

signed main(){

    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    int t;
    cin>>t;
    int s;
    for (int i=0;i<t;i++)
    {
        cin>>s;
        int count=unreachablenodescount(adj,n,s);
        cout << count<< " ";
        for (int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }

    return 0;   
}


