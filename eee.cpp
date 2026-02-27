#include <iostream>
#include <string> // permite usar string


class Livro {
private: /// encapsulamento, ou seja, TUDO QUE VEM ABAIXO SÓ PODE SER ACESSADO DENTRO DESSA CLASSE
    std::string titulo;
    std::string autor;
    float preco;

public:
    // Construtor com REFERÊNCIA
    Livro(const std::string& t, const std::string& a, float p) // Const vai manter od dados de forma integra, sem permitir mudanças
    // & comercial vai servir para que as strings não sejam apenas copiadas e assim eles irão recebe-la
        : titulo(t), autor(a), preco(p) {}

    // Método CONST (não altera o objeto)
    void exibir() const { //void porque ele nãon irá receber, apenas exibir 
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Preco: R$ " << preco << std::endl;
    }
// metodo get serve para permitir que outras partes do programa vejam o título,
//mas sem poder alterar.
    std::string getTitulo() const { 
        return titulo;
    }
};

void cadastrarLivro(Livro* livros[], int& qtd) { //estamnos recebendo um vetor de ponteiros para Livros
//livros[]:? é uma liosta e cada posição vai guardar o endereço de um livro, ou seja, guarda o ponteiro
// int& qtd: estamos trabalhando c variavel qtd que etsá no main.


    if(qtd >= 20) { //limite de livros cadastrados 
        std::cout << "Limite atingido.\n";
        return;
    }

    std::string titulo, autor;
    float preco;

    std::cin.ignore();

    std::cout << "Titulo: ";
    getline(std::cin, titulo);

    std::cout << "Autor: ";
    getline(std::cin, autor);

    std::cout << "Preco: ";
    std::cin >> preco;

    livros[qtd] = new Livro(titulo, autor, preco); //new vai servir para sempre que o code der uma volta, criar um novo espaço na memoria p aquek livro/autor/preço
    qtd++;
    //tradução: Pegue o endereço retornado pelo new -> guarde na posição qtd do vetor
}

class ListarLivros {
public:
    void executar(Livro* livros[], int qtd) {

        if(qtd == 0) {
            std::cout << "Nenhum livro cadastrado.\n";
            return;
        }

        for(int i = 0; i < qtd; i++) {
            livros[i]->exibir();
            std::cout << "-------------------\n";
        }
    }
};

void comprarLivro(Livro* livros[], int qtd) {

    if(qtd == 0) {
        std::cout << "Nenhum livro disponivel.\n";
        return;
    }

    int escolha;

    std::cout << "\nEscolha o numero do livro:\n";

    for(int i = 0; i < qtd; i++) {
        std::cout << i << " - "
                  << livros[i]->getTitulo()
                  << std::endl;
    }

    std::cin >> escolha;

    if(escolha >= 0 && escolha < qtd) {
        std::cout << "Voce comprou: "
                  << livros[escolha]->getTitulo()
                  << std::endl;
    } else {
        std::cout << "Opcao invalida.\n";
    }
}


int main() {

    Livro* livros[20];   // vetor de ponteiros
    int qtd = 0;
    int opcao;

    do {
        std::cout << "\n===== ACERVO DE LIVROS =====\n";
        std::cout << "1 - Cadastrar livro\n";
        std::cout << "2 - Mostrar livros\n";
        std::cout << "3 - Comprar livro\n";
        std::cout << "0 - Sair\n";
        std::cout << "Opcao: ";

        std::cin >> opcao;

        switch(opcao) {

            case 1:
                cadastrarLivro(livros, qtd);
                break;

           case 2: {
                ListarLivros listar;
                listar.executar(livros, qtd);
                break;
            }
            case 3:
                comprarLivro(livros, qtd);
                break;

            case 0:
                std::cout << "Saindo...\n";
                break;

            default:
                std::cout << "Opcao invalida.\n";
        }
    

    } while(opcao != 0);

    // Liberando memória
    for(int i = 0; i < qtd; i++) {
        delete livros[i];
    }    
    return 0; 
}