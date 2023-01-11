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
    string a, comp, b; cin >> a >> comp >> b;

    int a_i = stoi(a);
    int b_i = stoi(b);

    if(comp == "=") {
        if (a_i==b_i) cout << "Right";
        else cout << "Wrong";
    }
    if(comp == ">") {
        if(a_i>b_i) cout << "Right";
        else cout << "Wrong";
    }
    if(comp == "<") {
        if(a_i<b_i) cout << "Right";
        else cout << "Wrong";
    }
}
