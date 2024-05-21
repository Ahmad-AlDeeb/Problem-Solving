class Solution {
public:
    int hammingWeight(int n) {
        int answer{};
        while(n) {
            if(n & 1) answer++;
            n >>= 1;
        }
        return answer;
    }
};
