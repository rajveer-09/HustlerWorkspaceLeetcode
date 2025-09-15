// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
//     }
// };


class Solution {
public:
    bool dfsCycleCheck(int course, const vector<vector<int>>& graph, vector<int>& state) {
        if (state[course] == 1) return false; // cycle detected
        if (state[course] == 2) return true;  // already visited/safe

        state[course] = 1; // mark as visiting

        for (int neighbor : graph[course]) {
            if (!dfsCycleCheck(neighbor, graph, state)) return false;
        }

        state[course] = 2; // mark as visited

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
            
        vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        for (int i = 0; i < numCourses; ++i){
            if (!dfsCycleCheck(i, graph, state)) return false;
        }
            
        return true;
    }
};
