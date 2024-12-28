class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> sc;
    int res = 0;

    for (const auto& op : ops) {
        if (op == "C") {
            if (!sc.empty()) {
                sc.pop_back();
            }
        } else if (op == "D") {
            if (!sc.empty()) {
                sc.push_back(sc.back() * 2);
            }
        } else if (op == "+") {
            if (sc.size() >= 2) {
                sc.push_back(sc[sc.size() - 1] + sc[sc.size() - 2]);
            }
        } else {
            sc.push_back(stoi(op));
        }
    }

    for (const auto& s : sc) {
        res += s;
    }

    return res;
    }
};