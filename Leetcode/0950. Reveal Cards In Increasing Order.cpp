class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        
        queue<int> deck_queue;
        for(int i{}; i<deck.size(); i++) 
            deck_queue.emplace(i);
        
        vector<int> order;
        while(!deck_queue.empty()) {
            order.push_back(deck_queue.front());
            deck_queue.pop();
            
            deck_queue.push(deck_queue.front());
            deck_queue.pop();
        }

        vector<int> answer(deck.size());
        for(int i{}; i<order.size(); i++)
            answer[order[i]] = deck[i];
        
        return answer;
    }
};
