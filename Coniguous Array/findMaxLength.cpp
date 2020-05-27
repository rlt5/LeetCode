#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;


// O(N) solution
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int size = nums.size();
        int index[size*2 + 1];
        for (int i = 0; i < size*2+1; i++){
            index[i] = -2;
        }
        
        index[size] = -1;
        int count = 0;
        for ( int i = 0; i < size; i++ ){
            if ( nums[i] ) count++;
            else count--;
            if ( index[count + size] >= -1 ){
                if ( maxLength < i - index[count + size] ) maxLength = i-index[count + size];
            } else 
                index[count + size] = i;
        }
        return maxLength;
    }
};

// // O(N^2) solution
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int maxLength = 0;
//         int count;
//         for ( int begin = 0; begin < nums.size(); begin++ ){
//             count = 0;
//             for ( int end = begin; end < nums.size(); end++ ){
//                 if ( nums[end] ) count++;
//                 else count--;
//                 if ( maxLength < end - begin && count == 0 ) maxLength = end-begin + 1;
//             }
//         }
//         return maxLength;
//     }
// };

int main(){
    Solution s;
    vector<int> tc1 = {0,1};
    // vector<int> tc2 = {100,1,2,3,2,1,0};
    vector<int> tc3 = {0,1,0,1};
    vector<int> tc4 = {0,1,0,1,0};
    vector<int> tc5 = {1,0,1,0};
    vector<int> tc6 = {0,0,0,1,1,1,0};
    vector<int> tc7 = {0,0,1,0,0,0,1,1};
    // // vector<int> tc8 = {0,0,1,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,1};

    cout << "Max = " << s.findMaxLength(tc1) << endl; 
    // cout << "Max = " << s.findMaxLength(tc2) << endl; 
    cout << "Max = " << s.findMaxLength(tc3) << endl; 
    cout << "Max = " << s.findMaxLength(tc4) << endl; 
    cout << "Max = " << s.findMaxLength(tc5) << endl; 
    cout << "Max = " << s.findMaxLength(tc6) << endl; 
    cout << "Max = " << s.findMaxLength(tc7) << endl; 
    // cout << "Max = " << s.findMaxLength(tc8) << endl; 
    // for (uint32_t i = 0; i < (uint32_t)50000*50000; i++ )
    //     i = i;
}