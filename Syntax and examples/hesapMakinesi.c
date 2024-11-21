#include <stdio.h>


double hesapMakinesi(char op , double num1 , double num2 , double result){
    switch (op){
        case '+':
            return num2,num1+num2;
            break;
        case '-':
            return num1-num2;
            break;
        case '*':
            return num1*num2;
            break;
        case '/':
            return num1/num2;
            break;
        default:
            printf("Geçersiz operatör!");
            return 0;
    }
}

// IF BLOKLARIYLA DA YAP


int main(){
    char op;
    double num1,num2,result;

    printf("Birinci sayıyı girin :");
    scanf("%lf",&num1);

    printf("İkinci sayıyı girin : ");
    scanf("%lf",&num2);

    printf("İşlem türünü seçiniz (+,-,*,/) : ");
    scanf(" %c",&op);

    result =  hesapMakinesi(op,num1,num2,result);

    printf(" Cevap : %.2f ",result);

    return 0 ;
}


