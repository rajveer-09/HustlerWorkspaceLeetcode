class Solution{
public:
    vector<int> asteroidCollision(vector<int> &asteroid){
        int n = asteroid.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(asteroid[i] > 0) {
                ans.push_back(asteroid[i]);
                continue;
            }
            
            while(ans.size() > 0 && ans.back() > 0){
                if(ans.back() < abs(asteroid[i])){
                    ans.pop_back();
                }
                else{
                    break;
                }
            }
            
            if (!ans.size() || ans.back() < 0){
                ans.push_back(asteroid[i]);
            }
            else if(ans.back() == abs(asteroid[i])){
                ans.pop_back();
            }
            
        }

        return ans;
    }
};

/*
collisions sirf ek case me hoga i.e [pos, neg] -> and no other order
[neg, pos] X
[neg, neg] X
[pos, pos] X
*/