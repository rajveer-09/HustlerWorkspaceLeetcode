class Solution {
public:
 
int f(int maxx,int minn,TreeNode*root)
{
    if(root==nullptr)return maxx-minn;
    maxx=max(maxx,root->val);
    minn=min(minn,root->val);
    int l=f(maxx,minn,root->left);
    int r=f(maxx,minn,root->right);
    return max(l,r);
}
    int maxAncestorDiff(TreeNode* root) {
        return f(-1e8,1e9,root);
    }
};