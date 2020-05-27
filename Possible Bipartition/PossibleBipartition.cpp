#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:

    void printStack(stack<int> s){
        queue<int> q;
       while ( !s.empty() ){
            q.push(s.top());
            s.pop();
        }
        cout << "---STACK---" << endl;
        while ( !q.empty() ){
            cout << "    " << q.front()+1<< endl;
            s.push(q.front());
            q.pop();
        }
        cout << "--- END ---" << endl;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        map<int, vector<int>> edge;
        for ( vector<int> dislike : dislikes ){
            dislike[0]--;
            dislike[1]--;
            edge[dislike[0]].push_back(dislike[1]);
            edge[dislike[1]].push_back(dislike[0]);
        }
        
        stack<int> s;
        for ( map<int, vector<int>>::iterator it = edge.begin(); it != edge.end(); it++ ){
            int visited[N];
            int parents[N];
            for ( int i = 0; i < N; i++ ){
                visited[i] = -1;
                parents[i] = -1;
            }
            
            int current = it->first;
            s.push(current);
            visited[current] = 0;
            while ( !s.empty() ){
                // printStack(s);
                current = s.top();
                s.pop();
                // cout << "parent = " << parents[current] + 1 << endl;
                // cout << "current = " << current + 1<< endl;
                for ( int child : edge[current] ){
                    // cout << "child = " << child +1<< " visited = " << visited[child] << endl;
                    if ( child != parents[current] ){
                        if ( visited[child] == -1 ){ // not visited
                            parents[child] = current;
                            s.push(child);
                            visited[child] = visited[current]+1;    
                        } else { // cycle exists
                            if ( (visited[child] + visited[current] + 1) % 2 ) {
                                // cout << "--CYCLE EXISTS--" << endl;
                                // cout << "parent = " << parents[current]+1 << endl;
                                // cout << "current = " << current+1 << endl;
                                // cout << "child = " << child+1 << " visited = " << visited[child] << endl;
                                // cout << "visited[child] = " << visited[child] << " visited[current] = " << visited[current] << endl;
                                // cout << "edges: " << endl;
                                // for ( int e : edge[current] ){
                                //     cout << e+1 << ",";
                                // }
                                // cout << endl;
                                return false;
                            }
                        }    
                    }
                }
                // cout << endl;
            }
        }
        return true;
        
    }
};

int main(){
    // int N = 4;
    // vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
    int N = 3;
    vector<vector<int>> dislikes = {{1,2},{1,3},{2,3}};
    // int N = 10;
    // vector<vector<int>> dislikes = {{4,7},{4,8},{5,6},{1,6},{3,7},{2,5},{5,8},{1,2},{4,9},{6,10},{8,10},{3,6},{2,10},{9,10},{3,9},{2,3},{1,9},{4,6},{5,7},{3,8},{1,8},{1,7},{2,4}};
    Solution s;
    if ( s.possibleBipartition(N,dislikes)) cout << "true";
    else cout << "false";
    cout << endl;
}