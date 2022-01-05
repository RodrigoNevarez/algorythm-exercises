const {createPartitions} = require("./palindromePartitioning");

str = "abbba";
result = [];

createPartitions(str, [], 0, result);
console.log(result);