#include <bits/stdc++.h> 
vector<int> findSteppingNumbers(int l, int r) {
	vector<int> answer;
	queue<string> nums;

	for (int digit{1}; digit < 10; ++digit) {
		nums.push(to_string(digit));

		if(digit >= l && digit <= r) {
			answer.push_back(digit);
		}
	}

	for(int size = nums.size(); !nums.empty(); size = nums.size())
		while(size--) {
			string current = nums.front();
			nums.pop();


			if(current.size() == 8) {
				continue;
			}
			
			char lastDigit = current.back();
			
			if(lastDigit != '0') {
				char prevDigit = lastDigit - 1;
				string num = current + prevDigit;
				nums.push(num);
				
				if(stoi(num) >= l && stoi(num) <= r) {
					answer.push_back(stoi(num));
				}
			}

			if(lastDigit != '9') {
				char nextDigit = lastDigit + 1;
				string num = current + nextDigit;
				nums.push(num);

				if(stoi(num) >= l && stoi(num) <= r) {
					answer.push_back(stoi(num));
				}
			}
		}

	return answer;
}
