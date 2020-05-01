#include <iostream>
#include <iomanip>
#include <vector>
#include <utility> 
#include <map>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int size = nums.size();
        int failureIndex = -1;
        for ( int i = 0; i < size-1 ; i++ ){
            if ( nums[i] > nums[i+1]  ){
                if (failureIndex != -1) return false;
                failureIndex = i;
            } 
        }
        if ( failureIndex == 0 || failureIndex == size-2 || failureIndex == -1 ) return true;
        if ( nums[failureIndex-1] <= nums[failureIndex+1] || nums[failureIndex] <= nums[failureIndex+2] ) return true;
        return false;
    }
};

void print(std::vector <int> const &a) {
    std::string s;
    s += '[';
    for(int i=0; i < a.size(); i++){
        s += std::to_string(a[i]);
        s += ',';
    }
    s = s.substr(0,s.size()-1);
    s += ']';
    std::cout << std::setw(14) << s;
}

int main(){
    Solution s;
    std::map< std::vector<int>, bool> testCases;
    testCases.insert( std::pair<std::vector<int>,bool>({4,2,2,3}, true) );
    testCases.insert( std::pair<std::vector<int>,bool>({4,2,1}, false) );
    testCases.insert( std::pair<std::vector<int>,bool>({3,4,2,3}, false) );
    testCases.insert( std::pair<std::vector<int>,bool>({2,3,3,2,4}, true) );
    testCases.insert( std::pair<std::vector<int>,bool>({-1,4,2,3}, true) );
    testCases.insert( std::pair<std::vector<int>,bool>({3,1}, true) );
    testCases.insert( std::pair<std::vector<int>,bool>({1,2,4,5,3}, true) );
    
    std::cout << std::endl << std::setw(14) << std::right << "TestCase";
    std::cout << std::setw(10) << std::right << "Output" << std::setw(10) << std::right << "Expected" << std::setw(10) << std::right << "Result" << std::endl;
    for ( std::pair<std::vector<int>,bool> testCase : testCases ){
        bool result = s.checkPossibility(testCase.first);
        print(testCase.first);
        std::cout << std::setw(10) << std::right << std::boolalpha << result << std::setw(10) << std::right << std::boolalpha  << testCase.second;
        if ( testCase.second == result )
            std::cout << std::setw(10) << std::right << "--- PASS" << std::endl;
        else 
            std::cout << std::setw(10) << std::right << "--- FAIL <---" << std::endl;
    }

}

