#include <iostream>
#include <stack>
#include <string>

void menu();
void adicionar();
void remover();
void mostrar();

std::stack<int> pilha;

/* "tamanho" Define o número de elementos da pilha/stack a serem adicionados */
int tamanho = 5;

int main() {
    menu();
    return 0;
}

/* Loop para o menu funcionar */
void menu() {
    int opcao = 0;
    bool continua = false;

    do {
        std::cout << "O que deseja fazer com a pilha?\nOpcoes validas:\n 1: Adicionar\n 2: Remover\n 3: Mostrar\n";
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            adicionar();
            break;
        case 2:
            remover();
            break;
        case 3:
            mostrar();
            break;
        default:
            std::cout << "Opcao invalida\n";
        }

        std::string input;

        do {
            std::cout << "Deseja fazer outra coisa? y/n\n";
            std::cin >> input;
        } while ((input != "y") && (input != "n"));

        if (input == "n") {
            std::cout << "Programa encerrado\n";
            continua = false;
        }
        else {
            continua = true;
        }

    } while (continua);
}

/* Adiciona os valores à pilha, de acordo com o a variável 'tamanho' */
void adicionar() {
    int num = 0;

    for (int i = 0; i < tamanho; i++) {
        std::cout << "Digite o " << i + 1 << " elemento: ";
        std::cin >> num;
        pilha.push(num);
    }

    std::cout << "Elementos adicionados com sucesso.\n";
}

/* Remove o elemento do topo (último a entrar) */
void remover() {
        if (!pilha.empty()) {
            std::cout << "Removendo o elemento " << pilha.top() << "\n";
            pilha.pop();
        }
        else {
            std::cout << "A pilha esta vazia.\n";
        }
    }

/* Printa os elementos da stack */
void mostrar() {
    std::cout << "Elementos na pilha:\n";
    std::stack<int> temp;

    while (!pilha.empty()) {
        std::cout << pilha.top() << "\n";
        temp.push(pilha.top());
        pilha.pop();
    }

    while (!temp.empty()) {
        pilha.push(temp.top());
        temp.pop();
    }
}
