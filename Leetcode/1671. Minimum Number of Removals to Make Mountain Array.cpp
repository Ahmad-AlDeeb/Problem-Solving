int const N = 1000 + 1;

class Solution {
    vector<int> numbers;
    int memoryLIS[N], memoryLDS[N];
    int n;

int LIS(int cur) {
    int &answer = memoryLIS[cur];
    if(answer != -1) {
        return answer;
    }

    answer = 0;
    for(int prev{cur - 1}; prev >= 0; prev--) {
        if(numbers[prev] < numbers[cur]) {
            answer = max(answer, LIS(prev));
        }
    }
    return ++answer;
}

int LDS(int cur) {
    int &answer = memoryLDS[cur];
    if(answer != -1) {
        return answer;
    }

    answer = 0;
    for(int nex{cur + 1}; nex < n; nex++) {
        if(numbers[nex] < numbers[cur]) {
            answer = max(answer, LDS(nex));
        }
    }
    return ++answer;
}

public:
    int minimumMountainRemovals(vector<int>& nums) {
        numbers = nums;
        n = numbers.size();
        memset(memoryLIS, -1, sizeof(memoryLIS));
        memset(memoryLDS, -1, sizeof(memoryLDS));

        int answer{};
        for(int peakIndex{}; peakIndex < n; ++peakIndex) {
            int lis = LIS(peakIndex);
            int lds = LDS(peakIndex);
            if(lis == 1 || lds == 1) {
                continue;
            }
            
            int currentAnswer = lis + lds - 1;
            answer = max(answer, currentAnswer);
        }
        return n - answer;
    }
};
