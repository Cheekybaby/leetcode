/**
 * @param {number} n
 * @return {boolean}
 */
const recur = (n, alice) => {
    if (n === 0){
        return ;
    }
    for (let i=1; i<n; i+=1){
        if (n%i === 0){
            alice[0] = !alice[0];
            recur(n-i, alice);
            break;
        }
    }
}
var divisorGame = function(n) {
    let alice = [true];
    recur(n, alice);
    return !alice[0];
};