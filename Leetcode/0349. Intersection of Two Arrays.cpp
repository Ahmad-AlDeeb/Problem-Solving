class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1, m2;
        for(auto num : nums1)
            m1[num]++;
        for(auto num : nums2)
            m2[num]++;
        
        vector<int> answer;
        for(auto pair : m1) 
            if(m2[pair.first])
                answer.push_back(pair.first);
        return answer;   
    }
};
