// 368. Largest Divisible Subset
// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
// Si % Sj = 0 or Sj % Si = 0.
// If there are multiple solutions, return any subset is fine.

// Example 1:
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)

// Example 2:
// Input: [1,2,4,8]
// Output: [1,2,4,8]
// O(N^2) DP Solution

// TEST CASES
// [1,2,3]
// [1,2,4,8]
// [3,4,16,8]
// [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
// [1,2,3,4,5,6,7,8]
// [2000000000]
// [2,4,8]
// [4,8,10,240]

#include <vector>

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> solution;
        if ( nums.empty() || nums[0] == 0 ) return solution;
        
        int* count = new int[nums.size()];
        for ( int i = 0; i < nums.size(); i++ ){
            count[i] = 1;
        }
        sort( nums.begin(), nums.end() );
        
        for (int i = 0; i < nums.size(); i++){
            for ( int j = i-1; j >=0; j-- ){
                if ( nums[i] % nums[j] == 0 ) count[i] = count[i] > count[j] + 1 ? count[i] : count[j]+1;
            }
        }
        
        int max = 0;
        for ( int i = 1; i < nums.size(); i++ ){
            max = count[i] > count[max] ? i : max;
        }
        
        int maxNum = nums[max];
        int currCount = count[max];
        for ( int i = max; i >= 0; i-- ){
            if ( maxNum % nums[i] == 0 && count[i] == currCount ){
                solution.push_back(nums[i]);
                maxNum = nums[i];
                currCount--;
            }
        }
        
        return solution;
    }
};