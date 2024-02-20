class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (letters[mid] <= target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        // If start exceeds the array size, it means we need to wrap around to the beginning
        return letters[start % letters.size()];
    }
};