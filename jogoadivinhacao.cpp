#include <iostream> //fluxo de entrada e saída de dados
#include <cstdlib> //biblioteca com funcoes padroes
#include <ctime> //biblioteca com funcoes de tempo

// standard -- > std:: (função padrão de C++)
using namespace std;


int main(){
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;
    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    // variaveis constantes devem estar em caixa alta >> boa pratica
    // nao eh possivel modificar uma variavel constante
    srand(time(NULL)); //a funcao time(NULL) seta o numero de segundos a partir de 1970, logo sempre vai mudar
                       //a funcao srand gera um SEED (pseudoaleatorio) a partir de uma entrada
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0; //tipo da variavel Real

    //inicia com 1 tentativa, enquanto for menor, adiciona um no contador
    for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute: " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0; //atencao aos tipos das variaveis e os restos
        pontos -= pontos_perdidos;

        // eh boa pratica abstrair as condicoes em variaveis
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas." << endl;  
        cout.precision(2); //seta a precisao de 2 casas decimais
        cout << fixed; //fixa a virgula da saida da proxima variavel numerica, se nao uso isso, o padrao eh imprimir em notacao cientifica
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
}