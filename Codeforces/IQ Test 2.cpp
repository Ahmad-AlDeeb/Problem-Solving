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
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    vector<vector<char>>paint(4,vector<char>(4));
    for(ll i{}; i<4; i++)
        for(ll j{}; j<4; j++)
            cin >> paint[i][j];

    for(ll i{}; i<3; i++)
        for(ll j{}; j<3; j++) {
            ll black{},white{};

            if(paint[i][j]=='.') white++;
            else black++;
            if(paint[i][j+1]=='.') white++;
            else black++;
            if(paint[i+1][j]=='.') white++;
            else black++;
            if(paint[i+1][j+1]=='.') white++;
            else black++;

            if(black>2 || white>2) {cout << "YES"; return 0;}
        }
    cout << "NO";
}
