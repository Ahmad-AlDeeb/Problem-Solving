int binary_exp(int x, int n) {
    int result {1};

    while(n > 0) {
        if(n%2 == 1) result *= x; // to minus the odd number n by one, we multiply the base x in result
        // equals (x^2)^n/2
        x *= x; 
        n /= 2;
    }
    return result;
}
