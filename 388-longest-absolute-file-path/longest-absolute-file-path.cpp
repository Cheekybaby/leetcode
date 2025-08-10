class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int,int> path_length;  // Stores the cumulative length till the given depth
        int max_length = 0; // Stores the maximum length of the file seen so far
        path_length[0] = 0; // The length of the depth 0.
        
        // Now we need to traverse the input string
        stringstream ss(input);
        string line;
        while(getline(ss, line, '\n')){
            int depth = 0; // Find the depth of current directory or file
            while(depth < line.length() && line[depth] == '\t'){
                depth++;
            }

            string name = line.substr(depth); // Name of the directory or the file

            // Now see if it is a directory or a file
            if (name.find('.') != string::npos){
                // It is a file, so we update the max_length
                max_length = max(max_length, path_length[depth] + (int)name.length());
            } else {
                // It is a directory
                path_length[depth+1] = path_length[depth] + (int)name.length() + 1; // +1 for '\'
            }
        }


        return max_length;
    }
};

/* 
- Unordered map for saving depth and its cumulative length
- We then traverse the string, looking for new line characters
- Then we look for the depth using the number of tab characters
- If the name of the current substring is a directory (not contains a .) then we update the depth and cumulative length till there, else we consider the length of the file so far.
- The length of the file so far is given by the cumulative length of the depth - 1 + the length of the file name.
- We update the max_length seen so far.

- At the end we return the maximum length of a file seen so far. If the file is present, then the max_length gets updated else it remains 0, as per the problem's requirement
*/