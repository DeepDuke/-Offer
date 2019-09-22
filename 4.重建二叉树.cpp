/*
基于先序序列和中序序列重建而建二叉树
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);
        // root->val = pre[0];
        int i;
        for(i = 0; i < vin.size(); i++){
            if(vin[i] == pre[0]){
                break;
            }
        }
        int leftLength = i, rightLength = vin.size()-leftLength-1;
        // left child tree
        vector<int> leftPre(pre.begin()+1, pre.begin()+leftLength+1);
        vector<int> leftIn(vin.begin(), vin.begin()+leftLength);
        root->left = reConstructBinaryTree(leftPre, leftIn);
        // right child tree
        vector<int> rightPre(pre.begin()+leftLength+1, pre.end());
        vector<int> rightIn(vin.begin()+leftLength+1, vin.end());
        root->right = reConstructBinaryTree(rightPre, rightIn);
        
        return root;
    }
};