int const MAX_SIZE = 10000 + 5;

class Solution {
    int mem[MAX_SIZE];
    int size;

    void ini(vector<int>& nums) {
        memset(mem, -1, sizeof(mem));
        size = nums.size();
    }

    int getAnswer(int index, vector<int>& nums) {
        if(index >= size - 1) {
            return 0;
        }

        int &answer = mem[index];
        if(answer != -1) {
            return answer;
        }
        answer = MAX_SIZE;
        
        for(int jumps{1}; jumps <= nums[index]; ++jumps) {
            answer = min(answer, 1 + getAnswer(index + jumps, nums));
        }

        return answer;
    }

public:
    int jump(vector<int>& nums) {
        ini(nums);
        return getAnswer(0, nums);
    }
};
