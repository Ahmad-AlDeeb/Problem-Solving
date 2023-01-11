#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pcc pair<char, char>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    string s{}, a{}, op{}, b{}; cin >> s;

    int i{};
    for(; isdigit(s[i]); i++) a += s[i];
    op = s[i++];
    for(; i<s.size(); i++) b += s[i];

    int i_a = stoi(a);
    int i_b = stoi(b);

    if(op == "+") cout << i_a+i_b;
    else if(op == "-") cout << i_a-i_b;
    else if(op == "*") cout << i_a*i_b;
    else if(op == "/") cout << i_a/i_b;
}
