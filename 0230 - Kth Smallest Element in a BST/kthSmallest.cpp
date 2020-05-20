// 230. Kth Smallest Element in a BST

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


// TEST CASES
// [5,3,6,2,4,null,null,1]
// 3
// [3,1,4,null,2]
// 1
// [41,37,44,24,39,42,48,1,35,38,40,null,43,46,49,0,2,30,36,null,null,null,null,null,null,45,47,null,null,null,null,null,4,29,32,null,null,null,null,null,null,3,9,26,null,31,34,null,null,7,11,25,27,null,null,33,null,6,8,10,16,null,null,null,28,null,null,5,null,null,null,null,null,15,19,null,null,null,null,12,null,18,20,null,13,17,null,null,22,null,14,null,null,21,23]
// 25


#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ITERATIVE SOLUTION
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> s;
        s.push(root);
        while ( root || !s.empty() ){
            while ( root ){ // GO LEFT ALL THE WAY
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            k--;
            if ( k == 0 )
                return root->val;
            root = root->right;
        }
        return -1;
    }
};

// // Binary Tree Recursive Tree inorder Solution. Passed.
// class Solution {
// public:
    
//     vector<int> arr;
//     int index;
    
//     void infix(TreeNode* root){
//         if ( root->left )
//             infix(root->left);
        
//         arr.push_back(root->val);
//         if (arr.size() == index)
//             return;
        
//         if ( root->right )
//             infix(root->right);
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         index = k;
//         infix(root);
//         return arr[k-1];
//     }
// };