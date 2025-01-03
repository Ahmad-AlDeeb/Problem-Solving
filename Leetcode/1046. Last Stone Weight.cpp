class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stonesQueue(stones.begin(), stones.end());

        while(stonesQueue.size() > 1) {
            int stone1 = stonesQueue.top();
            stonesQueue.pop();

            int stone2 = stonesQueue.top();
            stonesQueue.pop();

            if(stone1 == stone2) {
                if(stonesQueue.empty()) {
                    return 0;
                }
                continue;
            }

            stonesQueue.push(stone1 - stone2);
        }

        return stonesQueue.top();
    }
};
