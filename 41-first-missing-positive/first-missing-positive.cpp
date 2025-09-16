class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val - 1] > 0) {
                    nums[val - 1] *= -1;
                } else if (nums[val - 1] == 0) {
                    nums[val - 1] = -1 * (n + 1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] >= 0) {
                return i;
            }
        }

        return n + 1;
    }
};

/*

<-- BRUTE -->

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        while (true) {
            bool flag = true;
            for (int& num : nums) {
                if (missing == num) {
                    flag = false;
                    break;
                }
            }
            if (flag) return missing;
            missing++;
        }
    }
};


<-- BETTER -->

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1;
        for (int num : nums) {
            if (num > 0 && missing == num) {
                missing++;
            }
        }
        return missing;
    }
};

<-- OPTIMAL1 -->
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);

        for (int num : nums) {
            if (num > 0 && num <= n) {
                seen[num - 1] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

<-- MOST OPTIMAL -->

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val - 1] > 0) {
                    nums[val - 1] *= -1;
                } else if (nums[val - 1] == 0) {
                    nums[val - 1] = -1 * (n + 1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] >= 0) {
                return i;
            }
        }

        return n + 1;
    }
};

<-- CYCLIC SORT -->

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] <= 0 || nums[i] > n) {
                i++;
                continue;
            }
            int index = nums[i] - 1;
            if (nums[i] != nums[index]) {
                swap(nums[i], nums[index]);
            } else {
                i++;
            }
        }

        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

*/