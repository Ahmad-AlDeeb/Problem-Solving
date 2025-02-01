class Solution {
public:
    int minPartitions(string n) {
        int maxDigit{};
        for(auto ch : n) {
            int dig = ch - '0';
            maxDigit = max(maxDigit, dig);
        }
        return maxDigit;
    }
};
