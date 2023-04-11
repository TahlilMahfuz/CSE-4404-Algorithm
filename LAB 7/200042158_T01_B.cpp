#include<bits/stdc++.h>
#define int long long int
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()

using namespace std;

int n;
vector<int>v,p;
int dp[1000][1000];

int sum(int s,int e){
    int ans=0;
    for(int i=s;i<=e;i++){
        ans+=v[i];
        ans%=100;
    }
    return ans;
}

int findMix(int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=INT_MAX;
    
    for(int k=i;k<=j;k++){
        dp[i][j]=min(mini,findMix(i,k)+findMix(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}

signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    vector<int>pref(n,v[0]);
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+v[i];
    }
    p=pref;
    // for(auto e:pref){cout<<e<<" ";}
    memset(dp,-1,sizeof dp);

    cout<<findMix(0,n-1)<<endl;
}