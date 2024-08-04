/**
 * @param {number[]} nums
 * @return {number}
 */
const solve = (nums, n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n < 0) return 0;
    if (n === 0) return nums[0];

    let loots = nums[n] + solve(nums, n - 2, memo);
    let not_loots = solve(nums, n - 1, memo);

    memo[n] = Math.max(loots, not_loots);
    return memo[n];
}

var rob = function(nums) {
    return solve(nums, nums.length-1);
};