#include <bits/stdc++.h> 
#define long long int int

using namespace std;

int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0 and j==0){return grid[i][j];}
    if(i<0 or j<0){return 1e9;}

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int up=grid[i][j]+f(i,j-1,grid,dp);
    int left=grid[i][j]+f(i-1,j,grid,dp);
    return dp[i][j]=min(left,up);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>matrix;
    for(int i=0;i<n;i++){
        vector<int>a;
        for(int j=0;j<m;j++){
            int p;cin>>p;
            a.push_back(p);
        }
        matrix.push_back(a);
    }
    cout<<minSumPath(matrix);
    return 0;
}