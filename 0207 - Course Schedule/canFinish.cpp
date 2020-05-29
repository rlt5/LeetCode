// 207. Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.

// Example 2:
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
 
// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool* visited;
    bool* recursive;
    vector<int>* adjList;

    bool isCyclic(int i){
        if ( visited[i] == false ){
            visited[i] = true;
            recursive[i] = true;
            for ( int prereq : adjList[i] ){
                if ( !visited[prereq] && isCyclic(prereq) ){
                    return true;
                } else if ( recursive[prereq] ){
                    return true;
                }
            }
        }
        recursive[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = new bool[numCourses];
        recursive = new bool[numCourses];

        // Build the adjacency List
        adjList = new vector<int>[numCourses];
        for ( vector<int> prereq : prerequisites ){
            adjList[prereq[0]].push_back(prereq[1]);
        }        
        
        // Initialize the visited and recursive lists.
        for ( int j = 0; j< numCourses; j++ ){
            visited[j] = false;
            recursive[j] = false;
        }
            
        for ( int i = 0; i < numCourses; i++ ){
            if ( isCyclic(i) )
                return false;
        }

        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> prerequisites;
    // int N = 2;
    // prerequisites.push_back({0,1});
    // prerequisites.push_back({1,0});


    // int N = 3;
    // prerequisites.push_back({0,1});
    // prerequisites.push_back({0,2});
    // prerequisites.push_back({1,2});
    // int N = 8;
    // prerequisites.push_back({1,0});
    // prerequisites.push_back({2,6});
    // prerequisites.push_back({1,7});
    // prerequisites.push_back({6,4});
    // prerequisites.push_back({7,0});
    // prerequisites.push_back({0,5});

    // int N = 7;
    // prerequisites.push_back({1,0});
    // prerequisites.push_back({0,3});
    // prerequisites.push_back({0,2});
    // prerequisites.push_back({3,2});
    // prerequisites.push_back({2,5});
    // prerequisites.push_back({4,5});
    // prerequisites.push_back({5,6});
    // prerequisites.push_back({2,4});

    int N = 4;
    prerequisites.push_back({0,1});
    prerequisites.push_back({3,1});
    prerequisites.push_back({1,3});
    prerequisites.push_back({3,2});
    cout << boolalpha << s.canFinish(N,prerequisites) << endl; 
}