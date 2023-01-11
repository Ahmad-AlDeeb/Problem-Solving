/* we take 2 sorted vectors and sort them together to return the main vector sorted,
 * we have those 2 sorted vectors cause we starts by just 1 element in each vector from base case,
 * then it gets bigger and bigger by comparing them together. */
vector <int> merge(vector<int> left, vector<int> right) {
    // this is a result vector of merging the 2 sorted vector.
    vector<int> result;
    // an index for the left vector and another for the right vector.
    int left_index{}, right_index{};
    // while we don't reach the end of any of the 2 vectors, we continue comparing their elements (to prevent runtime error).
    while (left_index<left.size() && right_index<right.size()) {
        // if the number of the left vector smaller than the number from the right vector...
        if (left[left_index] < right[right_index]) {
            // we add the number of the left vector to the result vector.
            result.push_back(left[left_index]);
            // we move the index to the next number of the left vector to compare with the number of the right vector.
            left_index++;
        }
        // if it's vice versa, and the number of the right vector is smaller than the number of the left vector...
        else {
            // we add the number of the right vector to the result vector.
            result.push_back(right[right_index]);
            // we move the index to the next number of the right vector to compare with the number of the left vector.
            right_index++;
        }
    }
    /* what if one of the 2 vectors still has some elements left?
     * we just add them to result vector because they are already sorted! */
    // we check if left vector has any remaining elements.
    for (;left_index < left.size(); left_index++)
        // if so, we add the remaining elements of left vector to the result vector.
        result.push_back(left[left_index]);
    // we check if right vector has any remaining elements.
    for (;right_index < right.size(); right_index++)
        // if so, we add the remaining elements of the right vector to the result vector.
        result.push_back(right[right_index]);
    // we just return the merged sorted vector of the 2 sorted vector (left & right).
    return result;
}
// we take the vector we want to sort and return it but sorted for sure :D
vector <int> merge_sort(vector<int> vec) {
    // base recursion case, when there's only one element in vector, return the vector with it.
    if (vec.size() == 1) return vec;
    // how many elements in the vector?
    int size = vec.size();
    // the half of number of elements in the vector.
    int mid = size/2;
    // we are gonna split the main vector into 2 vectors, left & right.
    vector<int> left, right;
    // we loop through the main vector till we reach the end.
    for (size_t i{}; i<size; i++) {
        // we add the first half of the elements in the left vector.
        if (i < mid) left.push_back(vec[i]);
        // we add the second half of the elements in the right vector.
        else right.push_back(vec[i]);
    }
    /* this function do the sort operation and it has 2 recursive calls to merge_sort() function to keep splitting them,
     * till we hit base case with 2 vectors of 1 element so we are able to sort them together */
    return merge(merge_sort(left), merge_sort(right));
}
