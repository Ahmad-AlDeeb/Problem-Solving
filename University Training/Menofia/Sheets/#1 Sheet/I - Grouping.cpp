                                                    // problem link: https://atcoder.jp/contests/abc062/tasks/abc062_a?lang=en
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
    int x{}, y{}; cin >> x >> y;
    vector<int> a {1, 3, 5, 7, 8, 10, 12};
    vector<int> b {4, 6, 9, 11};

    int counter{0}; // if counter is 0 means we didn't find x or y but if it's 1 we found only x or y and if it's 2 we found both
    for(int n: a) if(n==x || n==y) counter++;
    if (counter == 1) {cout << "No"; return 0;}
    if(counter == 2)  {cout << "Yes"; return 0;}

    for(int n: b) if(n==x || n==y) counter++;
    if (counter == 1) {cout << "No"; return 0;}
    if(counter == 2) {cout << "Yes"; return 0;}
}
