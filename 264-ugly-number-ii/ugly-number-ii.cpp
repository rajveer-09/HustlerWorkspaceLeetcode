class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};  // Initialize the primes array
        vector<int> indices = {0, 0, 0}; // Initialize indices for multiples of 2, 3, 5
        vector<int> uglyArr(1, 1);       // Initialize the ugly number array with 1

        for (int i = 1; i < n; ++i) {
            // Calculate the next possible ugly numbers
            vector<int> next_uglies = {
                uglyArr[indices[0]] * primes[0],
                uglyArr[indices[1]] * primes[1],
                uglyArr[indices[2]] * primes[2]
            };
            int min_value = *min_element(next_uglies.begin(), next_uglies.end()); // Find the smallest value
            uglyArr.push_back(min_value); // Append the smallest value to uglyArr

            // Update indices for primes that generated the current min_value
            for (int j = 0; j < 3; ++j) {
                if (next_uglies[j] == min_value) {
                    ++indices[j];
                }
            }
        }

        return uglyArr[n - 1];
    }
};