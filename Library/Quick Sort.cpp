/* the core operation for Quick Sort and used in most of data sets, as it partitions the vector to 2 partitions,
 * it takes the vector and 2 integers, left & right index, and return int which is index to the pivot,
 * when it has the smaller on the left partition and the bigger on the right partition */
int partition2 (vector<int> &a, int l, int r) {
    // pivot is chosen randomly from quick_sort() function and it's the first element in the vector.
    int pivot = a[l];
    // we make a copy of the left index, and it's used to get all elements smaller than the pivot on its left partition.
    int m = l;
    // loop to go over vector elements to compare them with pivot to get all "smaller or equal" elements on the left partition.
    for (int i {l+1}; i <= r; i++)
        // if the current element in the loop is (smaller than/ equal to) the pivot.
        if (a[i] <= pivot) {
            // we increase the left partition index to store the "new smaller than pivot number".
            m++;
            // we store the "new smaller than pivot number" by swapping its current location with left partition index m.
            swap(a[i], a[m]);
        }
    /* after getting all smaller elements than pivot on the left partition,
     * we get the pivot in the middle (on the right of them),
     * by swapping the first element in the vector (pivot) with the last element in the left partition */
    swap (a[l], a[m]);
    /* we return m index which is referring now to the pivot,
     * where in left partition we have smaller elements and on right bigger elements. */
    return m;
}
/* the core operation for "Quick Sort 3" used in the "few unique data sets" specially, as it partitions the vector to 3 partitions,
 * it takes the vector to partition and 2 int for the left & right indices,
 * and return 2 integers in a vector which are start & end indices for the middle partition */
vector<int> partition3 (vector<int>&a, int l, int r) {
    // pivot is chosen randomly from quick_sort() function and it's the first element in the vector.
    int pivot = a[l];
    /* we make a copy of the left index, and it's used to get all elements smaller than the pivot on its left partition,
     * and it's called m1 as it would be the end index of the left partition. */
    int m1 = l;
    // loop over vector elements to compare them with pivot to get all "only smaller" elements on the left partition.
    for (int i{l+1}; i<=r; i++)
        // if the current element in the loop is smaller than the pivot.
        if (a[i] < pivot) {
            // we increase the left partition end index to store the "new smaller than pivot number".
            m1++;
            /* we store the "new smaller than pivot number",
             * by swapping its current location with the left partition end index. */
            swap (a[i], a[m1]);
        }
    /* we make a copy of m1 called m2 which is the end index for the middle partition,
     * as m2 will continue to change to reach the end of the middle partition */
    int m2 = m1;
    /* loop over vector elements to compare them with pivot,
     * to get all "only equal to" pivot elements in the middle partition (pivot partition),
     * but it starts after the end index of the left partition as we already knew all before elements are smaller than pivot. */
    for (int i{m2 + 1}; i <= r; i++)
        // if the current element in the loop is equal to the pivot.
        if (a[i] == pivot) {
            // we increase middle partition end index to store the "new equal to pivot number".
            m2++;
            // we store the "new equal to pivot number" by swapping its current location with "middle partition end index"
            swap (a[i], a[m2]);
        }

    /* we swap the pivot with left partition end index,
     * so now m1 & m2 would be the start & end indices for the middle partition. (which we want to return from function) */
    swap(a[l], a[m1]);
    // we return m1 & m2 in a vector and now we have partitioned the vector into 3-way partition.
    return vector<int> {m2, m1};
}
/* Quick sort function which takes the vector by reference to sort and the left & right indices,
 * and it doesn't return data because we pass the vector by reference so it would itself changes not a copy */
void quick_sort(vector<int> &a, int l, int r) {
    // Recursion base case where we would have a partition of 1 element we just return.
    if (l >= r) return;
    /* we take a random pivot from the vector by using random generator mod the size of the vector,
     * so we get a number smaller by 1 of the size to add on the left index */
    int k = l + rand()%(r-l+1);
    // we get the chosen pivot in the first position of the vector by swapping its index with the left index.
    swap(a[l], a[k]);
    /* we take the returned vector of the function partition3,
     * where the vector has 2 integers m1 & m2 for the start & end indices for the middle partition. */
    vector<int> m = partition3(a, l, r);
    // 2 Recursion call to the same function to divide again the left and right partition till we hit base case.
    // first recursion call is on the left partition using m1.
    quick_sort(a, l, m[0] - 1);
    // second recursion call is on the right partition using m2.
    quick_sort(a, m[1] + 1, r);
}
