class Solution {
    string str1, str2;
    vector<vector<int>> memory;

    int LCS(int i, int j) {
        if(i == str1.size() || j == str2.size()) {
            return 0;
        }

        int &answer = memory[i][j];
        if(answer != -1) {
            return answer;
        }

        if(str1[i] == str2[j]) {
            return answer = 1 + LCS(i+1, j+1);
        }

        int leaveFirst = LCS(i+1, j);
        int leaveSecond = LCS(i, j+1);
        return answer = max(leaveFirst, leaveSecond);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        memory.resize(1000, vector<int>(1000, -1));
        str1 = text1;
        str2 = text2;
    
        return LCS(0, 0);
    }
};
