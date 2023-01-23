#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e5;

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    bitset<14> x;
    //// First Query ////
    cout << "? ";
    for(ll i{1}; i<=100; i++)
        cout << i << " ";
    cout << endl; cout.flush();

    ll input1; cin >> input1;
    bitset<14>seq1(input1);
    for(ll i{13}; i>=7; i--)
        x[i] = seq1[i];

    //// Second Query ////
    cout << "? ";
    for(ll i{1}; i<=100; i++)
        cout << (i<<7) << " ";
    cout << endl; cout.flush();

    ll input2; cin >> input2;
    bitset<14>seq2(input2);
    for(ll i{6}; i>=0; i--)
        x[i] = seq2[i];

    //// Calculating Answer ////
    ll ans{};
    for(ll i{}; i<14; i++)
        if(x[i]) ans += pow(2,i);
    cout << "! " << ans << endl; cout.flush();
}
