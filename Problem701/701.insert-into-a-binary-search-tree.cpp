/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */

// @lc code=start
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

/*
// recursive
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL){
            return new TreeNode(val);
        }else if(root->val<val){
            root->right =  insertIntoBST(root->right,val);

        }else{
            root->left =  insertIntoBST(root->left,val);
        }
        return root;
    }
};
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL){
            return new TreeNode(val);}

        TreeNode *current = root;

        while(true){
            if(current->val < val){
                if(current->right!=NULL) current = current->right;
                else{
                    current->right = new TreeNode(val);
                    break;
                }
            }else{
                if(current->left!=NULL) current = current->left;
                else{
                    current->left = new TreeNode(val);
                    break;
                }

            }


        } 
        return root;
            
    }
};
// @lc code=end

