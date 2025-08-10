class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0;
        unordered_map<int,int> basket;
        int max_fruit = 0, sum = 0;
        while(j < fruits.size()){
            basket[fruits[j]]++;
            
            sum += 1;
            
            while(i < j && basket.size() > 2){
                basket[fruits[i]]--;
                sum -= 1;
                if (basket[fruits[i]] == 0) basket.erase(fruits[i]);

                i++;
            }

            max_fruit = max(max_fruit, sum);
            j++;
        }

        return max_fruit;
    }
};


/*
We need to consider every subarray with only two kinds of fruits.
So we start and start putting the fruits in the basket.
Whenever we see encounter a new fruit, if only one basket is being used, then we just keep it and move on, but if no basket is empty, then we start taking out the fruits we started from until there are only two types left, then we move on again.

So whenever we encounter a third type, we update the maximum fruit seen till now.

*/