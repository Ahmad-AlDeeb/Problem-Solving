int const MAX = 500 + 1;

class Solution {
    int memory[MAX];
    vector<int> vec;
    int n, limit;
    
    int getSubValue(int start, int end) {
        int maxValue = *max_element(vec.begin() + start, vec.begin() + end);
        int count = end - start;
        return maxValue * count;
    }

    int getSum(int i) {
        if(i >= n) {
            return 0;
        }

        int &answer = memory[i];
        if(answer != -1) {
            return answer;
        }

        for(int j{i + 1}; j <= i + limit && j <= n; ++j) {
            answer = max(answer, getSubValue(i, j) + getSum(j));
        }
        return answer;
    }


public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(memory, -1, sizeof(memory));
        vec = arr;
        n = arr.size();
        limit = k;

        return getSum(0);
    }
};
