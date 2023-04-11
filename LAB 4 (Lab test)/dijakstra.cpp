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


// Complexity O(elog(v));


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
    int v,edge,s=0;
    cin>>v>>edge;
    vector<vector<int>>adj[v];
    for(int i=0;i<edge;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        vector<int>v;
        v.push_back(b);v.push_back(c);
        adj[a].push_back(v);
        vector<int>v1;
        v1.push_back(a);v1.push_back(c);
        adj[b].push_back(v1);
    }



    // Driver code.
    // int v = 3, e = 3, s = 2;
    // vector<vector<int>> adj[v];
    // vector<vector<int>> edges;
    // vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    // int i = 0;
    // adj[0].push_back(v1);
    // adj[0].push_back(v2);
    // adj[1].push_back(v3);
    // adj[1].push_back(v4);
    // adj[2].push_back(v5);
    // adj[2].push_back(v6);

    // for(auto e:adj[1]){
    //     {
    //         cout<<e[0]<<" "<<e[1]<<endl;
    //         cout<<endl;
    //     }
    // }

    for(int i=0;i<v;i++){
        for(auto e:adj[i]){
            for(auto x:e){
                cout<<x<<" ";
            }
            cout<<"BAR ";
        }
        cout<<endl;
    }

    Solution obj;
    vector<vector<int>>ans;
    map<int,vector<int>>mp;
    for(int i=0;i<v;i++){
        vector<int> res=obj.dijkstra(v,adj,i);
        // for(auto e:res){
        //     cout<<e<<" ";
        // }
        // cout<<"=>"<<accumulate(res.begin(),res.end(),0)<<endl;
        mp[accumulate(res.begin(),res.end(),0)].push_back(i);
        cout<<endl;
    }
    cout<<endl;
    for(auto e:mp){
        for(auto x:e.second){
            cout<<x+1<<" ";
        }
        break;
    }
    
    // Solution obj;
    // vector<int> res = obj.dijkstra(v, adj, 3);

    // for (int i = 0; i < v; i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << endl;
    return 0;
}