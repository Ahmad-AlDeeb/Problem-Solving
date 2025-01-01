class Solution {
    unordered_map<int, int> answer;

    vector<int> getNge(vector<int>& nums) {
        int size = nums.size();
        vector<int> nge(size, -1);

        stack<int> bigNumIdx;

        for(int i{}; i < size; ++i) {
            while(!bigNumIdx.empty() && nums[bigNumIdx.top()] < nums[i]) {
                nge[bigNumIdx.top()] = nums[i];
                bigNumIdx.pop();
            }
            bigNumIdx.push(i);
        }

        return nge;
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ngeNums2 = getNge(nums2);
        for(int i{}; i < nums2.size(); ++i) {
            answer[nums2[i]] = ngeNums2[i];
        }
        
        int size1 = nums1.size();
        
        vector<int> ngeNums1(size1);
        for(int i{}; i < size1; ++i) {
            ngeNums1[i] = answer[nums1[i]];
        }
        return ngeNums1;
    }
};
