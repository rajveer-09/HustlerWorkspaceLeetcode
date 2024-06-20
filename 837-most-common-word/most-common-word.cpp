class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> wordCount;
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        
        // Convert paragraph to lowercase and replace punctuations with spaces
        for (char& c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }

        // Split the paragraph into words and count their frequencies
        int n = paragraph.size();
        string word;
        for (int i = 0; i < n; ++i) {
            if (paragraph[i] == ' ') {
                if (!word.empty() && bannedWords.find(word) == bannedWords.end()) {
                    wordCount[word]++;
                }
                word.clear();
            } else {
                word += paragraph[i];
            }
        }

        // Check the last word
        if (!word.empty() && bannedWords.find(word) == bannedWords.end()) {
            wordCount[word]++;
        }

        // Find the word with the maximum frequency
        string mostCommon;
        int maxCount = 0;
        for (const auto& entry : wordCount) {
            if (entry.second > maxCount) {
                maxCount = entry.second;
                mostCommon = entry.first;
            }
        }

        return mostCommon;
    }
};
