class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>smp;
        unordered_map<char,int>tmp;
        int cnt=0;
        for(auto a:s)smp[a]++;
        for(auto a:t)tmp[a]++;

        for (auto a : smp) {
    if (tmp.find(a.first) != tmp.end()) {
        if (smp[a.first] == tmp[a.first]) {
            cnt += smp[a.first];
        } else {
            cnt += min(smp[a.first], tmp[a.first]);
        }
    }
}

        return s.size()-cnt;
    }
};