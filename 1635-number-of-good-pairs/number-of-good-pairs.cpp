class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int, int> numFreqMp;
        int answer = 0;
        for(auto num : nums){
            answer += numFreqMp[num];
            numFreqMp[num]++;
        }
        return answer;

    }
};