class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
        int i = 0, j = 0;
        int n = Student.size(), m = Cookie.size();

        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        while(i < n && j < m){
            if(Cookie[j] >= Student[i]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return i;
    }
};