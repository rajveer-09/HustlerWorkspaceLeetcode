class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> bucket(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            bucket[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = bucket.size() - 1; i > 0; --i) {
            for (int n : bucket[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};


/*

<-- BRUTE -->
Hash Map + Sorting (O(n log n))

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    vector<pair<int,int>> arr(freq.begin(), freq.end());
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });

    vector<int> ans;
    for (int i = 0; i < k; i++) ans.push_back(arr[i].first);
    return ans;
}

<-- BETTER -->
Heap (O(n log k))

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

    for (auto &p : freq) {
        minHeap.push({p.second, p.first});
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> ans;
    while (!minHeap.empty()) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}


<-- BEST -->
Bucket Sort (O(n))

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    int nSize = nums.size();
    vector<vector<int>> bucket(nSize + 1);

    for (auto &p : freq) {
        bucket[p.second].push_back(p.first);
    }

    vector<int> ans;
    for (int i = nSize; i >= 0 && ans.size() < k; i--) {
        for (int num : bucket[i]) {
            ans.push_back(num);
            if (ans.size() == k) break;
        }
    }
    return ans;
}


*/