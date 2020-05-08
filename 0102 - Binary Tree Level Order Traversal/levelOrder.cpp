// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if ( root == nullptr ){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* levelNode = new TreeNode();
        q.push(levelNode);
        TreeNode* tempTreeNode;
        
        vector<int>* currentRow = new vector<int>();
        while ( q.size() > 1 ){
            tempTreeNode = q.front();
            q.pop();
            if (tempTreeNode == levelNode){
                result.push_back(*currentRow);
                currentRow = new vector<int>();
                q.push(levelNode);
                continue;
            } else {
                currentRow->push_back(tempTreeNode->val);
            }
            
            if ( tempTreeNode->left ){
                q.push( tempTreeNode->left );
            }
            if ( tempTreeNode->right ){
                q.push( tempTreeNode->right );
            }
        }
        result.push_back(*currentRow);
        return result;
    }
};

/*  Test Cases
* [3,9,20,null,null,15,7]
* [3,null,9,null,20,15,7]
* [1,2,null,3,null,null,null,null]
* []
*/
