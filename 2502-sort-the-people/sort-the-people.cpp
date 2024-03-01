class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        size_t n = names.size();
        
        for (size_t i{0}; i < n - 1; i++) 
        {
            int maxIndex = i;
            
            for (size_t j = i + 1; j < n; j++)
            {
                if (heights[j] > heights[maxIndex])
                {
                    maxIndex = j;
                }
            }
            
            swap(names[i], names[maxIndex]);
            swap(heights[i], heights[maxIndex]);
        }
        
        return names;
    }
};