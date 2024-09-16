class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for (int i=1; i<numRows; i+=1){
            vector<int> row(i+1, 1);
            for (int j=1; j<i; j+=1){
                row[j] = triangle.back()[j-1] + triangle.back()[j];
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};