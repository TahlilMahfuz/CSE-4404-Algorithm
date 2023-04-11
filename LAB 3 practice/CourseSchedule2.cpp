#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef long long int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.rbegin(),v.rend()

using namespace std;

vector<int> findOrder(int n, vector<vector<int>>&pre) {
    vector<int>ans,indegree(n);
    vector<vector<int>>v(n);
    // map<int,vector<int>>v;
    for(auto &e:pre){
        v[e[1]].push_back(e[0]);
        indegree[e[0]]++;
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){  
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for(auto e:v[x]){
            indegree[e]--;
            if(indegree[e]==0){
                q.push(e);
            }
        }
    }
    if(ans.size()==n)return ans;
    return {};
}

signed main(){
    fio;
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    test(findOrder(n,v));
    // for(auto e:v){
    //     for(auto x:e){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    

    return 0;
}