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
    int findParent(TreeNode* root, int x){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* currentNode;
        if (root->val == x){
            return -1;
        }
        while ( !q.empty() ){
            currentNode = q.front();
            q.pop();
            if ( currentNode->left ){
                if ( currentNode->left->val == x){
                    return currentNode->val;
                }
                q.push(currentNode->left);
            }
                
            if ( currentNode->right ){
                if ( currentNode->right->val == x){
                    return currentNode->val;
                }
                q.push(currentNode->right);
            }
        }
        return -1;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* currentNode = root;
        TreeNode* depthNode = new TreeNode(9999);
        int depth = 0;
        queue<TreeNode*> queue;
        queue.push(currentNode);
        queue.push(depthNode);
        bool xFound = false, yFound = false;
        while ( !queue.empty() ){
            currentNode = queue.front();
            queue.pop();
            
            if ( currentNode->val == 9999 ){
                if ( xFound == true && yFound == true ){
                    if ( findParent(root,x) == findParent(root,y) ){
                        return false;
                    }
                    return true;
                } else if ( xFound == true || yFound == true ){
                    return false;
                }
                depth++;
                queue.push(depthNode);
                continue;
            }      
            
            if ( currentNode->val == x ){
                xFound = true;
            } else if ( currentNode->val == y ){
                yFound = true;
            }
            
            if ( currentNode->left ){
                queue.push(currentNode->left);
            }
            if ( currentNode->right ){
                queue.push(currentNode->right);
            }
        }
        return -1;
        
    }
};