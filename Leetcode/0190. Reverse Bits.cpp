class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans{};
        for(int i{}; i<32; i++) {
            int leastSignificantBit = n&1;
            n >>= 1;
            ans <<= 1;
            ans |= leastSignificantBit;
        }
        return ans;
    }
};
