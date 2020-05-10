// Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

// The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple, otherwise, it does not have any apple.

// Example 1:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
// Output: 8 
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

// Example 2:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
// Output: 6
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
// Example 3:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
// Output: 0
 
// Constraints:

// 1 <= n <= 10^5
// edges.length == n-1
// edges[i].length == 2
// 0 <= fromi, toi <= n-1
// fromi < toi
// hasApple.length == n

class Solution {
public:
     struct TreeNode {
         int val;
         bool checked;
         vector<TreeNode*> children;
         TreeNode* parent;
         TreeNode() : val(0), checked(false), parent(nullptr){}
         TreeNode(int x) : val(x), checked(false), parent(nullptr){}
     };
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        // Create the tree
        // O(E+V)
        vector<TreeNode*> nodes;
        for ( int i = 0; i < hasApple.size(); i++ ){
            nodes.push_back(new TreeNode(i));
        }
        TreeNode* root = nodes[0];
        for ( vector<int> edge : edges ){
            nodes[edge[0]]->children.push_back(nodes[edge[1]]);
            nodes[edge[1]]->parent = nodes[edge[0]];
        }
        
        TreeNode* tempNode;
        int counter = 0;
        for ( int i = 0; i < hasApple.size(); i++ ){
            if ( hasApple[i] ){
                tempNode = nodes[i];
                while ( tempNode != root && tempNode->checked == false ){
                    tempNode->checked = true;
                    counter += 2;
                    tempNode = tempNode->parent;
                }
            }
        }
       
        return counter;
    }
};