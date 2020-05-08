// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// Constraints:

// 2 <= coordinates.length <= 1000
// coordinates[i].length == 2
// -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
// coordinates contains no duplicate point.

// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false

class Solution {
public:
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if ( coordinates.size() < 3 ){
           return true; 
        }
        int x1, y1, x2, y2, x3, y3;
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        x2 = coordinates[1][0];
        y2 = coordinates[1][1];
        for ( int i = 2; i < coordinates.size(); i++ ){
            x3 = coordinates[i][0];
            y3 = coordinates[i][1];
            if ( x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2 )
                return false;
        }
        return true;
        
    }
};