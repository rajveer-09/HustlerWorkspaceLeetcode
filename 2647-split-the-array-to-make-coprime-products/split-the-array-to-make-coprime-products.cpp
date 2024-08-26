class Solution {
public:
    vector<int> getPrimes(int n) {
        vector<int> ret;
        vector<bool> isPrime(n+5, true);
        for(int i=2; i<=(int)(sqrt(n)); i++) {
            if(isPrime[i]) for(int j=i*i; j<=n; j+=i) isPrime[j]=false;
        }

        for(int i=2; i<=n; i++) if(isPrime[i]) ret.push_back(i);

        return ret;
    }

    int findValidSplit(vector<int>& nums) {
        vector<int> primes = getPrimes(1000);
        int n = nums.size();

        map<int, pair<int,int>> memo1;
        for(int i=0; i<n; i++) {
            for(int p: primes) {
                if(nums[i] % p == 0) {
                    if(memo1.find(p) == memo1.end()) memo1[p] = make_pair(n,-1);

                    auto& [first, last] = memo1[p];

                    first = min(first, i);
                    last = max(last, i);

                    while(nums[i] % p == 0) nums[i] /= p;
                }
            }

            if(nums[i] > 1) {
                if(memo1.find(nums[i]) == memo1.end()) memo1[nums[i]] = make_pair(n,-1);

                    auto& [first, last] = memo1[nums[i]];

                    first = min(first, i);
                    last = max(last, i);
            }
        }

        map<int,int> memo;

        for(const auto& [_, idxs]: memo1) {
            memo[idxs.first]+=1;
            memo[idxs.second]-=1;
        }
        
        int c=0;
        for(int i=0; i<=n-2; i++) {
            c += memo[i];

            if(c == 0) return i;
        }

        return -1;
    }
};