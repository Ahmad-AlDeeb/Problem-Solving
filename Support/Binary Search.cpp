bool binary_search(vector<int>&vec, int x, int left, int right) {
    if(left > right) return false;
    int mid {(left+right)/2};
    if(vec[mid] == x) return true;
    else if(x < vec[mid]) return binary_search(vec, x, left, mid-1);
    else                         binary_search(vec, x, mid+1, right);
}
