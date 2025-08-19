class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);

        int maxi = 0;

        for(int i = 0; i < edges.size(); i++){
            score[edges[i]] += i;

            if(score[edges[i]] > score[maxi]){
                maxi = edges[i];
            }
            else if(score[edges[i]] == score[maxi]){
                maxi = min(maxi, edges[i]);
            }
        }

        return maxi;
    }
};