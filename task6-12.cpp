#include <iostream>
#include <string.h>
#include <time.h>

using  namespace std;

template <typename T>
bool are_equal(T *a, T *b, int size){
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]){
      return 0;
    }
  }
  return 1;
}

bool are_equal(char* a, char* b){
  return (strcmp(a,b) == 0);
}


int main() {
  int arr[6], arrr[6];
  char *a, *b;
  char c[10] = "123456789",d [10] = "123456789";
  a = new char[10];
  strcpy(a, "abcdefght");
  b = new char[10];
  strcpy(b, "abcdefgaa");
  for (int i = 0; i < 6; i++) {
    i[arr] = 0;
  };
  for (int i = 0; i < 6; i++) {
    i[arrr] = 0;
  };
  cout << "Are arr and arrr equal ? :" << are_equal(arr, arrr, 6) << endl;
  arr[2] = 123456;
  cout << "Are arr and arrr equal ? :" << are_equal(arr, arrr, 6) << endl;
  cout << "Are char* a and b equal ? :" << are_equal(a, b, 10) << endl;
  cout << "Are char arrrays c and d equal ? :" << are_equal(c, d, 10) << endl;
  c[0] = 'a';
  cout << "Are char arrrays c and d equal ? :" << are_equal(c, d, 10) << endl;
  return 0;
}
