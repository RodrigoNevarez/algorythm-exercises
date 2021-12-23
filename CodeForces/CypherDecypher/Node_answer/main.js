LIM_SUP = 100;
const prompt = require('prompt-sync')();
const {createSieve} = require("./sieve");
const {countPrimes} = require("./sieve");


let criba = createSieve(LIM_SUP);
let i, j = 0;
let T = prompt("What is the number of tests? ");
for (let c = 1; c <= T; ++c) {
  i = prompt("Inicio: ");
  j = prompt("Fin: ");
  console.log(`Primos: ${countPrimes(i, j, criba)}`);
}
