class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        
        for(int i=0;i<edges.size();i++) {
            auto it = edges[i];
            if(succProb[i] == 0)    continue;
            double val = 1.0/succProb[i];
            adj[it[0]].push_back({it[1],val});
            adj[it[1]].push_back({it[0],val});
        }
        
        vector<double> dis(n,1e7);
        priority_queue<pair<double,int>,
        vector<pair<double,int>>,
        greater<pair<double,int>>> pq;

        pq.push({1,start_node});
        dis[start_node] = 0;
        while(!pq.empty())
        {
            double distance = pq.top().first;
            int node = pq.top().second;
            if(node == end_node)    
                break;
            pq.pop();
            for(auto it : adj[node])    {
                if(distance*it.second < dis[it.first])
                {
                    dis[it.first] = distance*it.second;
                    pq.push({distance*it.second,it.first});
                }
            }
        }
        
        if(dis[end_node] == 1e7 || dis[end_node] == 0)    
            return 0;

        return (1.0/dis[end_node]);
    }
};