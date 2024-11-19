class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans = 0;
        int st = 0;
        int arr[2]{0};

        for(int ed = 0; ed < s.size(); ed++){
            if(s[ed] == 'T') arr[0]++;
            else arr[1]++;

            if(arr[0] <= k){
                ans = max(ans, ed - st + 1);
            }
            if(arr[1] <= k){
                ans = max(ans, ed - st + 1);
            }
            if(arr[1] > k && arr[0] > k){
                if(s[st] == 'T') arr[0]--;
                else arr[1]--;
                st++;
            }
        }

        return ans;
    }
};