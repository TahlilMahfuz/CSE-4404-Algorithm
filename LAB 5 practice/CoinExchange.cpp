#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef long long int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()
 
using namespace std;

lli n;
vector<int>c;
lli dp[255][255];

long long coinexchange(int i,int w){
    if(w == 0) return 1;
    if(i == n or w < 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    dp[i][w] = coinexchange(i + 1, w) + coinexchange(i,w - c[i]);

    return dp[i][w];

}

signed main(){
    memset(dp,-1,sizeof(dp));
    lli w;
    cin>>w>>n;
    c.resize(n);
    for(auto &e:c){
        cin>>e;
    }

    cout<<coinexchange(0,w);

}















// long long int coinexchange(long long int n,long long int m,vector<long long int>c){
//     if(n==0){
//         return 1;
//     }
//     if(n<0 or m<=0){
//         return 0;
//     }
//     return coinexchange(n,m-1,c) + coinexchange(n-c[m-1], m, c);

// }


// int main(){
//     // fio;
//     long long int n,m;
//     cin>>n>>m;

//     vector<long long int>v(n);
//     for(auto &e:v){
//         cin>>e;
//     }

//     // test(v);

//     cout<<coinexchange(n,m,v);


//     return 0;
// }

// int coinexchange(lli n, lli m, vector<lli> c) {
//     lli dp[n + 1];
//     for(auto &e:dp){
//         e=0;
//     }
//     dp[0] = 1;

//     for (lli i = 0; i < m; i++) {
//         for (lli j = c[i]; j <= n; j++) {
//             dp[j] += dp[j - c[i]];
//         }
//     }

//     return dp[n];
// }

// signed main() {
//     fio;
//     lli n,m;
//     cin>>n>>m;
//     vector<lli>v(m);
//     for(auto &e:v){
//         cin>>e;
//     }

//     cout << coinexchange(n, m, v) << endl;
//     return 0;
// }









