#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()
 
using namespace std;

int n;
int mat[16][16];
int dp[16][1<<16];

bool isOn(int N,int pos)
{
    return (bool)(N & (1<<pos)) ;
}

int turnOn(int N,int pos)
{
    return (N | (1<<pos));
}

int matchmake(int i,int mask){
    if(mask==(1<<n)-1){
        return 0;
    }
    if(dp[i][mask]!=-1){
        return dp[i][mask];
    }
    int mx=dp[i][mask];
    for(int j=0; j<n; j++){
        if(isOn(mask,j)==0){
            mx=max(mx,mat[i][j]+matchmake(i+1,turnOn(mask,j)));
        }
    }
    return mx;
}

signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<matchmake(0,0);

    return 0;
}