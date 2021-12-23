exports.createSieve = function (SUP_LIMIT){
  let sieve = Array(SUP_LIMIT).fill(true);
  for (let i of sieve.keys()){
    i += 2;
    if ( sieve[i] )
      for (let j = i * 2 ; j <= SUP_LIMIT; j += i)
        sieve[j] = false;
  }
  return sieve;
}

exports.countPrimes = function (start, finish, sieve){
  if (start < 2) start = 2;
  let num_primes = 0;
  for (let i = start; i <= finish; ++i)
   if (sieve[i]) ++num_primes; 
  return num_primes;
}