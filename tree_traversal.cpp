//
// Created by peilin.wu on 2023/4/13.
//

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
    // 中序遍历，通过移动push_back()位置完成前中后序遍历；
    // 前序：根左右
    // 中序：左根右
    // 后序：左右根
    // 递归方法出栈的顺序还存在疑问；
    void inorder(TreeNode* root, vector<int>& tv){
        if (root == nullptr){
            return;
        }
        inorder(root->left, tv);
        tv.push_back(root->val);
        inorder(root->right, tv);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> traverse_vec;
        inorder(root, traverse_vec);
        return traverse_vec;
    }
};
