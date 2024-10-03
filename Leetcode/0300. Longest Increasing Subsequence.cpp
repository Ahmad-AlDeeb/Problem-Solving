// (Take or Leave) Pattern O(n^2) | O(n^2)
class Solution {
    vector<vector<int>> memory;
    int LIS(int i, int prev_i, vector<int>& nums) {
        if(i == nums.size()) {
            return 0;
        }

        int &state = memory[i][prev_i];
        if(state != -1) {
            return state;
        }
        
        int takeOption{};
        if(prev_i == 2500 || nums[prev_i] < nums[i]) {
            takeOption = 1 + LIS(i + 1, i, nums);
        }
        
        int leaveOption = LIS(i + 1, prev_i, nums);

        return state = max(takeOption, leaveOption);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memory.resize(2500, vector<int>(2500 + 1, -1));
        return LIS(0, 2500, nums);
    }
};

// (Take next mask 1) Using windows with starting index O(n^2) | O(n) | More stack friendly
// Source: Dr Mostafa Saad Algorithm 2 course : https://www.udemy.com/course/skills-algorithms-cpp2/learn/lecture/31594142
class Solution {
    vector<int> memory;
    int LIS(int i, vector<int>& nums) {
        int &answer = memory[i];
        if(answer != -1) {
            return answer;
        }

        for(int j{i + 1}; j < nums.size(); ++j) {
            if(nums[i] < nums[j]) {
                answer = max(answer,LIS(j, nums));
            }
        }
        answer++;
        return answer;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memory.resize(2500, -1);
        
        int answer{};
        for(int i{}; i < nums.size(); ++i) {
            answer = max(answer, 1 + LIS(i, nums));
        }
        return answer;
    }
};

// Same as before but better written + Build output function
int MAX_SIZE = 2500 + 1;

class Solution {
    vector<int> cache;
    vector<int> nums;

    int LIS(int i) {
        int &count = cache[i];
        if(count != -1) {
            return count;
        }
        count = 0;

        for(int j{i + 1}; j < nums.size(); ++j) {
            if(nums[i] < nums[j]) {
                count = max(count, LIS(j));
            }
        }
        count++;
        return count;
    }

    void printLIS(int i) {
        int optimal = LIS(i) - 1;

        for(int j{i + 1}; j < nums.size(); ++j) {
            if(nums[i] < nums[j]) {
                int choice = LIS(j);
                if(optimal == choice) {
                    cout << nums[j] << " ";
                    printLIS(j);
                    break;
                }
            }
        }
    }
public:
    int lengthOfLIS(vector<int>& nums_) {
        cache.resize(MAX_SIZE, -1);
        nums = nums_;

        nums.insert(nums.begin(), -INT_MAX);
        printLIS(0);
        return LIS(0) - 1;
    }
};
