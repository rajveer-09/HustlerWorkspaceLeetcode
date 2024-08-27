constexpr int MAX = 1000100;

int spf[MAX], primes[MAX], leftCnt[MAX], rightCnt[MAX];

// Function to initialize the smallest prime factor for each number up to MAX
void initPrimeFactors() {
    int primeIdx = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            primes[primeIdx++] = i;
        }
        for (int j = 0; i * primes[j] < MAX; ++j) {
            spf[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

class Solution {
public:
    int findValidSplit(std::vector<int>& nums) {
        // Initialize prime factors only once
        static bool init = []() {
            initPrimeFactors();
            return true;
        }();

        int n = nums.size();
        int maxElem = *std::max_element(nums.begin(), nums.end());

        // Reset left and right counts for prime factors
        std::fill(leftCnt, leftCnt + maxElem + 1, 0);
        std::fill(rightCnt, rightCnt + maxElem + 1, 0);

        // Populate the rightCnt array with prime factor counts from the entire array
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val > 1) {
                int prime = spf[val];
                while (val % prime == 0) {
                    val /= prime;
                    ++rightCnt[prime];
                }
            }
        }

        int activeCnt = 0;

        // Iterate through the array to find a valid split
        for (int i = 0; i < n - 1; ++i) {  // No need to check the last element
            int val = nums[i];
            while (val > 1) {
                int prime = spf[val];
                while (val % prime == 0) {
                    val /= prime;
                    ++leftCnt[prime];
                    --rightCnt[prime];

                    // Track the number of active prime factors on both sides
                    if (leftCnt[prime] == 1 && rightCnt[prime] > 0) {
                        ++activeCnt;
                    } else if (leftCnt[prime] > 1 && rightCnt[prime] == 0) {
                        --activeCnt;
                    }
                }
            }

            // If there are no common prime factors, return the split index
            if (activeCnt == 0) {
                return i;
            }
        }

        // No valid split found
        return -1;
    }
};