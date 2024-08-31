class Solution {
public:
    int longestPalindrome(string s) {
        int frequency[58];
        for(char character : s)
            frequency[character-'A']++;

        int ans{};
        bool is_odd{false};
        for(int i{}; i<58; i++) {
            int count = frequency[i];
            if(count % 2 == 0) {
                ans += count;
            }
            else {
                ans  += count-1;
                is_odd = true;
            } 
        }
        return ans + is_odd;
    }
};
