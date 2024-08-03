/**
 * @param {string} s
 * @return {number}
 */
const solve = (s, idx, memo = {}) =>{
    if (idx in memo) return memo[idx];
    if (idx === s.length) return 1;
    if (s[idx] === '0') return 0;

    let ways = solve(s, idx+1, memo);
    if (idx + 1 < s.length && (s[idx] === '1' || (s[idx] === '2' && s[idx+1] <= '6'))){
        ways += solve(s, idx+2, memo);
    }

    memo[idx] = ways;
    return memo[idx];
}
var numDecodings = function(s) {
    return solve(s, 0);
};