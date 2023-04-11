#include <bits/stdc++.h>
#include <unordered_map>
 
#define ll                  long long int 
#define PI                  3.14159265359
#define am_so_cool_you_know (ios::sync_with_stdio(0), cin.tie(0),cout.tie(0));
#define kaam_shesh          return 0;
#define nl                  "\n"
 
using namespace std;



vector<bool> visited(100, false);
void DFS(int u, vector<bool> &visited, vector<int> adj[])
{
    
    // visited[u] = true;
    for(int i = 0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if (visited[v]==false)
            {
                visited[v] = true;
                DFS(v, visited, adj);
            }
    }
      
}

int getUnreachableCount(vector<int> adj[], int nodes, int start)
{
    int count=0;
    for (int i = 1; i < nodes;i++)
    {
        visited[i] = false;
    }
    DFS(start, visited, adj);
    for (int u = 1; u <= nodes; u++) {
        if (visited[u] == false) {
            count+=1;
        }
    }
    return count;
}
 
int main()
{
    am_so_cool_you_know;
    // cin>>
    // cout<<
    // sort(arr,arr+length)
    // 706B has binary search
    int nodes,edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes+1];
    int a, b;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int testCases;
    cin >> testCases;
    int start;
    for (int i = 0; i < testCases; i++)
    {
        cin >> start;
        int count = getUnreachableCount(adj, nodes, start);
        cout << count<< " ";
        for (int k = 1; k <= nodes; k++)
        {
            if(visited[k]==false)
            {
                cout << k << " ";
            }
        }
        cout << nl;
    }

    kaam_shesh;
}