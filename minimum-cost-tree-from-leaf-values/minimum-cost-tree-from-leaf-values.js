/**
 * @param {number[]} arr
 * @return {number}
 */
var mctFromLeafValues = function(arr) {
    let cost=0;
    while(arr.length>1){
        let minId=-1;
        let minCost = Number.MAX_VALUE;
        for(let i=0; i<arr.length-1; i++){
            let c = arr[i]*arr[i+1];
            if(c<minCost){
                minCost= c;
                minId= (arr[i]<arr[i+1])?i:i+1;
            }
           
        }
         cost+=minCost;
            arr.splice(minId, 1);
        
    }
    return cost;
};