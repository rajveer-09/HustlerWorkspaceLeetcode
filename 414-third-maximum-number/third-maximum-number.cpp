#pragma GCC target("tune=native")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Os")
// Code here is optimized for size

static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int first =LONG_MIN;
        long long int second =LONG_MIN;
        long long int third =LONG_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=third || nums[i]==second || nums[i]==first)
                continue;
            third=nums[i];
            if(third>second) swap(third,second);
            if(second>first) swap(second,first);
        }
        if(third==LONG_MIN) return first;
        else return third;
    }
};