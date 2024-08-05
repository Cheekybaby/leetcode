/**
 * @param {number} n
 * @return {number}
 */
const solve = (n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n <= 3) {
        return n;
    }

    let ans = n;
    for (let i=1; i*i<=n; i+=1){
        ans = Math.min(ans, 1 + solve(n-i*i, memo));
    }

    memo[n] = ans;
    return ans;
}

var numSquares = function(n) {
    return solve(n);
};