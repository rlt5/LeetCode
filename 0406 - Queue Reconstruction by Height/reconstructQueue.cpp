// 406. Queue Reconstruction by Height
// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

// Example
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct {
        bool operator()(vector<int> person1, vector<int> person2) const 
        { 
            if ( person1[0] == person2[0] )
                return ( person1[1] < person2[1] );
            return (person1[0] > person2[0]); 
        } 
    } compareVector;

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), compareVector);
        cout << "[";
        for ( auto person : people ){
            cout << "[" << person[0] << "," << person[1] << "],";
        }
        cout << "]";        
        for ( int i = 0; i < people.size(); i++ ){
            result.insert(result.begin() + people[i][1], people[i] );
            cout << "[";
            for ( auto r : result ){
                cout << "[" << r[0] << "," << r[1] << "],";
            }
            cout << "]" << endl;
        }
        return result;
    }
};