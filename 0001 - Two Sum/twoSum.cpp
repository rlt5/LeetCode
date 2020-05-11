// 1. Two Sum

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <vector>
using namespace std;

class Solution {
public:
    
//     // Brute force
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int s = nums.size();
//         vector<int> ret;
//         for ( int i = 0; i < s; i++ ){
//             for ( int j = 0; j < s; j++ ){
                
//                 if (nums[i] + nums[j] == target && i != j ){

//                     ret = {i,j};
                    
//                     return ret;
//                 }
//             }   
//         }
//     return ret;
//     }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        vector<int> ret;
        for ( int i = 0; ; i++ ){
            for ( int j = 0; j < s; j++ ){
                if (nums[i] + nums[j] == target && i != j ){

                    ret = {i,j};
                    
                    return ret;
                }
            }   
        }
    return ret;
    }
};
