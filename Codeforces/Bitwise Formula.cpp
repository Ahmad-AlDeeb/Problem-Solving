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
#include<map>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>

int n,m;
struct line{
    string binary;
    int lhs,op,rhs,digit;
    line(){};
    line(string binary, int lhs, int op, int rhs, int digit)
        : binary(binary), lhs(lhs), op(op), rhs(rhs), digit(digit){}
};
vector<line>lines(5005);
map<string,int>var;
int ones_count(int index, int bit) {
    lines[0].digit = bit;

    int count{};
    for(int i{1}; i<=n; i++) {
        if(lines[i].op == 0)
            lines[i].digit = lines[i].binary[index]-'0';
        else {
            int lhs = lines[lines[i].lhs].digit,
                rhs = lines[lines[i].rhs].digit;

            if(lines[i].op == 1) lines[i].digit = (lhs&rhs);
            else if(lines[i].op == 2) lines[i].digit = (lhs|rhs);
            else if(lines[i].op == 3) lines[i].digit = (lhs^rhs);
        }
        count += lines[i].digit;
    }
    return count;
}


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cin >> n >> m;
    var["?"] = 0;

    for(int i{1}; i<=n; i++) {
        string s;
        cin >> s; var[s] = i;
        cin >> s; // reading garbage :=
        cin >> s;
        if(isdigit(s[0])) {
            lines[i].op = 0;
            lines[i].binary = s;
        }
        else {
            lines[i].lhs = var[s];

            cin >> s;
            if(s=="AND") lines[i].op = 1;
            else if(s=="OR") lines[i].op = 2;
            else if(s=="XOR") lines[i].op = 3;

            cin >> s;
            lines[i].rhs = var[s];
        }
    }

    string mini,maxi;
    for(int i{}; i<m; i++) {
        int count0 = ones_count(i,0),
            count1 = ones_count(i,1);

        if(count0 < count1) {
            mini +='0';
            maxi += '1';
        }
        else if(count0 > count1) {
            mini += '1';
            maxi += '0';
        }
        else {
            mini += '0';
            maxi += '0';
        }
    }
    cout << mini << endl << maxi;
}
