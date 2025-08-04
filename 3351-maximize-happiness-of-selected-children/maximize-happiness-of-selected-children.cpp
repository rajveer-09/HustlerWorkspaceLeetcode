class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long ans = 0;

        int cnt = 0;

        for(int it : happiness){
            if(it - cnt <= 0) break;
            
            ans += (it-cnt);
            cnt++;

            if(cnt == k) break;
        }

        return ans;
    }
};