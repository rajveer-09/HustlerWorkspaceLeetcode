static const int _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
class UnionFindSet
{
public:
    UnionFindSet(int n) : _parent(n), _size(n)
    {
        for(int i = 0; i < n; ++i)
        {
            _parent[i] = i;
            _size[i] = 1;
        }
    }
    bool Union(int x, int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);

        if(rootX == rootY)
        {
            return true;
        }

        if(rootX != rootY)
        {
            if(_size[rootY] < _size[rootX])
            {
                _parent[rootY] = rootX;
                _size[rootX] += _size[rootY];
            }
            else
            {
                _parent[rootX] = rootY;
                _size[rootY] += _size[rootX];

            }
        }

        return false;
    }

    int Find(int x)
    {
        if(_parent[x] == x)
        {
            return x;
        }

        return _parent[x] = Find(_parent[x]);
    }

    int getGroup()
    {
        int g = 0;

        for(int i = 0; i < _parent.size(); ++i)
        {
            if(i == _parent[i])
            {
                ++g;
            }
        }

        return g;
    }

    vector<int> getGroupVec()
    {
        vector<int> res;

        for(int i = 0; i < _parent.size(); ++i)
        {
            if(_parent[0] == _parent[i])
            {
                res.emplace_back(i);
            }
        }

        return res;
    }

    void set(int num)
    {
        //cout << num << endl;
        _parent[num] = num;
        _size[num] = 1;
    }

private:
    vector<int> _parent;
    vector<int> _size;
};
class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        sort(meetings.begin(), meetings.end(), [&](vector<int> &a, vector<int> &b)
            {
                return a[2] < b[2];
            });
        //for(auto& meet : meetings){
        //    cout << meet[0] << " " << meet[1] << " " << meet[2] << endl;
        //}

        vector<int> res(1, 0);
        UnionFindSet ufs(n);
        ufs.Union(0, firstPerson);
        int m = meetings.size();

        for(int i = 0; i < m; ++i)
        {
            int time = meetings[i][2];
            ufs.Union(meetings[i][0], meetings[i][1]);

            if(i == m - 1 || meetings[i][2] != meetings[i + 1][2])
            {
                int j = i;

                while(j >= 0 && meetings[j][2] == time)
                {
                    if(ufs.Find(meetings[j][1]) != ufs.Find(0))
                    {
                        ufs.set(meetings[j][1]);
                    }

                    if(ufs.Find(meetings[j][0]) != ufs.Find(0))
                    {
                        ufs.set(meetings[j][0]);
                    }

                    --j;
                }
            }
        }

        //cout << "------------" << endl;
        return ufs.getGroupVec();
    }
};