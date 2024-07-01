class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int maxsum = 0;
        int n=points.size();
        for(int i=0;i<n;i++)
        { for(int j=0;j<n;j++)
            {
                if(i==j || points[i][0]>points[j][0] || points[i][1]<points[j][1])
                {
                    continue;}
                int p = 0;
                for(;p<n;p++)
                { if(p==i || p==j)
                    {
                        continue;
                    }
                    if(points[p][1] <= points[i][1] && points[p][1] >= points[j][1] &&
                     points[p][0] <= points[j][0] && points[p][0] >= points[i][0]) {
                        break;
                    } }
                if(p==n)
                {
                    maxsum++;
                }}
        }
        return maxsum;
    }
};