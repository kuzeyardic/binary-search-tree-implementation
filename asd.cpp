int maxSumPath(TreeNode* root){
    if(root==nullptr)
    return 0;

    int left = maxSumPath(root->left);
    int right = maxSumPath(root->right);
    
    return root->val+max(left,right);

}