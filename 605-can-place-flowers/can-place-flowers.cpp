class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        if (flowerbed.size()==1){
            if (flowerbed[0]==1 && n>0) return false;
            else if (flowerbed[0]==0 && n>1) return false;
            else return true; 
        }
        while (i<flowerbed.size()){
            if (n == 0) return true;
            if (i==0){
                if (flowerbed[i+1]==0 && flowerbed[i]==0){
                    n-=1;
                    flowerbed[i] = 1;
                }
            } else if (i>0 && i<flowerbed.size()-1){
                if (flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                    n-=1;
                    flowerbed[i] = 1;
                }
            } else {
                if (flowerbed[i-1]==0 && flowerbed[i]==0){
                    n-=1;
                    flowerbed[i] = 1;
                }
            }
            i+=1;
        }

        if (n == 0) return true;
        return false;
    }
};