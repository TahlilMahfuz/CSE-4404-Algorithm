#include<bits/stdc++.h>
using namespace std;

//Reverse Pair
class Solution {
public:

    long long int merge(vector<int>&nums,long long int low,long long int mid,long long int high){
        long long int j=mid+1;
        long long int cnt=0;
        for(long long int i=low;i<=mid;i++){
            while(j<=high and nums[i]>nums[j]*2LL){
                j++;
            }
            cnt+=(j-(mid+1));
        }

        vector<long long int>temp;

        long long int left=low,right=mid+1;
        while(left<=mid and right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else temp.push_back(nums[right++]);
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }
        for(long long int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return cnt;
    }

    long long int mergesort(vector<int>&nums,long long int low,long long int high){
        if(low>=high){return 0;}
        long long int mid=(low+high)/2;
        long long int ans=mergesort(nums,low,mid);
        ans+=mergesort(nums,mid+1,high);
        ans+=merge(nums,low,mid,high);
        return ans;
    }
    long long int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};



