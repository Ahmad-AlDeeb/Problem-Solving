vector<int> p_fact(int x) {
    int i{2}; vector<int> p;
    while(i*i <= x; i++)
        while(x%i == 0) {
            x /= i; // we keep dividing as long as i divides x
            p.push_back(i); // and we push to factors vector
        }
    if(x != 1) p.push_back(i);
    return p;
}
