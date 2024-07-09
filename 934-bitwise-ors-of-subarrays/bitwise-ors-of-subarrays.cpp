class Solution 
{
    public:
    int subarrayBitwiseORs(vector<int> A) 
    {
        //res will contain all the possible subarray xors
        vector<int> res;
        int left = 0, right;
        
        //loop through all the elements of the array
        for (int a: A) 
        {
            right = res.size();
            res.push_back(a);
            
            //left will always be at the last element 
            for (int i = left; i < right; ++i) 
            {
                if (res.back() != (res[i] | a)) 
                    res.push_back(res[i] | a);
            }
            
            left = right;
        }
        
        return set(res.begin(), res.end()).size();
    }
};