class Solution {
public:
    int dfs(int id, unordered_map<int, Employee*>& mpp){
        int ans = mpp[id]->importance;

        for(int sub : mpp[id]->subordinates){
            ans += dfs(sub, mpp);
        }

        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mpp;

        for(auto emp : employees){
            mpp[emp->id] = emp;
        }
        
        return dfs(id, mpp);
    }
};