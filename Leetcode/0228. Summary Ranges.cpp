class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if(nums.empty()) {
            return ranges;
        }
        
        string curRange {to_string(nums.front())};
        curRange += "->";
        int startIndex{};

        for(int i{1}; i < nums.size(); ++i) {
            if(nums[i] - (long) nums[i - 1] != 1) {
                if(i - 1 == startIndex) {
                    curRange.pop_back();
                    curRange.pop_back();
                }
                else {
                    curRange += to_string(nums[i - 1]);
                }
                ranges.push_back(curRange);

                curRange = to_string(nums[i]);
                curRange += "->";
                startIndex = i;
            }
        }

        if(nums.size() - 1 == startIndex) {
            curRange.pop_back();
            curRange.pop_back();
        }
        else {
            curRange += to_string(nums.back());
        }
        ranges.push_back(curRange);

        return ranges;
    }
};
