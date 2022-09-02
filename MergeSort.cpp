// Emma Gabriela Alfaro de la Rocha
// Emmanuel Humberto Solórzano Cabrera
// Maximiliano Villegas García
// Pablo Gutiérrez Costales 
#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r){
  
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++){
     L[i] = A[p + i];
  }
  for (int j = 0; j < n2; j++){
     R[j] = A[q + 1 + j];
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
    A[k] = L[i];
    i++;
  } else {
    A[k] = R[j];
    j++;
  }
  k++;
}

  while (i < n1){
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){
    A[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int A[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
  }
}

void printArray(int A[], int size) {
  for (int i = 0; i < size; i++){
    cout << A[i] << " ";
  }  
  cout << endl;
}

int main() {
  int A[] = {7, 1, 17, 9, 21, 2}; //{6, 5, 12, 10, 9, 1}; //{10, 40, 31, 1, 13, 7, 25};
  int size = sizeof(A) / sizeof(A[0]);

  mergeSort(A, 0, size - 1);

  cout << "Arreglo Ordenado: \n";
  printArray(A, size);
  return 0;
}