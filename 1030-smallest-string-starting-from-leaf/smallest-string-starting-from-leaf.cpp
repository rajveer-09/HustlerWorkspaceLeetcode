class Solution {
public:
    deque<char> t={'|'};
    void f(TreeNode* node, deque<char>& s){// call by reference
        if (!node) return;
        s.push_front(node->val+'a');
        if (!node->left && !node->right){
            if (s<t) t=s; // compare s, t & take t as the smaller one
        }
        f(node->left, s);
        f(node->right, s);
        s.pop_front(); //Remove current node's value before returning to parent
    }

    string smallestFromLeaf(TreeNode* root) {
        deque<char> s={};
        f(root, s);
        return string(t.begin(), t.end());
    }
};