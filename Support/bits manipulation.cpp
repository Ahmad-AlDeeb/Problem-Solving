// Int to binary conversion
string binary = bitset<32>(n).to_string(); // 1st way
// or by dividing n by 2 and pushing back the remainder till n becomes 0 (2nd way)
// or (3rd way)
void print_bits(ll n, ll size) {
    if(!size) return;

    print_bits(n>>1, size-1);
    cout << (n&1);
}
void print_all_subsets(int size) {
    for(int i{}; i<(1<<size); i++) {
        print_bits(i,size);
        cout << endl;
    }
}
///////////////////////////////
// count 1s in binary //
int bits_count(ll n) {
    int count{};
    while(n) {
        if(n&1) count++;
        n >>= 1;
    }
    return count;
}
int bits_count2(ll n) {
    int count{};
    while(n) {
        n &= (n-1);
        count++;
    }
    return count;
}
/////////////////////////////////
// Other Important operations //
int get_bit(ll num, int i) {
    return ((num>>i) & 1) == 1;
}
ll set_bit1(ll num, int i) {
    return num | (1<<i);
}
ll set_bit0(ll num, int i) {
    return num & ~(1<<i);
}
ll flip_bit(ll num, int i) {
    return num ^ (1<<i);
}
