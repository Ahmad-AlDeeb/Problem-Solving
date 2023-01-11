int comp_double(double a, double b) {
    if(fabs(a-b) <= 1e-10) return 0;
    return a<b? -1:1;
}
