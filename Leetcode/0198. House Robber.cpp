class Solution {
    vector<int> memory;
    vector<int> houses;
    int n;

    int getAnswer(int i) {
        if(i >= n) {
            return 0;
        }

        int &answer = memory[i];
        if(answer != -1) {
            return answer;
        }

        int takeOption = houses[i] + getAnswer(i + 2);
        int leaveOption = getAnswer(i + 1);
        return answer = max(takeOption, leaveOption);
    }

public:
    int rob(vector<int>& nums) {
        houses = nums;
        n = houses.size();
        memory.resize(n, -1);

        return getAnswer(0);
    }
};
