                                                    // problem link: https://atcoder.jp/contests/abc215/tasks/abc215_a?lang=en
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
//#define S second
//#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    string s1; cin >> s1;
    string s2 = "Hello,World!";
    if(s1.size() != s2.size()) {cout << "WA"; return 0;}
    for(int i{}; i<s1.size(); i++)
        if(s1[i] != s2[i])
        { cout << "WA"; return 0;}
    cout << "AC";
}
