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
#define input_adj_mat() for(auto &e:matrix){for(auto &x:e){cin>>x;}cout<<endl;}cout<<endl;
#define all(v) v.begin(),v.end()

int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

bool valid(int x, int y, int n, int m) {
    return x>=0&&x<n&&y>=0&&y<m;
}

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> adj, int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);
    distTo[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
}


signed main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> maze(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }

    int V = n*m;
    vector<vector<pair<int, int>>> adj(V);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u = i*m+j;
            for(int k=0;k<4;k++){
                int x = i+dx[k], y = j+dy[k];
                if(valid(x, y, n, m)){
                    int v = x*m+y;
                    int w = maze[x][y];
                    adj[u].push_back({v, w});
                }
            }
        }
    }

    vector<int> dist = dijkstra(V, adj, 0);
    cout<<dist[V-1]<<endl;

    return 0;
}
