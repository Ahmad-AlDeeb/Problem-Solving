class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;

    vector<set<int>> CC;
    vector<multiset<char>> values;

    void dfs(int node, string &s, set<int> &cc, multiset<char> &value) {
        if(vis.count(node)) {
            return;
        }
        vis.insert(node);

        cc.insert(node);
        value.insert(s[node]);

        for(auto child : adj[node])
            dfs(child, s, cc, value);
    }

    void construct_string(string &s) {
        int n = CC.size();
        for(int i{}; i < n; ++i) {
            auto it1 = CC[i].begin();
            auto it2 = values[i].begin();

            for(; it1 != CC[i].end(); ++it1, ++it2) {
                s[*it1] = *it2;
            }
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto p : pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        for(int i{}; i < s.size(); ++i) {
            set<int> cc;
            multiset<char> value;

            dfs(i, s, cc, value);

            CC.push_back(cc);
            values.push_back(value);
        }
        
        construct_string(s);
        return s;
    }
};
