                                                    // problem link: https://codeforces.com/gym/102942/problem/A?f0a28=1
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

    while(t--) {
        int zeros{}, ones{}, size{};
        string num{}; cin >> size >> num;
        for(char dig: num) // calculate how many zeros and ones we have
            if(dig == '0') zeros++;
            else           ones++;

        int moves = abs(zeros-ones) % 4; // diff between #zeros & #ones tells us the number of moves
        if(moves == 0) cout << "E" << endl; // right and left moves are equal so we end up in initial place E
        else if(moves == 2) cout << "W" << endl; // going 2 right or 2 left would be same result W
        // going 1 right or 3 left would end up in S
        else if((moves==1 && zeros>ones) || (moves==3 && ones>zeros))
            cout << "S" << endl;
        // going 1 left or 3 right would end up in N
        else if((moves==1 && ones>zeros) || (moves==3 && zeros>ones))
            cout << "N" << endl;
    }
}
