class Solution {
    string buildString(vector<string>& word) {
        string outputString;
        for(auto str : word) {
            outputString += str;
        }
        return outputString;
    }

public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        str1 = buildString(word1);
        str2 = buildString(word2);
        return str1 == str2;
    }
};
