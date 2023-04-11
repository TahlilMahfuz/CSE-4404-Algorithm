// #include<bits/stdc++.h>
// #define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
// #define ll long long;
// typedef long long int lli;
// #define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
// #define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
// #define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
// #define input(v) for(auto &e:v){cin>>e;}
// #define all(v) v.begin(),v.end()
 
// using namespace std;
// string s;
// int n;
// lli dp[5001][5001];

// lli palindrome(lli a,lli b){
//     if(a>=b)
//         return 0;
//     if(dp[a][b]!=-1){
//         return dp[a][b];
//     }
//     if(s[a]==s[b]){
//         dp[a][b]=palindrome(a+1,b-1);
//     }
//     dp[a][b]=min(palindrome(a,b-1),palindrome(a+1,b))+1;
//     return dp[a][b];
// }

// signed main(){
//     cin>>n>>s;

//     cout<<palindrome(0,n-1);

//     return 0;

// }

#include<bits/stdc++.h>
using namespace std;
int n,ans=0x3f3f3f3f;
char s[5005];
int dp[5005][5005];
inline int dfs(int l,int r){
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int ret=0x3f3f3f3f;
    if(s[l]==s[r]) ret=dfs(l+1,r-1);
    ret=min(ret,min(dfs(l+1,r),dfs(l,r-1))+1);
    return dp[l][r]=ret;
}
int main(){
    scanf("%d%s",&n,s+1);
    memset(dp,-1,sizeof dp);
    printf("%d",dfs(1,n));
    return 0;
}