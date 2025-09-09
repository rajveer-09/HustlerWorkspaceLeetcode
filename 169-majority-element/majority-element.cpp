class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = 0;

        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    bitCount++;
                }
            }

            if (bitCount > n / 2) {
                majority |= (1 << i);
            }
        }

        return majority;
    }
};


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int el = -1;
//         int cnt = 0;

//         for(int i = 0; i < nums.size(); i++){
//             if(cnt == 0){
//                 el = nums[i];
//                 cnt++;
//             }
//             else if(nums[i] != el) cnt--;
//             else cnt++;
//         }

//         return el;
//     }
// };