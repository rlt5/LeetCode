// 787. Cheapest Flights Within K Stops
// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

// Constraints:

// The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// The size of flights will be in range [0, n * (n - 1) / 2].
// The format of each flight will be (src, dst, price).
// The price of each flight will be in the range [1, 10000].
// k is in the range of [0, n - 1].
// There will not be any duplicated flights or self cycles.

// TEST CASES
// 3
// [[0,1,100],[1,2,100],[0,2,500]]
// 0
// 2
// 1
// 3
// [[0,1,100],[1,2,100],[0,2,500]]
// 0
// 2
// 2
// 8
// [[0,1,1],[0,6,2],[0,7,7],[1,2,6],[1,4,2],[1,6,2],[2,3,2],[2,4,1],[3,5,1],[4,7,1],[6,7,4]]
// 0
// 7
// 1
// 8
// [[0,1,1],[0,6,2],[0,7,7],[1,2,6],[1,4,2],[1,6,2],[2,3,2],[2,4,1],[3,5,1],[4,7,1],[6,7,4]]
// 0
// 7
// 2
// 8
// [[0,1,1],[0,6,2],[0,7,7],[1,2,6],[1,4,2],[1,6,2],[2,3,2],[2,4,1],[3,5,1],[4,7,1],[6,7,4]]
// 0
// 7
// 3
// 4
// [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
// 0
// 3
// 1

#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> distance(K+2,vector<int>(n, INT_MAX));
        
        for ( int i  = 0; i <= K+1; i++ ){
            distance[i][src] = 0;
        }
        
        for ( int i = 1; i <= K+1; i++ ){
            for ( auto &flight: flights ){
                int source = flight[0];
                int destination = flight[1];
                int price = flight[2];
                
                if ( distance[i-1][source] != INT_MAX ){
                    distance[i][destination] = min(distance[i][destination], distance[i-1][source] + price);
                }
            }
        }
        return distance[K+1][dst] == INT_MAX ? -1 : distance[K+1][dst];
    }
};

// #include <vector>
// #include <iostream>
// #include <queue>
// #include <limits.h>
// using namespace std;

// // Dijkastra's Single Shortest Path Algorithm MODIFIED with K steps. Does not work...
// class Solution {
// public:
//     size_t index( int x, int y, int n ) const { return x + n * y; }
    
//     void printAdjMatrix(int* d, int n){
//         for ( int x = 0; x < n; x++ ){ // PRINT OUT ADJ MATRIX
//             for ( int y = 0; y < n; y++ ){
//                 cout << d[index(x,y,n)] << " ";
//             }
//             cout << endl;
//         }
//     }
    
//     int minDistance(vector<int> distance, vector<bool> completed, int n) { 
//         int min = INT_MAX;
//         int minIndex;
//         for (int flight = 0; flight < n; flight++){
//             if (completed[flight] == false && distance[flight] <= min){
//                 min = distance[flight];
//                 minIndex = flight; 
//             }
//         }
//         return minIndex; 
//     } 
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         vector<vector<int>> distance(K+2,vector<int>(n, INT_MAX);
        
//         vector<int> steps(n,-1);
//         vector<bool> completed(n,false);
//         distance[src] = 0;
//         // steps[src] = 0;
        
//         // Create adjacency matrix
//         int* d = new int[n*n];
//         for ( int x = 0; x < n; x++ ){
//             for ( int y = 0; y < n; y++ ){
//                 d[index(x,y,n)] = 0;
//             }
//         }
//         for ( vector<int> flight : flights ){
//             d[index(flight[0],flight[1],n)] = flight[2];
//         }
        
//         printAdjMatrix(d,n);

//         int cost;
//         int minIndex;
//         for ( int count = 0; count < n; count++ ){
//             minIndex = minDistance(distance,completed,n);
//             completed[minIndex] = true;
//             for ( int flight = 0; flight < n; flight++ ){
//                 cost = d[index(minIndex,flight,n)];
//                 if ( !completed[flight] && 
//                      cost && 
//                      distance[minIndex] != INT_MAX && 
//                      distance[minIndex] + cost < distance[flight] && 
//                      steps[minIndex] < K ){
//                         distance[flight] = distance[minIndex] + cost;
//                         steps[flight] = steps[minIndex] + 1;
//                 }
//             }
//         }
        
//         for (int i =0; i < n; i++)
//             cout << distance[i] << " ";
//         if ( distance[dst] == INT_MAX ){
//             return -1;
//         } else 
//             return distance[dst];
//     }
// };