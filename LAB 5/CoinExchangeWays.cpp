#include<bits/stdc++.h>
using namespace std;

int n;
int coin[55];
long long dp[55][255];

long long call(int i,int w)
{
    if(w == 0) return 1;
    if(i == n or w < 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    dp[i][w] = call(i + 1, w) + call(i,w - coin[i]);

    return dp[i][w];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int w;
    cin >> w >> n;
    for(int i = 0; i < n; i++)
        cin >> coin[i];

    cout << call(0,w);
}