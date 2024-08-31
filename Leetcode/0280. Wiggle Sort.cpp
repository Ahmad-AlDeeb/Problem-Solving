#include <bits/stdc++.h> 
vector<int> wiggleSort(int n, vector<int> arr) {
    bool is_bigger{true};
    vector<int> test(arr);
    
    for(int i{1}; i<n; i++) {    
        int first {arr[i-1]};
        int second {arr[i]};
        
        if(is_bigger && second < first || !is_bigger && second > first) {
            swap(arr[i], arr[i-1]);
        }
        is_bigger = !is_bigger;
    }
    return arr;
}
