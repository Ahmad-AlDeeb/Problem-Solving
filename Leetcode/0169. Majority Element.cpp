class Solution {
public:
	int majorityElement(vector<int>& nums) {
        int counter{};
        int majorElement{};

        for(auto num : nums) {
            if(counter == 0) {
                majorElement = num;
            }
            counter += (num == majorElement) ? 1 : -1;
        }

        return majorElement;
    }
};
