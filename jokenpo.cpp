//Pedra, papel e tesoura em C++
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Obtém o movimento do computador
char getComputerMove()
{
    int move;
    // Gera um número aleatório entre 0 e 2
    srand(time(NULL));
    move = rand() % 3;

    // Retorna o movimento baseado em qual número foi gerado anteriormente
    if (move == 0) {
        return 'p';
    }
    else if (move == 1) {
        return 's';
    }
    return 'r';
}

// Resultado do jogo
int getResults(char playerMove, char computerMove)
{
    // Condição de empate
    if (playerMove == computerMove) {
        return 0;
    }

    // Condição de vitória/derrota
    if (playerMove == 's' && computerMove == 'p') {
        return 1;
    }
    if (playerMove == 's' && computerMove == 'r') {
        return -1;
    }
    if (playerMove == 'p' && computerMove == 'r') {
        return 1;
    }
    if (playerMove == 'p' && computerMove == 's') {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 'p') {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 's') {
        return 1;
    }
    
    return 0;
}

// Código principal
int main()
{

    char playerMove;

    cout << "\nBem-vindo ao Jokenpo, também conhecido como Pedra, Papel e Tesoura!\n";

    cout << "\nEscolha quantas vezes quer jogar\n";
    int numPlay;
    cin >> numPlay;

    //Cria um laço de repetição de quantas vezes o jogador quer jogar
    for (int i = 0; i < numPlay; i++) { 
        cout << "\nAperte r para Pedra, p para Papel e s para Tesoura\n";

        while(true) {
            cin >> playerMove;

            if (playerMove == 'r' || playerMove == 'p' || playerMove == 's') {
                break;
            }
            else {
                cout << "Movimento inválido! Insira um caractere válido." << endl;
            }
        }
    
        // Movimento do computador
        char computerMove = getComputerMove();
        int result = getResults(playerMove, computerMove);

        // Mostra o resultado do jogo
        if (result == 0) {
            cout << "\nEmpate!\n";
        }
        else if (result == 1) {
            cout << "\nParabéns! Você venceu!\n";
        }
        else {
            cout << "\nVitória do computador!\n";
        }

        // Mostra ambas as jogadas
        cout << "Seu movimento: " << playerMove << endl;
        cout << "Movimento do computador: " << computerMove << endl;
        }

    return 0;
}