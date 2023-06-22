ll BS(ll left, ll right, ll val, bool first) {
    while(left < right) {
        ll mid = left + (right - left + 1) / 2;
        if(mid < val) left = mid + 1;
        else if(mid > val) right = mid - 1;
        else {
            if(first) right = mid;
            else left = mid;
        }
    }
    return left;
}
ld BS(ld left, ld right, ld val) {
    while(fabs(right-left) > 10e-7) {
        ld mid = (left+right)/2;
        if(mid < val) left = mid;
        else right = mid;
    }
    return left;
}
