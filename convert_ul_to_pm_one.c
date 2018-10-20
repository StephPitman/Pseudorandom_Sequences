//input: int buffer of size n for output, size n of the integer to covert, and unsinged long integer to convert

//used https://stackoverflow.com/questions/31577866/c-convert-integer-to-binary-array as refrence
void ul_tp_pmone(int *buf, int n, unsigned long i){
  unsigned int mask = 1U << (n-1);
  for (int j=0;j<n;j++){
    buf[j]= (i & mask) ? 1 : -1;
    i <<= 1;
  }
  
}
