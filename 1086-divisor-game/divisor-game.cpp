class Solution {
public:
    void recursion(int n, bool &alice){
        if (n == 0){
            return ;
        }

        for (int i=1; i<n; i+=1){
            if (n%i == 0){
                alice=!alice;
                recursion(n-i, alice);
                break;
            }
        }
    }
    bool divisorGame(int n) {
        bool alice = true;
        recursion(n, alice);
        return !alice;
    }
};