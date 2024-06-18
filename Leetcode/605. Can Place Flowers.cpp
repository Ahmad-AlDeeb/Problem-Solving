class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for(int i{}; i<size; i++) {
            bool current_plot = flowerbed[i] == false;
            bool left_plot = (i==0) || (flowerbed[i-1] == false);
            bool right_plot = (i==size-1) || (flowerbed[i+1] == false);

            if(current_plot && left_plot && right_plot) {
                n--;
                flowerbed[i] = true;
            }
        }

        return n <= 0;
    }
};
