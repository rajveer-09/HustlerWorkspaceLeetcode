class Solution {
public:
    TreeNode* solve(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie, map<int, int>& mp) {

        if (ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(pre[ps]);
        int inRoot = mp[root->val];
        int leftCnt = inRoot - is;

        root->left = solve(pre, ps + 1, ps + leftCnt, in, is, inRoot - 1, mp);
        root->right = solve(pre, ps + leftCnt + 1, pe, in, inRoot + 1, ie, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        ios_base::sync_with_stdio(false);
        map<int, int> mp;
        for (int i = 0; i < in.size(); ++i) {
            mp[in[i]] = i;
        }
        return solve(pre, 0, pre.size() - 1, in, 0, in.size() - 1, mp);
    }
};
