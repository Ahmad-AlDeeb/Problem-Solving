string huge_sum(string s1, string s2) {
    int size1 = s1.size(), size2 = s2.size();

    // Making the two numbers equal in size by adding zeros to the smaller number //
    if(size1 > size2) {
        string zeros;
        for(int i{}; i < size1-size2; i++) zeros += "0";
        s2 = zeros + s2;
    }
    else if(size1 < size2) {
        string zeros;
        for(int i{}; i < size2-size1; i++) zeros += "0";
        s1 = zeros + s1;
    }

    // Summing each digit from the both numbers //
    string sum{}; int carry{};
    for(int i= s1.size()-1; i>=0; i--) {
        int dig_sum {carry + (s1[i] - 48) + (s2[i] - 48)};
        sum += to_string(dig_sum%10);
        carry = dig_sum / 10;
    }
    if(carry) sum += "1";
    reverse(sum.begin(),sum.end());
    return sum;
}
bool is_bigger(string s1, string s2) {
    if(s1.size() > s2.size()) return true;
    else if(s1.size() < s2.size()) return false;
    else {
        for(int i{}; i<s1.size(); i++)
            if(s1[i] > s2[i]) return true;
            else if(s1[i] < s2[i]) return false;
        return false;
    }
}
void swap(string s1, string s2) {
    string temp = s1;
    s1 = s2; s2 = temp;
}
string huge_sub(string s1, string s2) {
    // Swapping if s1 is smaller than s2
    int size1 = s1.size(), size2 = s2.size();
    if(size1 < size2) swap(s1, s2);
    else if(size1 == size2) {
        bool s2_bigger{false};
        for(int i{}; i<size1; i++)
            if(s1[i] < s2[i]) s2_bigger=true;
        if(s2_bigger) swap(s1,s2);
    }

    // Making the two numbers equal in size by adding zeros to the smaller number //
    size1 = s1.size(); size2 = s2.size();
    if(size1 > size2) {
        string zeros;
        for(int i{}; i < size1-size2; i++) zeros += "0";
        s2 = zeros + s2;
    }
    else if(size1 < size2) {
        string zeros;
        for(int i{}; i < size2-size1; i++) zeros += "0";
        s1 = zeros + s1;
    }


    // Subtracting each digit from the both numbers //
    string sub{};
    for(int i=s1.size()-1; i>=0; i--) {
        int dig_sub{(s1[i]-48) - (s2[i]-48)};
        if(s1[i] < s2[i]) {
            dig_sub = (s1[i]-48)+10 - (s2[i]-48);
            s1[i-1]--;
        }
        sub += to_string(dig_sub);
    }
    reverse(sub.begin(), sub.end());
    return sub;
}
string huge_pro(string s1, string s2) {
    string pro{"0"};
    for(int zeros{}, j=s2.size()-1; j>=0; j--, zeros++) {
        string dig_sum;
        for (int j{}; j < zeros; j++) dig_sum += "0";

        int carry{};
        for (int i = s1.size() - 1; i >= 0; i--) {
            int dig_pro{(s1[i] - 48) * (s2[j] - 48) + carry};
            dig_sum += to_string(dig_pro % 10);
            carry = dig_pro / 10;
        }
        if (carry > 0) dig_sum += to_string(carry);
        reverse(dig_sum.begin(), dig_sum.end());
        pro = huge_sum(pro, dig_sum);
    }
    return pro;
}
