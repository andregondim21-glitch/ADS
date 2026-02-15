#include <stdio.h>
int potencia (int x, int y){
    if(y == 0) return 1;
    else return potencia(x,y-1)*x;
}
int main() {
    int x=1, y=0;
    printf("Digite o valor da base: ");
    scanf("%d",&x);
    printf("\nDigite o valor do expoente: ");
    scanf("%d",&y);
    printf("%d elevado a %d é igual a %d",x,y,potencia(x,y));
}
