class Solution {
public:
    int maximumLength(vector<int> &nums){
        int length[4] = {0};
        int Reqd[2] = {0 , 1}; //{Reqd for 01 , 10}
        for(int num : nums){
            int newNum = num % 2;
            length[newNum]++;
            if(newNum == Reqd[0]) length[2]++ , Reqd[0] ^= 1;
            if(newNum == Reqd[1]) length[3]++ , Reqd[1] ^= 1;
        }
        return *max_element(length , length + 4);
    }
};
