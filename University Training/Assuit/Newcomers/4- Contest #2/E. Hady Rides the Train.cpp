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
    ll id{}; cin >> id;
    ll row = id/4;
    ll steps {id%4};
    if(row%2 == 0) { // left
        if(steps == 0) cout << row << " " << 0;
        if(steps == 1) cout << row << " " << 1;
        if(steps == 2) cout << row << " " << 2;
        if(steps == 3) cout << row << " " << 3;
    }
    else { // right
        if(steps == 0) cout << row << " " << 3;
        if(steps == 1) cout << row << " " << 2;
        if(steps == 2) cout << row << " " << 1;
        if(steps == 3) cout << row << " " << 0;
    }
}
