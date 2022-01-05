isPalindrome = function (str){
  for (let i = 0; i <=  Math.floor(str.length / 2); i++){
    if (str[i] != str[str.length-1-i]) return false;
  }
  return true;
}

exports.createPartitions = function (str, partitions, index, result){
  if (index == str.length){
    const palindromes = [...partitions];
    result.push(palindromes);
    return;
  }

  let aux = "";
  for ( let i = index; i < str.length; ++i ){
    aux += str[i];
    if (isPalindrome(aux)){
      partitions.push(aux);
      exports.createPartitions(str, partitions, i+1, result);
      partitions.pop();
    }
  }
}
