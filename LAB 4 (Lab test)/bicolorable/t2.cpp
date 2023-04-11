#include <bits/stdc++.h>
using namespace std;

const int N=4, M=5;
int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

bool valid(int x, int y, int n, int m) {
    return x>=0&&x<n&&y>=0&&y<m;
}

vector<int> dijkstra(int V, vector<vector<int>> adj, int S)
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
            int v = it[0];
            int w = it[1];
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
}

int main() {
    int n=N, m=M;
    int g[N][M]={{0, 3, 1, 2, 9},
                 {7, 3, 4, 9, 9},
                 {1, 7, 5, 5, 3},
                 {2, 3, 4, 2, 5}};

    vector<vector<int>> adj(n*m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                int x=i+dx[k], y=j+dy[k];
                if(valid(x, y, n, m)) {
                    adj[i*m+j].push_back(x*m+y);
                }
            }
        }
    }

    vector<int>res=dijkstra(n,adj,0);
    for(auto e:res){
        cout<<e<<endl;
    }


    return 0;
}