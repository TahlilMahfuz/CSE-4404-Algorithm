// Add some code
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

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            // cout<<"Node : "<<node<<endl<<"dis : "<<dis<<endl;

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                // cout<<v<<" "<<w<<endl;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
    }
};

int main()
{
    int t;
    while(t--){
        int v,edge,s=0,ans;
        cin>>v>>edge;
        vector<vector<int>>adj[v];
        for(int i=0;i<edge;i++){
            int a,b,c;
            cin>>a>>b>>c;
            vector<int>v;
            v.push_back(b);v.push_back(c);
            adj[a].push_back(v);
            vector<int>v1;
            v1.push_back(a);v1.push_back(c);
            adj[b].push_back(v1);
        }
        cin>>ans;

        Solution obj;
        vector<int> res=obj.dijkstra(v,adj,ans);
        for(auto e:res){
            cout<<e<<endl;
        }
    }

    return 0;
}