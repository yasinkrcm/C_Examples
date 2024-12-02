#include <stdio.h>

void printArray();
void findMinMax(); 


int main(){
    int n;

    printf("Dizinin eleman sayısı : ");
    scanf("%d",&n);

    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        int a;
        printf("Listenin %d. elemanını giriniz : ",i+1);
        scanf("%d",&a);
        arr[i] = a;
    }
    findMinMax(arr,n);
    return 0 ;
}


void printArray(int arr[] , int n){
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("Listenin %d. elemanı : %d \n",i+1,arr[i]);
}

void findMinMax(int arr[] , int n){
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n ; i++)
    {
        if (arr[i]>max)
            max = arr[i];
        else if (arr[i]<min)
            min = arr[i];
    }
    printf("Dizideki min değer : %d\n",min);
    printf("Dizideki max değer : %d\n",max);
}

