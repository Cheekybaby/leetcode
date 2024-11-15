class Solution {
public:
    const vector<pair<int,string>> symbol = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string intToRoman(int num) {
        string roman;
        
        for (const auto &[val, sym] : symbol){
            if (num == 0){
                break;
            }

            while(num >= val){
                roman += sym;
                num -= val;
            }
        }

        return roman;
    }
};