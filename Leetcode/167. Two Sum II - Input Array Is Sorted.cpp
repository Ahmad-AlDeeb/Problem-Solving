class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum = numbers.front() + numbers.back();
        
        int i{}, j = numbers.size()-1;
        while(sum != target) {
            if(sum < target) {
                i++;
            }
            else if(sum > target) {
                j--;
            }
            sum = numbers[i] + numbers[j];
        }
        vector<int> answer{i+1, j+1};
        return answer;
    }
};
