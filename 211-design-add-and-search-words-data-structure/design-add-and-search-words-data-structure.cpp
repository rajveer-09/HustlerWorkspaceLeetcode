class TrieNode{
public:
    bool terminal;
    TrieNode* children[26];

    TrieNode(){
        terminal = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool search_recursive(string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->terminal;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && search_recursive(word, index + 1, node->children[i])) {
                    return true;
                }
            }
        } else {
            int idx = ch - 'a';
            if (node->children[idx] && search_recursive(word, index + 1, node->children[idx])) {
                return true;
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* crawler = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx] == NULL){
                crawler->children[idx] = new TrieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->terminal = true;
    }
    
    bool search(string word) {
        return search_recursive(word, 0, root);
    }
};