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
    int a{}, b{}; cin >> a >> b;
    string s; cin >> s;

    for(int i{}; i<s.size(); i++) {
        if(i==a)
            {if(s[a]!='-') {cout << "No"; return 0;}}
        else
            if(s[i]-48<0 || s[i]-48>9) {cout << "No"; return 0;}
    }
    cout << "Yes";
}
