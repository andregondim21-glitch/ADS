#include <stdio.h>
int fibonacci (int n){
    if(n <= 3) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    int n=0;
    printf("Digite o números da sequêcia de Fibonacci que deseja ver (>2): ");
    scanf("%d",&n);
    if(n <= 2) printf("Número digitado menor que 2!!!");
    else printf("%d",fibonacci(n));

}
