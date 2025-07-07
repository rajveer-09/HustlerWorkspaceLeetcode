class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        int cnt = 0;
        int ans = 0;
        int st = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) cnt++;

            if(cnt > k){
                if(nums[st] == 0){
                    cnt--;
                }

                st++;
                // har baar hm i++ kr rhe aur st++ v hoga jab tk cnt > k hai
                // isse mera answer update nhi hoga... baki pahla store ans hi rhega..
                // jab ek new valid codition me bad ans milega tb update hoga aur bada 
                // ans banega toh udpate hoga... 
            }

            ans = max(ans, i - st + 1);
            // best is is answer ko tabhi update kro..jab valid ans mile...
        }

        return ans;
    }
};