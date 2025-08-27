class Solution {
public:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    string base = "http://tinyurl.com/";
    
    // Helper to generate a random 6-char key
    string getKey() {
        string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string key = "";
        for (int i = 0; i < 6; i++) {
            key += chars[rand() % chars.size()];
        }
        return key;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.count(longUrl)) {
            return base + longToShort[longUrl];
        }
        string key = getKey();
        while (shortToLong.count(key)) { // handle collisions
            key = getKey();
        }
        shortToLong[key] = longUrl;
        longToShort[longUrl] = key;
        return base + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(base.size());
        return shortToLong[key];
    }
};
/*
Character set size = 62 (26 lowercase + 26 uppercase + 10 digits).
For a key of length k:
Total keys = 62^\U0001d458
for k = 6 => 62^6 = 56,800,235,584 ≈ 56.8 billion unique keys
*/