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

        // Split the paragraph into words
        string word;
        istringstream stream(paragraph);
        while (stream >> word) {
            if (bannedWords.find(word) == bannedWords.end()) {
                wordCount[word]++;
            }
        }

        // Find the word with the maximum frequency
        string mostCommon;
        int maxCount = 0;
        for (const auto& [word, count] : wordCount) {
            if (count > maxCount) {
                maxCount = count;
                mostCommon = word;
            }
        }

        return mostCommon;
    }
};
