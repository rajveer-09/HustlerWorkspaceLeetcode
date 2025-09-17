class Solution {
public:
    bool check(int arr[]){
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int freq[26]{0};

        vector<int> ans;

        for(char it : p) freq[it - 'a']++;

        int st = 0;

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']--;

            if((i - st + 1) == p.size()){
                if(check(freq)){
                    ans.push_back(st);
                }

                freq[s[st] - 'a']++;
                st++;
            }

        }

        return ans;
    }
};