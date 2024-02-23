class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int m=0,j=-1,len=arr.size()-1;
        for(int i=len;i>=0;i--)
        {
            m=max(arr[i],m);
            arr[i]=j;
            j=m;
        }
        return arr;
    }
};

static const int _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();