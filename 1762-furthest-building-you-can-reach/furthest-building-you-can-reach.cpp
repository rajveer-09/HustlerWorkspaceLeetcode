class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < heights.size() - 1; i++){
            int gap = heights[i + 1] - heights[i];

            if(gap > 0){
                pq.push(gap);

                if(pq.size() > ladders){
                    bricks -= pq.top();
                    pq.pop();
                }
                // Not enough bricks? Stop here
                if(bricks < 0) return i;
            }
        }

        return heights.size() - 1;
    }
};
/*
ham ladders ka use krke jarhe hain....but agr kahi ladder khtm hogya toh..
ham assume krenge ki abi tk ke smaller jumps hamne bricks se kra

*/