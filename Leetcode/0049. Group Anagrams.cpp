class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(auto str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            groups[word].push_back(str);
        }

        vector<vector<string>> answer;
        for(auto p : groups)
            answer.push_back(p.second);
        return answer;
    }
};
