class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        //edge direction: b → a
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for(int ngh : adj[node]) {
                indegree[ngh]--;
                if(indegree[ngh] == 0) {
                    q.push(ngh);
                }
            }
        }

        return count == n;
    }
};

/*
a ->b  | x -> y  | p -> q

kya koi sequence possible hai(of a,b, x, y, p, q) jisse ye course complete ho paaye
Yes possible hai agr ki cyclic dependecy na ho | koi loop na ho
=> DAG ho | Toposort possible ho
*/

// class Solution {
// public:
//     bool dfsCycleCheck(int course, const vector<vector<int>>& graph, vector<int>& state) {
//         if (state[course] == 1) return false; // cycle detected
//         if (state[course] == 2) return true;  // already visited/safe

//         state[course] = 1; // mark as visiting

//         for (int neighbor : graph[course]) {
//             if (!dfsCycleCheck(neighbor, graph, state)) return false;
//         }

//         state[course] = 2; // mark as visited

//         return true;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph(numCourses);
//         for (auto& p : prerequisites){
//             graph[p[1]].push_back(p[0]);
//         }
            
//         vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
//         for (int i = 0; i < numCourses; ++i){
//             if (!dfsCycleCheck(i, graph, state)) return false;
//         }
            
//         return true;
//     }
// };
