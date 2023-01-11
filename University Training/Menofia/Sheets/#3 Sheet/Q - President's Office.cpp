                                                    // problem link: https://codeforces.com/problemset/problem/6/B
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
    int n{}, m{}; cin >> n >> m; // n for rows and m for columns
    char p_color{}; cin >> p_color; // president desk color

    char room[n][m], color{}; cin.get(color); // to get /n character out of the way before storing into room matrix
    vector<int> row, col; // vector of indices for each cell (row and column index for each cell)
    for(int i{}; i<n; i++) { // loop over rows
        for(int j{}; j<m+1; j++) { // loop over columns and it's m+1 because we read \n
            if(i==n-1 && j==m) break; // if it our last time in both loops, we break before reading as nothing to read exist
            cin.get(color);
            if(color=='\n') break; // break if we read \n as it means we are at the end of this row
            room[i][j] = color;

            if(color == p_color) { // if the color is president color then we store its index in row and col vectors
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    vector<char> colors; // vector to store all neighbouring colors of president desk
    for(int i{}; i<row.size(); i++) { // we loop over each cell of president desk
        if(row.at(i) != 0) { // we check if the upper cell exist before accessing it
            char up {room[row.at(i)-1][col.at(i)]};
            if(up!=p_color && up!='.') // checking if it's not empty with '.' or if it's another cell of president desk
                colors.push_back(up);
        }
        if(row.at(i) != n-1)  { // we check if the down cell exist before accessing it
            char down {room[row.at(i)+1][col.at(i)]};
            if(down != p_color && down!='.') // checking if it's not empty with '.' or if it's another cell of president desk
                colors.push_back(down);
        }
        if(col.at(i) != 0) { // we check if the left cell exist before accessing it
            char left {room[row.at(i)][col.at(i)-1]};
            if(left != p_color && left!='.') // checking if it's not empty with '.' or if it's another cell of president desk
                colors.push_back(left);
        }
        if(col.at(i) != m-1) { // we check if the right cell exist before accessing it
            char right {room[row.at(i)][col.at(i)+1]};
            if(right != p_color && right!='.') // checking if it's not empty with '.' or if it's another cell of president desk
                colors.push_back(right);
        }
    }
    int ans{1}; // in case if there's only 1 neighbour the ans is 1
    if(colors.empty()) cout << 0; // if there is no neighbours then the ans is 0
    else {
        sort(colors.begin(), colors.end()); // we sort characters because we will keep comparing till we find different character
        char color{colors.at(0)}; // we start with the first neighbour
        for(int i{1}; i<colors.size(); i++)
            if(colors.at(i) != color) { // we keep comparing current with previous and they are not equal,
                color = colors.at(i); // then we have another desk so we assign the new desk color,
                ans++; // and increment our ans for the new desk
            }
        cout << ans;
    }
}
