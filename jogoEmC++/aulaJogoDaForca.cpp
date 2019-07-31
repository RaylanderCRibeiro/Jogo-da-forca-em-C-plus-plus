#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatorio(){


        //vetor de palavras em c++ com plavras disponiveis
    string palavras[3] = ("abacaxi", "manga", "morango");
    //indice gerado no intervalo dividido por 3
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];

}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    int cont = 0;
    string palavraComMascara;
    //coloca a mascara
    while (cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}
void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagens){
    cout << mensagens;
    cout << "\npalavra:" << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;
    cout << "\nLetras arriscadas:" << letrasJaArriscadas;

    int cont;
    cout << "\nLetras Arriscadas:";
    for(cont = 0; cont < letrasJaArriscadas.size();cont++){
        cout << letrasJaArriscadas[cont] << ",";
    }
}

void jogarSozinho(){
    //cout << palavras[indiceAleatorio];

    string palavra = retornaPalavraAleatorio();

    //tamanho da palavra
    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);
     ///variaveis principais
    int cont = 0;
    int tentativas = 0, maximoDeTentativas = 7; // numero de tentativas
    char letra;   //letra arriscada pelo o usuario
    string letrasJaArriscadas;              //Acumula expectativas do jogador
    string mensagens = "Bem vindo ao Jogo!";                       //feedback do jojgar
    bool jaDigitouLetra = false;           //Auxiliar para ver se já digitou a letra


    while (palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){
//tirei o limpa tela para exixibir as letras ja digitadas
      limpaTela();

        //Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas,letrasJaArriscadas,mensagens);

    //cout << "A palavra Secreta eh:" << palavra << "(Tamanho:" << tamanhoDaPalavra << ")";
    //cout << "\nMascara:" << palavraComMascara;
    //cout << "\nTentativas Restantes:" << maximoDeTentativas - tentativas;

    cout << "\nDigite uma letra:";
    cin >> letra;

    // percorre as letras ja arriscadas
    for (cont = 0; cont < tentativas; cont++){

        //verifico se encontrar a letra
        if (letrasJaArriscadas[cont] == letra){

         mensagens = "\nEssa Letra ja foi Digitada!!";
          //indica uma variavel booleana
           jaDigitouLetra = true;
        }
    }

    //se for uma letra nova
    if (jaDigitouLetra == false){


        letrasJaArriscadas += letra;

        for(cont = 0; cont < tamanhoDaPalavra; cont++ ){

            if(palavra[cont] == letra){

                palavraComMascara[cont] = palavra[cont];

                mensagens = "Voce acertou uma letra!";
            }

        }

   /* }

    letrasJaArriscadas += letra;
        //percorre a palavra a palavra real e se a letra existir muda a palavra com mascara
    for(cont = 0; cont < tamanhoDaPalavra; cont++){

        //se a letra existir na palavra escondido faremos aparecer a letra na palavra com mascara
        if(palavra[cont] == letra){

                palavraComMascara[cont] = palavra[cont];
        }

    }
*/

    tentativas++;
    }
}

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "\nparabens, você venceu!\n";

    }else{

        limpaTela();
        cout << " \nbleeh, você perdeu!\n";
    }
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
            //cout << "jogo iniciado";
            jogarSozinho();
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


    //gera numero aleatorio
    srand( (unsigned) time(NULL));

    menuInicial();
    //limpaTela();

    return 0;
}

