class Solution {
    char getPrev(char digit) {
        if(digit == '0') {
            return '9';
        }
        else {
            return digit - 1;
        }
    }
    char getNext(char digit) {
        if(digit == '9') {
            return '0';
        }
        else {
            return digit + 1;
        }
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> deads;
        string start{"0000"};
        
        for(auto deadend : deadends) {
            deads[deadend] = true;
            if(deadend == start) {
                return -1;
            }
        }

        queue<string> codes;
        codes.push(start);

        for(int level{}, size{1}; !codes.empty(); ++level, size = codes.size()) {
            while(size--) {
                string current = codes.front();
                codes.pop();
                // deads[current] = true;

                if(current == target) {
                    return level;
                }

                vector<char> slot1 {getPrev(current[0]), getNext(current[0])};
                vector<char> slot2 {getPrev(current[1]), getNext(current[1])};
                vector<char> slot3 {getPrev(current[2]), getNext(current[2])};
                vector<char> slot4 {getPrev(current[3]), getNext(current[3])};
                vector<vector<char>> slots {slot1, slot2, slot3, slot4};
                
                for(int slot{}; slot < 4; ++slot) {
                    string newCode {current};

                    for(int option{}; option < 2; ++option) {
                        newCode[slot] = slots[slot][option];

                        if(!deads[newCode]) {
                            deads[newCode] = true;                            
                            codes.push(newCode);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
