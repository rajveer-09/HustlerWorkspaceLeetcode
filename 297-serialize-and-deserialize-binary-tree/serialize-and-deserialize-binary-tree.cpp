class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "#,";
            }
        }

        return ans;
    }

    int getValue(string& s, int& idx) {
        if (idx >= s.size()) return INT_MIN;

        if (s[idx] == '#') {
            idx += 2;
            return INT_MIN;
        }

        int ans = 0;
        bool negative = false;

        if (s[idx] == '-') {
            negative = true;
            idx++;
        }

        while (idx < s.size() && s[idx] != ',') {
            ans = ans * 10 + (s[idx] - '0');
            idx++;
        }

        if (idx < s.size() && s[idx] == ',') idx++;

        return negative ? -ans : ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty()) return NULL;

        int idx = 0;
        int val = getValue(s, idx);
        if (val == INT_MIN) return nullptr;

        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int val1 = getValue(s, idx);
            if (val1 != INT_MIN) {
                node->left = new TreeNode(val1);
                q.push(node->left);
            }

            int val2 = getValue(s, idx);
            if (val2 != INT_MIN) {
                node->right = new TreeNode(val2);
                q.push(node->right);
            }
        }

        return root;
    }
};
