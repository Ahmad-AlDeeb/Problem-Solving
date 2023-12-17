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
///////////////////////////////////////
const ll N = 1e7+7;
const ll M = 998244353;
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
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
void fast() {
    ll n; string s; cin >> n >> s;
    if(n==1) {cout << 0; return;}

    vector<bool> vis(n,false);
    vis.back() = true;

    char mx{s.back()};
    for(ll i{n-2}; i>=0; i--)
        if(s[i] >= mx) { /// WHAT ABOUT MANY MAX !!?
            mx = s[i];
            vis[i]=true;
        }

    /////// Checking if seq can be sorted ////////
    // Creating the seq first
    string seq;
    for(ll i{}; i<n; i++)
        if(vis[i]) seq += s[i];
    ll sz = seq.size();
    // Detecting index of first smallest char
    char mn{'z'}; ll index{};
    for(ll i{}; i<sz; i++)
        if(seq[i]<mn) mn=seq[i], index=i;
    // Checking if it can be sorted by right shifting
    bool cool{true};
    for(ll i{index+1}; i==index; i++, i%=sz) {
        ll j = mod(i-1,sz);
        if(seq[i] < seq[j]) cool=false;
    }
    if(!cool) {cout << -1; return;}

    ///////////////////////////////////////////////
    string seq_srt {seq};
    sort(all(seq_srt));

    ll moves{};
    char tar{seq.front()};
    /// WHAT ABOUT REPITION ?
    for(ll i{}; i<seq_srt.size(); i++) {
        if(tar == seq_srt[i]) break;
        else moves++;
    }




    string res{s};
    for(ll i{},j{}; i<n; i++)
        if(vis[i]) res[i]=seq_srt[j++];

    sort(all(s));
    if(s == res) cout << moves;
    else         cout << -1;
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }

}


