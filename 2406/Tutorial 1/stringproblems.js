function landscape() {
  let result1 = "";
  let result2 = "";

  function flat(size) {
    for (let count = 0; count < size; count++){
      result1 += "_";
      result2 += " ";
	}
  }

  function hill(size) {
    result1 += "/";
    result2 += " ";
    for (let count = 0; count < size; count++){
      result2 += "_";
      result1 += " ";
	}
    result1 += "\\";
    result2 += " ";
  }

  //START BUILD SCRIPT
  flat(3);
  hill(4);
  flat(6);
  hill(1);
  flat(1);
  //END BUILD SCRIPT
  let result = result2 + "\n" + result1
  return result

}

console.log("")
console.log(landscape())
