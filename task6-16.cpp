#include <iostream>
using namespace std;
template <class T> void selectSort(T a[], int size) {
  T x;
  for (int i = 0; i < size; i++) {
    int k = i;
    x = a[i];
    for (int j = i + 1; j < size; j++) {
      if (a[j] < x) {
        k = j;
        x = a[j];
      }
    }
    a[k] = a[i];
    a[i] = x;
  }
}

int main(){
  cout << "Sort for int" << endl;
  int arr[] = {1, 2, 0, -1};
  for (int i = 0; i < 4; i++) {
    cout << arr[i] << endl;
  }
  cout << "----------" << endl;
  selectSort(arr, 4);
  for (int i = 0; i < 4; i++) {
    cout << arr[i] << endl;
  }
  cout << "Sort for float" << endl;
  float arrr[] = {1.1, 5.2, 4.9};
  for (int i = 0; i < 3; i++) {
    cout << arrr[i] << endl;
  }
  selectSort(arrr, 3);
  cout << "-----------" << endl;
  for (int i = 0; i < 3; i++) {
    cout << arrr[i] << endl;
  }
  return 0;
}
