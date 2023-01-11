                                                    // Problem link: https://codeforces.com/contest/328/problem/A
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
// detect if the number is int or not by narrowing conversion double to int then comparing
// if  they were the same
bool is_int(dd double_num) {
    int int_num = double_num; // narrow double by copying to int
    if(int_num == double_num) // if the number is int then they must be equal but if not equal then the num was double
        return true;
    return false;
}

int main() { IOS
    dd num; vector<dd> seq; // we take the input and store in vecotr
    for(int i{}; i<4; i++) {
        cin >> num;
        seq.push_back(num);
    }

    // we get the difference and ratio between (1st & 2nd), (2nd, 3rd), (3rd, 4rd)
    dd d1 = seq[3] - seq[2]; dd d2 = seq[2] - seq[1]; dd d3 = seq[1] - seq[0]; dd next1 = seq[3]+d1;
    dd r1 = seq[3] / seq[2]; dd r2 = seq[2] / seq[1]; dd r3 = seq[1] / seq[0]; dd next2 = seq[3]*r1;
    // if all differences are equal, it's arithmetic sequence and we print next in sequence if it is int number
    if(d1==d2 && d2==d3 && is_int(next1))
        cout << next1;
    // if all ratio are equal, it's geometric sequence and we print  if it is int number
    else if(r1==r2 && r2==r3 && is_int(next2))
        cout << next2;
    else
        cout << 42; // printing 42 as required if sequence is neither arithmetic or geometric or next in sequence is not int
}
