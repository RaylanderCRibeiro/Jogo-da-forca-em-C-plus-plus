#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela(){
	system("CLS");
}

int main(){

    int a = 10;
    char palavra[3];
    palavra[0] = 'g';
    palavra[1] = 'o';
    palavra[2] = 'l';

        //printf("\n%c%c%c ", palavra[0], palavra[1]), palavra[2];

        //printf(" O Valor %d eh Maior que 0", a);


        string outraPalavra = "gol";

        //e o mesmo que os printf
        cout << outraPalavra;
      // cout <<"\nO valor de "<< a <<"\ne maior que 0";

    return 0;
}
