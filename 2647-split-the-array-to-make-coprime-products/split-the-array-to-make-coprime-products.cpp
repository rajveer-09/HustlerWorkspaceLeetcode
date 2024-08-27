// class Solution {
// public:
//     int findValidSplit(vector<int>& nums) {
//         long long n = nums.size();
//         for (int i = 0; i <= n - 2; i++) {
//             long long u = 1, v = 1;
//             for (int j = 0; j <= i; j++) {
//                 u *= nums[j];
//             }
//             for (int k = i + 1; k < n; k++) {
//                 v *= nums[k];
//             }
//             if (__gcd(u, v) == 1) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
// #define f first
// #define s second
// class Primes {
//   private:
//     int n;
//   public:
//     vector<int> isPrime;
//     vector<int> primeFactor;
//     Primes (int n) {
//       isPrime.resize(n + 1, 1);
//       primeFactor.resize(n + 1);
//       int i = 2;
//       isPrime[0] = isPrime[1] = false;
//       while(i * i <= n) {
//         if (isPrime[i]) {
//           for (int j = i * i; j <= n; j += i) {
//             isPrime[j] = false;
//             primeFactor[j] = i;
//           }
//         }
//         i++;
//       }
//       for(int i = 2; i <= n; i++) {
//         if (!isPrime[i]) continue;
//         primeFactor[i] = i;
//       }
//     }
// };

// class Solution {
// public:
//     int findValidSplit(vector<int>& nums) {
//         int maxEle = *max_element(nums.begin(), nums.end());
//         Primes p(maxEle);
//         int n = nums.size();
//         map<int, pair<int, int>> pos;
//         for (int i = 0; i < n; i++) {
//             int val = nums[i];
//             while (val != 1) {
//                 int pf = p.primeFactor[val];
//                 //storing start & end positions of a prime
//                 if (pos.find(pf) == pos.end()) pos[pf] = {i, i};
//                 else pos[pf].s = i;
//                 while (val % pf == 0) {
//                     val /= pf;
//                 }
//             }
//         }
//         vector<int> isNotPossible(n, 0);
//         for (auto p: pos) {
//             // making sure split is not possible between start and end
//             isNotPossible[p.s.f] += 1;
//             isNotPossible[p.s.s] += -1;
//         }
//         for (int i = 1; i < n; i++) {
//             isNotPossible[i] += isNotPossible[i - 1];
//         }
//         for (int i = 0; i < n - 1; i++) if (!isNotPossible[i]) return i;
//         return -1;
//     }
// };











constexpr int MAX = 1000100;

int a[MAX], p[MAX], l[MAX], r[MAX];

void Prime() {
  int n = 0;
  for (int i = 2; i < MAX; ++i) {
    if (!a[i]) {
      a[i] = i;
      p[n++] = i;
    }
    for (int j = 0; i * p[j] < MAX; ++j) {
      a[i * p[j]] = p[j];
      if (i % p[j] == 0) {
        break;
      }
    }
  }
}

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
      static bool init = []() {
        Prime();
        return true;
      }();

      int n = nums.size(), m = *std::max_element(nums.begin(), nums.end());
      std::fill(l, l + m + 1, 0);
      std::fill(r, r + m + 1, 0);
      for (int i = 0; i < n; ++i) {
        for (int x = nums[i]; x > 1; ) {
          for (int d = a[x]; a[x] == d; x /= d) {
            ++r[d];
          }
        }
      }
      int cnt = 0;
      for (int i = 0; i < n - 1; ++i) {
        for (int x = nums[i]; x > 1; ) {
          for (int d = a[x]; a[x] == d; x /= d) {
            ++l[d];
            --r[d];
            if (l[d] == 1 && r[d] > 0) {
              ++cnt;
            } else if (l[d] > 1 && r[d] == 0) {
              --cnt;
            }
          }
        }
        if (cnt == 0) {
          return i;
        }
      }
      return -1;
    }
};