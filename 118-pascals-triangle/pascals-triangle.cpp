class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=0; i<numRows; i+=1){
            vector<int> row(i+1, 1);
            for (int j=1; j<i; j+=1){
                row[j] = triangle[i-1][j]+triangle[i-1][j-1];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};