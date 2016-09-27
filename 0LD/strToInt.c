/*strToInt function*/
//Return a int when given a str.

int strToInt(char* num){

  int i = 0;
  int val=0;
  
  while (num[i] != '\0') {//Go through all the char
    if (num[i]<48 || num[i]>57) {//Check that the string is a number
      return -1; //ERROR
    }
    
    val=10*val+(num[i]-48);//Convert code ASCII in int
    i++;
   }
  return val;
}
