class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int keyIndex = 0;
    if (ruleKey == "color") {
        keyIndex = 1;
    } else if (ruleKey == "name") {
        keyIndex = 2;
    }
    
    return std::count_if(items.begin(), items.end(), [&](const auto& item) {
        return item[keyIndex] == ruleValue;
        });
    }
};