class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,bool>> people;
        for(int i{}; i<tickets.size(); i++) {
            if(i == k) people.emplace(tickets[i], true);
            else       people.emplace(tickets[i], false);
        }

        int seconds{};
        while(!people.empty()) {
            people.front().first--;
            seconds++;

            if(!people.front().first) {
                if(people.front().second) break;
                
                people.pop();
                continue;
            }
            
            people.push(people.front());
            people.pop();
        }
        return seconds;
    }
};
