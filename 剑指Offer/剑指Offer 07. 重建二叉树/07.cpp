/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归分治
        return recursionBuild(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }

    //递归分治
    TreeNode* recursionBuild(const vector<int>::iterator preBegin,const vector<int>::iterator preEnd,const vector<int>::iterator inBegin,const vector<int>::iterator inEnd )
    {
        if(inEnd==inBegin) return nullptr;

        TreeNode* cur = new TreeNode(*preBegin);    // 建立子树
        vector<int>::iterator root = find(inBegin,inEnd,*preBegin);  // 查找中序遍历中根节点的位置
        cur->left = recursionBuild(preBegin+1,preBegin+1+(root-inBegin),inBegin,root);  // 挂载左子树
        cur->right = recursionBuild(preBegin+1+(root-inBegin),preEnd,root+1,inEnd);
        return cur;
    }
};