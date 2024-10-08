int BS(vector<int>& vec, int target, bool first) {
    int n = vec.size();
    int l{}, r{n-1}, ans{-1};
    
    while(l <= r) {
        int mid = l + (r-l) / 2;
        if(vec[mid] > target) {
            r = mid - 1;
        }
        else if(vec[mid] < target) {
            l = mid + 1;
        }
        else {
            if(first) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }

            ans = mid;
        }
    }

    return ans;
}
ld BS(ld l, ld r, ld target) {
    for(int iter{}; iter<100; ++iter) {
        ld mid = (l + r) /2;
        
        if(mid < target) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return left;
}
