#include <stdio.h>
#include <math.h>
typedef enum { false, true } bool;

//input: int buffer of size n for output, size n of the integer to covert, and unsinged long integer to convert

//used https://stackoverflow.com/questions/31577866/c-convert-integer-to-binary-array as refrence
void ul_to_pmone(int *buf, int n, unsigned long i){
  unsigned int mask = 1U << (n-1);
  for (int j=0;j<n;j++){
    buf[j]= (i & mask) ? 1 : -1;
    i <<= 1;
  }

}

int test_t(int *E, int E_n, int M, int *X, int X_n){
  int count = 0;
  bool good = true;
  int k = X_n;
//  printf("k %d\n",k);
  for(int n=0;n < M; n++){
    for (int i=0;i<k;i++){
      if (E[n+i]!=X[i]){
        good = false;
      }
    }
    if (good == true){
      count++;
    }
    good = true;
  }
  return count;
}



bool check_pseudo(int *E, int N){
  int num=0;
  int max_k = (int) log2(N);
  for(int k=1; k<max_k;k++){
    int buf[k];
    int end = pow(2,k);
//    printf("end %d\n",end);
    for (int i=0;i<end;i++){
      ul_to_pmone(buf,k,i);
      num=test_t(E, N, N+1-k, buf, k);
      float left = fabs(num-(N+1-k)/end);
//      printf("left = %f ",left);
      float right = 1/sqrt(N);
//      printf("right = %f\n",right);
      if (left>right){
        return false;
      }
    }
  }
  return true;
}

int main(void) {
  int n = 11;
  int buf[n];
  long end = pow(2,n);
  for (unsigned long i=0;i<end;i++){
    ul_to_pmone(buf, n, i);
    if (check_pseudo(buf, n)==true){
//    	int d=(int) i;
//    	printf("sequence 1 %d \n",d);
    	for(int j=0; j<n;j++){
    		printf("%d",buf[j]);
    	}
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}

