class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool is_bulky {false};
        if(length >= 10000 || width >= 10000 || height >= 10000 || (long long) length * width * height >= 1000000000)
            is_bulky = true;
        
        bool is_heavy {false};
        if(mass >= 100) 
            is_heavy = true;
        
        if(is_bulky && is_heavy) 
            return "Both";
        if(is_bulky && !is_heavy)
            return "Bulky";
        if(!is_bulky && is_heavy)
            return "Heavy";
        
        // if(!is_bulky && !is_heavy)
        return "Neither";
    }
};
