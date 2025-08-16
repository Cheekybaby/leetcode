class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0, j = letters.size()-1;
        while (i <= j){
            int mid = midpoint(i, j);

            if (letters[mid] == target){
                while(mid < letters.size() && letters[mid] == target){
                    mid++;
                }
                if (mid == letters.size()) return letters[0];
                else return letters[mid];
            } else if (letters[mid] > target){
                j = mid - 1;
            } else i = mid + 1;
        }

        if (i >= letters.size()) return letters[0];
        return letters[i];
    }
};