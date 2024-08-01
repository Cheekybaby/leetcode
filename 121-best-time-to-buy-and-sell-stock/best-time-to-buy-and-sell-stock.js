/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minPrice = prices[0];
    let maxProfit = 0;

    for (let i=1; i<prices.length; i+=1){
        if (minPrice > prices[i]){
            minPrice = prices[i];
        }
        const currProfit = prices[i] - minPrice;
        if (currProfit > maxProfit){
            maxProfit = currProfit;
        }
    }

    return maxProfit;
};