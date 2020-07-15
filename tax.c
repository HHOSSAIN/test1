#include <stdio.h>
#include <stdlib.h>

#define Rate0 0.000
#define Rate1 0.190
#define Rate2 0.325
#define Rate3 0.370
#define Rate4 0.450
#define RateM 0.015

#define Thresh1 18200.00
#define Thresh2 37000.00
#define Thresh3 80000.00
#define Thresh4 180000.00

#define Base0 0.00
#define Base1 (Base0 + Rate0*Thresh1)
#define Base2 (Base1 + Rate1*(Thresh2 - Thresh1))
#define Base3 (Base2 + Rate2*(Thresh3 - Thresh2))
#define Base4 (Base3 + Rate3*(Thresh4 - Thresh3))

int main(){
    double gross, tax, medicare, net;
    printf("Enter gross: $");
    if (scanf("%lf", &gross) != 1){
        printf("No value entered\n");
        exit(EXIT_FAILURE);
    }
    if(gross <= Thresh1){
        tax = Base0 + gross*Rate0;
    }
    else if (gross <= Thresh2){
        tax = Base1 + (gross - Thresh1)*Rate1;
    }
    else if (gross <= Thresh3){
        tax = Base2 + (gross - Thresh2)*Rate2;
    }
    else if (gross <= Thresh4){
        tax = Base3 + (gross - Thresh3)*Rate3;
    }
    else {
        tax = Base4 + (gross - Thresh4)*Rate4;
    }
    medicare = RateM*gross;
    net = gross - tax - medicare;
    printf("gross income     $%9.2f\n", gross);
    printf("less tax         $%9.2f\n", -tax);
    printf("less medicare    $%9.2f\n", -medicare);
    printf("net income       $%9.2f\n", net);
    return 0;
}
