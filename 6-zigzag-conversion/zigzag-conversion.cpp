class Solution {
public:
    string convert(string s, int numRows) {
        // Edge cases
        if (numRows == 1 || numRows >= s.length()) return s;
        // Output String
        string output;
        
        int step = 2*(numRows-1);

        for(int i=0; i<numRows; i+=1){
            for(int j=i; j<s.length(); j+=step){
                output += s[j];

                // Diagonal
                int diag = j + step - 2*i;
                if (i > 0 && i < numRows-1 && diag < s.length()){
                    output += s[diag];
                }
            }
        }

        return output;
    }
};