#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

void limpaTela(){
    system("CLS");
}
void menuInicial(){




    int opcao = 0;

// Esse while foi colocado antes do menu justamente para que volte nas opçoes caso o usuaruio não digite as opções pedidas
    while(opcao < 1 || opcao > 3){
    limpaTela();
    cout << "Bem vindo ao jogo";
    cout << "\n1 - Jogar";
    cout << "\n2 - Sobre";
    cout << "\n3 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER:";

    cin >> opcao;




    switch(opcao){
        case 1:
            cout << "jogo iniciado";
            break;
        case 2:
            cout << "\nInformacoes do jogo";
            break;
        case 3:
            cout << "\nate mais!\n";
            break;
    }
  }
}


int main(){

    menuInicial();
    //limpaTela();

    return 0;
}
