#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i=0; i<= n-2; i++){    //n-2 passes
        for (int j =0; j<=n-1; j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main() {
   int a[8] = {6,9,2,0,-5,4,1,1};
   bubbleSort(a,8); //bubble sort works properly and updates the elements 
   for(int i=0; i<8; i++){
        cout<<a[i]<<" ";
   }
}
