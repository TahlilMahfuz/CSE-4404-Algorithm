#include<bits/stdc++.h>
#define int long long int

using namespace std;

int n;
vector<int>v;
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
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v.push_back(a);
        }
        // for(auto e:v){cout<<e;}
        memset(dp,-1,sizeof dp);

        cout<<findMix(0,n-1)<<endl;

        v.clear();
    }
}