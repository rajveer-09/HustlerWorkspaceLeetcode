class OrderedStream {
public:

    vector<string> res;
    int ptr = 0;
    OrderedStream(int n) {
        res.resize(n, " ");
    }
    
    vector<string> insert(int idKey, string value) {
        res[idKey-1] = value;
        vector<string> s = {};

        while (ptr < res.size() && res[ptr] != " ")
            s.push_back(res[ptr++]);

        return s;
    }
};