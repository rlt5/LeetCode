// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

// Example 1:
// Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
// Output: 4 
// Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

// Example 2:
// Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
// Output: 6
// Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

// Example 3:
// Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
// Output: 9

// Constraints:

// 2 <= h, w <= 10^9
// 1 <= horizontalCuts.length < min(h, 10^5)
// 1 <= verticalCuts.length < min(w, 10^5)
// 1 <= horizontalCuts[i] < h
// 1 <= verticalCuts[i] < w
// It is guaranteed that all elements in horizontalCuts are distinct.
// It is guaranteed that all elements in verticalCuts are distinct.

#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hSize = horizontalCuts.size();
        int vSize = verticalCuts.size();
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        uint32_t xbegin = 0, xend = 0, ybegin = 0, yend = 0;

        uint32_t xdiff = 0;
        for ( int i = 0; i < horizontalCuts.size()-1; i++ ){
            xbegin = horizontalCuts[i];
            xend   = horizontalCuts[i+1];
            if ( xdiff < xend-xbegin ){
                xdiff = xend-xbegin;
            }
        }
        
        uint64_t ydiff = 0;
        for ( int i = 0; i < verticalCuts.size()-1; i++ ){
            ybegin = verticalCuts[i];
            yend   = verticalCuts[i+1];
            if ( ydiff < yend-ybegin ){
                ydiff = yend-ybegin;
            }
                
        }
        const unsigned int m = 1000000007;
        return (uint64_t(xdiff*ydiff)) % m;
    }
};