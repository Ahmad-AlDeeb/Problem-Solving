class Solution {
    vector<int> nums;
    unordered_set<int> selectedIndex;
    set<vector<int>> unique_perms;
    vector<int> permutation;
    int n;

    void permutate(int i) {
        if(i == n) {
            unique_perms.insert(permutation);
            return;
        }

        for(int j{}; j < n; ++j) {
            if(!selectedIndex.count(j)) {
                selectedIndex.insert(j);
                permutation.push_back(nums[j]);

                permutate(i + 1);
                
                permutation.pop_back();
                selectedIndex.erase(j);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums_) {
        nums = nums_;
        n = nums.size();
        permutate(0);
        
        vector<vector<int>> answer;
        for(auto perm : unique_perms)
            answer.push_back(perm);
        return answer;
    }
};


// Dr Mostafa solution without using unordered_set or set (just by using frequency array !)
/*
One simple generic way for permutations is simply the frequency approach

Assume we have input {4, 4, 5, 6, 6, 6}
	So frequency is:
		4: 2
		5: 1
		6: 3

	We have an output of 6 values
	In each position, just pick one of the unique values; initially 4, 5, 6
	In this way; we try e.g. 4 only once

In other words, we apply our backtrack were we try all our unique choices per idx

Note; there are another approach based on while loop to skip similar numbers
	https://leetcode.com/problems/permutations-ii/discuss/18599/C%2B%2B-clean-recursive-easy-solution-beats-92
 */

vector<int> nums;
unordered_map<int, int> freq_mp;
vector<vector<int>> perm_list;
vector<int> cur_perm;

void permute_bt(int idx) {
	if (idx == (int) nums.size()) {
		perm_list.push_back(cur_perm);
		return;
	}

	for (auto [value, freq] : freq_mp) if (freq) {
		freq_mp[value] -= 1;
		cur_perm[idx] = value;

		permute_bt(idx + 1);

		freq_mp[value] += 1;
		cur_perm[idx] = -1;
	}
}

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &nums_) {
        nums = nums_;
        perm_list.clear();
        freq_mp.clear();

		cur_perm = vector<int>(nums.size(), -1);
		for (int i : nums)
			freq_mp[i]++;

		permute_bt(0);
		return perm_list;
	}
};
