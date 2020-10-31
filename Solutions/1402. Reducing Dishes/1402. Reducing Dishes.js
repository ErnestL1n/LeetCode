/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(s) {
    s.sort((a,b)=>a-b);
    var res=0,total=0;
    for(let i=s.length-1;i>=0&&s[i]+total>0;--i){
        total+=s[i];
        res+=total;
    }
    return res;
};