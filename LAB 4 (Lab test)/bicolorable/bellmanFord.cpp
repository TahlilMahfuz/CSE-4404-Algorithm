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


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};


int main() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(3));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,c};
    }
    for(auto e:edges){
        cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
    }

    int s=0;
    Solution obj;
    vector<int> dist=obj.bellman_ford(n,edges,s);
    cout<<endl;
    // cout<<dist.size()<<endl;
    for(auto e:dist){
        cout<<e<<" ";
    }

	// int V = 6;
	// vector<vector<int>> edges(7, vector<int>(3));
	// edges[0] = {3, 2, 6};
	// edges[1] = {5, 3, 1};
	// edges[2] = {0, 1, 5};
	// edges[3] = {1, 5, -3};
	// edges[4] = {1, 2, -2};
	// edges[5] = {3, 4, -2};
	// edges[6] = {2, 4, 3};

	// int S = 0;
	// Solution obj;
	// vector<int> dist = obj.bellman_ford(V, edges, S);
	// for (auto d : dist) {
	// 	cout << d << " ";
	// }
	// cout << endl;

	return 0;
}