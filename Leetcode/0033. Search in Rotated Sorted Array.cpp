class Solution {
    int findPivot(vector<int>& nums) {
        int left{1}, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[mid - 1]) {
                return mid;
            }
            else if(nums[mid] > nums.back()) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return 0;
    }

    int subArrayBinarySearch(vector<int>& nums, int left, int right, int target) {
        int answer = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            cout << mid << endl;
            if(nums[mid] == target) {
                answer = mid;
                break;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }

public:
    int search(vector<int>& nums, int target) {
        int k = findPivot(nums);
        if(!k) {
            if(!binary_search(nums.begin(), nums.end(), target)) {
                return -1;
            }
            return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        }

        int leftResult   = subArrayBinarySearch(nums, 0, k - 1, target);
        int rightResult = subArrayBinarySearch(nums, k, nums.size() - 1, target);
        if(leftResult != -1) {
            return leftResult;
        }
        if(rightResult != -1) {
            return rightResult;
        }
        return -1;
    }
};
