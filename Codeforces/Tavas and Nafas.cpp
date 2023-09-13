#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////
const ll N = 1e4+4;
const ll M = 1e9+7;
const ll MAX = 1e18;
const ld EPS = 1e-19;
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void fast() {
    map<ll,string> txt;
    txt[0]="zero",
    txt[1]="one", txt[2]="two", txt[3]="three", txt[4]="four", txt[5]="five",
    txt[6]="six", txt[7]="seven", txt[8]="eight", txt[9]="nine", txt[10]="ten",
    txt[11]="eleven", txt[12]="twelve", txt[13]="thirteen", txt[14]="fourteen", txt[15]="fifteen", txt[16]="sixteen",
    txt[17]="seventeen", txt[18]="eighteen", txt[19]="nineteen",
    txt[20]="twenty", txt[30]="thirty", txt[40]="forty", txt[50]="fifty", txt[80]="eighty";

    ll n; cin >> n;
    if(n <= 20) cout << txt[n];
    else {
        string num = to_string(n);
        if(num[0]=='2') cout << txt[20];
        else if(num[0]=='3') cout << txt[30];
        else if(num[0]=='4') cout << txt[40];
        else if(num[0]=='5') cout << txt[50];
        else if(num[0]=='8') cout << txt[80];
        else cout << txt[num[0]-'0'] << "ty";

        if(num[1]!='0') cout << "-" << txt[num[1]-'0'];
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
//        cout << endl;
    }
}
