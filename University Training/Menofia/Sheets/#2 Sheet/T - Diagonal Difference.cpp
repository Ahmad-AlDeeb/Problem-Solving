                                                    // problem link: https://www.hackerrank.com/contests/week-1-1/challenges/diagonal-difference
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
    int num{}, size{}; cin >> size;
    int matrix [size][size];
    for(int i{}; i<size; i++) // reading input and storing it into matrix
        for(int j{}; j<size; j++)
            cin >> matrix[i][j];

    int sum1{}, sum2{}; // summing up both diagonal in sum1 and sum 2
    for(int i{}; i<size; i++) {
        sum1 += matrix[i][i];
        sum2 += matrix[i][size-1-i];
    }
    cout << abs(sum1-sum2);
}
