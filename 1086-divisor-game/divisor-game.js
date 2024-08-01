/**
 * @param {number} n
 * @return {boolean}
 */

function recursive(n,alice){
    if(n===0){
        return;
    }

    for(let i=1;i<n;i++){
        alice[0]=!alice[0];
        
        recursive(n-i,alice);
        break;
    }
}
var divisorGame = function(n) {
    let alice=[0,1];
    recursive(n,alice);
    return alice[0];
};