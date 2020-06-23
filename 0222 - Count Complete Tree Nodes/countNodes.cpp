// 222. Count Complete Tree Nodes
// Given a complete binary tree, count the number of nodes.

// Note:

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Example:

// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
using namespace std;

class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* curr;
        int count = 0;
        stack<TreeNode*> s;
        s.push(root);
        while ( !s.empty() ){
            curr = s.top();
            s.pop();
            count++;
            if ( curr->left ) s.push(curr->left);
            if ( curr->right ) s.push(curr->right);
        }
        return count;
    }
};