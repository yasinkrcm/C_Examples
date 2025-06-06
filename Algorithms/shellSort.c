#include <stdio.h>

int shell(int a[],int n){
    for(int interval = n/2 ; interval>0; interval /= 2){
        for(int i = interval ; i<n ;i+=1){
            int temp = a[i];
            int j ;

            for(j = i ; j >= interval && a[j - interval] > temp;j-=interval)
                a[j] = a[j-interval];
                a[j] = temp;
        }
    }
    return 0;
}
void printArr(int a[], int n){
    for(int i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int a[] = {33,31,40,8,12,17,25,42};
    int n = sizeof(a)/sizeof(a[0]);
    
    printf("Sıralanmadan önceki liste : ");
    printArr(a,n);

    shell(a,n);
    printf("Sıralandıktan sonraki liste : ");
    printArr(a,n);
    
    return 0;

}