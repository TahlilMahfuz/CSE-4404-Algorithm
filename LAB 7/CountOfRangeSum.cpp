#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix_sum(n + 1);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        return mergeSortCount(prefix_sum, 0, n, lower, upper);
    }

    int mergeSortCount(vector<long long>& prefix_sum, int start, int end, int lower, int upper) {
        if (start >= end) {
            return 0;
        }
        int mid = (start + end) / 2;
        int count = mergeSortCount(prefix_sum, start, mid, lower, upper) + mergeSortCount(prefix_sum, mid + 1, end, lower, upper);
        int left = mid + 1, right = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (left <= end && prefix_sum[left] - prefix_sum[i] < lower) {
                left++;
            }
            while (right <= end && prefix_sum[right] - prefix_sum[i] <= upper) {
                right++;
            }
            count += right - left;
        }
        // Sorting the subarrays using custom merge function
        vector<long long> temp(end - start + 1);
        int i = start, j = mid + 1, k = 0;
        while (i <= mid && j <= end) {
            if (prefix_sum[i] < prefix_sum[j]) {
                temp[k++] = prefix_sum[i++];
            } else {
                temp[k++] = prefix_sum[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = prefix_sum[i++];
        }
        while (j <= end) {
            temp[k++] = prefix_sum[j++];
        }
        for (int i = 0; i < k; i++) {
            prefix_sum[start + i] = temp[i];
        }
        return count;
    }
};

//Count of range sum
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix_sum(n + 1);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        return mergeSortCount(prefix_sum, 0, n, lower, upper);
    }

    int mergeSortCount(vector<long long>& prefix_sum, int start, int end, int lower, int upper) {
        if (start >= end) {
            return 0;
        }
        int mid = (start + end) / 2;
        int count = mergeSortCount(prefix_sum, start, mid, lower, upper) + mergeSortCount(prefix_sum, mid + 1, end, lower, upper);
        int left = mid + 1, right = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (left <= end && prefix_sum[left] - prefix_sum[i] < lower) {
                left++;
            }
            while (right <= end && prefix_sum[right] - prefix_sum[i] <= upper) {
                right++;
            }
            count += right - left;
        }
        inplace_merge(prefix_sum.begin() + start, prefix_sum.begin() + mid + 1, prefix_sum.begin() + end + 1);
        return count;
    }
};


