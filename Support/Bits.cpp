// Int to binary conversion
string binary = bitset<32>(n).to_string(); // 1st way
// or by dividing n by 2 and pushing back the remainder till n becomes 0 (2nd way)
// or (3rd way)
void print_bits(ll n, ll size) {
    if(!size) return;
    print_bits(n, size-1);
    cout << (n&1);
}
void get_all_subsets(int size) {
    for(int i{}; i<(1<<size); i++) {
        print_bits(i,size);
        cout << endl;
    }
}
ll gray_code(ll n) {
    return n ^ (n>>1);
}
void get_all_subsets_gray(ll size) {
    for(ll i{}; i<(1<<size); i++) {
        print_bits(gray_code(i),size);
        cout << endl;
    }
}
void get_all_submasks(ll n) {
    for(ll sub{n}; sub; sub = (sub-1)&n)
        print_bits(sub, ones_cnt(n));
    // for reverse: ~sub & n = sub^n
}
/////////// count bits ////////////
ll bits_count(ll n) {
    return (LL)log2(n)+1;
}
pair<ll,ll> bits_count(ll n) {
    ll zero{}, one{};
    while(n) {
        if(n&1) one++; else zero++;
        n >>= 1;
    }
    return {zero,one};
}
ll ones_cnt(ll n) { // or use __builtin_popcount()
    ll cnt{};
    while(n) {
        n &= (n-1);
        cnt++;
    }
    return cnt;
}
/////////////////////////////////
// Other Important operations //
ll get_bit(ll n, ll i) {
    return ((n>>i) & 1);
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
///////// BIGGER Array for bigger visited numbers ! ////////////
bool VIS[10000000000/8];
void set_vis(ll n) {
    set_bit1(VIS[n>>3], VIS[1<<(n&7)]);
}
bool is_vis(ll n) {
    return get_bit(VIS[n>>3], VIS[1<<(n&7)]);
}
///////////////////// Bitset ///////////////////
ll n {10};
bitset<6> x (n);
x.set();
x.flip();
x.count();
x.any();
x.none();
x.test(1);
x.to_ullong();
// logic operators & assignment works!
cout << x << endl;
cout << x.to_string() << endl;
for(ll i=x.size()-1; i>=0; i--)
    cout << x[i];
///////////////////// My New Functions ///////////////////
ll get_fullset(ll n) {
    for(ll i{};;i++)
        if(pow(2,i) > n)
            return pow(2,i)-1;
}
ll get_flipped(ll n) {
    string binary;
    while(n) {
        if(n%2 == 0) binary.pb('0');
        else binary.pb('1');
        n /= 2;
    }
 
    ll result{};
    for(ll i{}; i<binary.size(); i++) {
        if(binary[i]=='0')
            result += pow(2,i);
    }
    return result;
}
