#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#define occ first
#define v second
#define dd double
#define ll long long
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstring>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
int n, k, w, pos, wish;
vector<vector<int>>adj;
vector<bool>visited;
vector<int> initial;
vector<int> parent;
 
void topological_sort(int student) {
    visited[student] = true;
    for(int child:adj[student])
        if(!visited[child])
            topological_sort(child);
 
    initial.push_back(student);
}
 
int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cin >> n >> k;
    adj = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1);
    parent = vector<int>(n+1);
 
    for(int i{1}; i<=k; i++) {
        cin >> w;
        while(w--) {
            cin >> wish;
            adj[i].push_back(wish);
        }
    }
 
    for(int i{1}; i<=n; i++)
        if(!visited[i])
            topological_sort(i);
 
    pos = 0;
    for(int i{n-1}; i>=0; i--) {
        int student = initial[i];
        parent[student] = pos;
        pos = student;
    }
 
    for(int i{1}; i<=n; i++)
        cout << parent[i] << endl;
}
 
