class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,bool> m;
        for(auto jewel : jewels) {
            m[jewel] = true;
        }

        int answer{};
        for(auto stone : stones) {
            if(m[stone])
                answer++;
        }

        return answer;
    }
};
