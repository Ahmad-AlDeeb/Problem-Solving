                                                    // problem link: https://www.hackerrank.com/contests/week-1-1/challenges/find-digits
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    int t{}; cin >> t;
    string str_num{}; int int_num{};
    for(int i{}; i<t; i++) {
        cin >> str_num;
        int_num = stoi(str_num);

        int count{};
        for(char n: str_num)
            if((n-48) != 0 && int_num % (n-48) == 0)
                count++;
        cout << count << endl;
    }
}
