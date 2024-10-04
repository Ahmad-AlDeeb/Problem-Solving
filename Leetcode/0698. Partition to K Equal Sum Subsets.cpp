class Solution {
    vector<int> partitions;
    vector<int> nums;
    vector<bool> visited;
    int n, k;
    int target;

    int getSum() {
        int sum{};
        for(auto num : nums)
            sum += num;
        return sum;
    }

    bool tryNums(int partitionIndex, int numsIndex) {
        if(partitionIndex >= k) {
            return true;
        }

        int &remain = partitions[partitionIndex];
        if(!remain) {
            return tryNums(partitionIndex + 1, 0);
        }
        if(numsIndex >= n) {
            return false;
        }

        if(!visited[numsIndex] && nums[numsIndex] <= remain) {
            remain -= nums[numsIndex];
            visited[numsIndex] = true;

            if(tryNums(partitionIndex, numsIndex + 1)) { // take option
                return true;
            }

            visited[numsIndex] = false;
            remain += nums[numsIndex];

            if(remain == target) {
                return false;
            }
        }

        return tryNums(partitionIndex, numsIndex + 1); // leave option
    }

public:
    bool canPartitionKSubsets(vector<int>& nums_, int k_) {
        nums = nums_;
        n = nums.size();
        int sum = getSum();
        visited.resize(n);
        k = k_;
        
        if(sum % k) {
            return false;
        }
        
        target = sum / k;
        partitions.resize(k, target);
        return tryNums(0, 0);
    }
};
