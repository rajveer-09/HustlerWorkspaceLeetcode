class TrieNode{
public:
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(){
        isTerminal = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }

};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;

        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(crawler->children[idx] == NULL){
                crawler->children[idx] = new TrieNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }

        return crawler->isTerminal == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';

            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */