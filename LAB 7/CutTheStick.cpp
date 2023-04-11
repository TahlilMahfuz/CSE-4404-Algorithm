#include <bits/stdc++.h> 
using namespace std;

int cutit(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<=j;k++){
        int cost=cuts[j+1]-cuts[i-1]+cutit(i,k-1,cuts,dp)+cutit(k+1,j,cuts,dp);
        mini=min(mini,cost);
    }   
    return dp[i][j]=mini;
}

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return cutit(1,c,cuts,dp);
}




//leetcode
class Solution {
public:
    int cutit(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            long long int cost=cuts[j+1]-cuts[i-1]+cutit(i,k-1,cuts,dp)+cutit(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }   
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size()+1;
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return cutit(1,c,cuts,dp);
    }
};