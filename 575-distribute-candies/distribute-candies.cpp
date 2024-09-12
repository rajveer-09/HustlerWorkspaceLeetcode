static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vd = vector<double>;
using si = set<int>;
using usi = unordered_set<int>;
using msi = map<string, int>;
using umii = unordered_map<int, int>;
using umsi = unordered_map<string, int>;
using pqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAX = (1 << 32) - 1;

void Print(const vi &v);
void Print(const vvi &vv);

//****************************************************************************************************

class Solution {
public:
    int distributeCandies(vector<int> &c) {
        constexpr int N = 1e5;
        vb v(N * 2 + 1);
        size_t ans = 0;
        for(auto &i: c)
            if(!v[i + N]) {
                ans++;
                v[i + N] = true;
            }
        return min(c.size() / 2, ans);
    }
};