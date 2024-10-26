class Solution {
public:
    bool dfs(vector<int>& arr, int index, vector<bool>& visited) {
        // Base case: Check if we reached a zero
        if (arr[index] == 0) return true;

        // If already visited, return false
        if (visited[index]) return false;

        // Mark the index as visited
        visited[index] = true;

        // Jump left and right with boundary checks
        bool left = (index - arr[index] >= 0) && dfs(arr, index - arr[index], visited);
        bool right = (index + arr[index] < arr.size()) && dfs(arr, index + arr[index], visited);

        // Return true if either direction reaches zero
        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};
