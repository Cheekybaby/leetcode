class Solution {
public:
    string convertToTitle(int columnNumber) {
        string column;
        while(columnNumber > 0){
            columnNumber--;
            column = char((columnNumber % 26) + 'A') + column;
            columnNumber/=26;
        }

        return column;
    }
};