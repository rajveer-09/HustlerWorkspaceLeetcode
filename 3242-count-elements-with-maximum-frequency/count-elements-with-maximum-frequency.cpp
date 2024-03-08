class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]{0};
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int max_freq=freq[0];
        int count=0;
        for(int i=1;i<=100;i++){
            if(freq[i]>max_freq) max_freq=freq[i];
        }
        for(int i=1;i<=100;i++){
            if(freq[i]==max_freq) count+= max_freq;
        }
        return count;
    }
};