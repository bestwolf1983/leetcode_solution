/*
 * Definition for binary tree
*/
#include <stdlib.h>
#include <stdio.h>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int depth = 0x7FFFFFFF;
        helper(root, depth, 1);
        return depth;
    }

    void helper(TreeNode* root, int& depth, int cur){
        if(cur >= depth){
            return;
        }else if(root->left == NULL && root->right == NULL){
            depth = cur;
        }else{
            if(root->left)
                helper(root->left, depth, cur + 1);
            if(root->right)
                helper(root->right, depth, cur + 1);
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    Solution s;
    int depth = s.minDepth(root);
    printf("len is: %d\n", depth);
    return 0;
}
