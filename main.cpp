#include <QCoreApplication>
#include <iostream>

using namespace std;

int mass[] = {12,4,1,22,43,67,42,9,61,55,71, 33, 95};
int* bubleSort(int mass[], const size_t n);
int quickSort(int mass[], const size_t n);
int* selectSort(int mass[], const size_t n);
int insertionSort(int mass[], const size_t n);
int merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int f : mass){
        cout<<f<<" ";
    }

    bubleSort(mass,size(mass));

    for(int f : mass){
        cout<<f<<" ";
    }



    return a.exec();
}

int* bubleSort(int mass[], size_t n){
    int a (0);

    for(int i = 0;i<n;i++){
        for(int j = n-1; j>= i+1; j-- ){
           if(mass[j]<mass[j-1]){
               a=mass[j];
               mass[j]=mass[j-1];
               mass[j-1]=a;
           }
        }
    }

    return mass;
}

int quickSort(int mass[], const size_t n){
    int const lenD = n;
     int pivot = 0;
     int ind = lenD/2;
     int i,j = 0,k = 0;
     if(lenD>1){
       int* L = new int[lenD];
       int* R = new int[lenD];
       pivot = mass[ind];
       for(i=0;i<lenD;i++){
         if(i!=ind){
           if(mass[i]<pivot){
             L[j] = mass[i];
             j++;
           }
           else{
             R[k] = mass[i];
             k++;
           }
         }
       }
       quickSort(L,j);
       quickSort(R,k);
       for(int cnt=0;cnt<lenD;cnt++){
         if(cnt<j){
           mass[cnt] = L[cnt];;
         }
         else if(cnt==j){
           mass[cnt] = pivot;
         }
         else{
           mass[cnt] = R[cnt-(j+1)];
         }
       }
     }
    return 0;
}

int* selectSort(int mass[], const size_t n){

    int j = 0;
     int tmp = 0;
     for(int i=0; i<n; i++){
       j = i;
       for(int k = i; k<n; k++){
         if(mass[j]>mass[k]){
           j = k;
         }
       }
       tmp = mass[i];
       mass[i] = mass[j];
       mass[j] = tmp;
     }

    return mass;
}

int insertionSort(int mass[], const size_t n)
{
  int key = 0;
  int i = 0;
  for(int j = 1;j<n;j++){
    key = mass[j];
    i = j-1;
    while(i>=0 && mass[i]>key){
      mass[i+1] = mass[i];
      i = i-1;
      mass[i+1]=key;
    }
  }
  return 0;
}

int merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR){
  int i = 0;
  int j = 0;
  while(i<lenL||j<lenR){
    if (i<lenL & j<lenR){
      if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
      }
      else{
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lenL){
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lenR){
      merged[i+j] = R[j];
      j++;
    }
  }
}






