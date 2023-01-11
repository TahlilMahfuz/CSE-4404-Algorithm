#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.rbegin(),v.rend()
#define testmatrix(v) for(auto e:v){for(auto x:e){cout<<x<<" ";}cout<<endl;}

using namespace std;

bool isValid(int i, int j, int n, int m ,vector<vector<int>>&v){
    if(i>=0 && i<n && j>=0 && j<m && v[i][j] == 0){
        return true;
    }
    return false;
}

void dfs(int i,int j, int n,int m,vector<vector<int>>&v){
    v[i][j]=1;

    int ax[4]={0,1,0,-1};
    int ay[4]={1,0,-1,0};

    for(int p=0;p<4;p++){
        int nx=ax[p]+i;
        int ny=ay[p]+j;

        if(isValid(nx,ny,n,m,v)){
            dfs(nx,ny,n,m,v);
        }
    }
}

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            v[i][j]=a;
        }
    }
    //testmatrix(v);

    //1 - Water 0-land

    //Call DFS for boarders
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i*j==0 || i==n-1 || j==m-1){
                // cout<<i<<" "<<j<<endl;
                if(v[i][j]==0){
                    dfs(i,j,n,m,v);
                }
            }
        }
    }

    //Call dfs for the whole matrix
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                count++;
                dfs(i,j,n,m,v);
            }
        }
    }
    cout<<count<<endl;

    return 0;
}