class Solution {
public:
    void solve(string& num, int target, string path, long long currentResult, long long prevNum, int index, vector<string>& result) {
        if (index == num.size()) {
            if (currentResult == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            if (i > index && num[index] == '0') {
                break;
            }

            string s = num.substr(index, i - index + 1);
            long long currentNum = stoll(s);

            if (index == 0) {
                solve(num, target, s, currentNum, currentNum, i + 1, result);
            } 
            else {
                solve(num, target, path + "+" + s, currentResult + currentNum, currentNum, i + 1, result);
                solve(num, target, path + "-" + s, currentResult - currentNum, -currentNum, i + 1, result);
                solve(num, target, path + "*" + s, currentResult - prevNum + prevNum * currentNum, prevNum * currentNum, i + 1, result);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) {
            return result;
        }
        
        solve(num, target, "", 0, 0, 0, result);
        return result;
    }
};