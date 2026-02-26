#include <iostream>
#include <string> // permite usar string


class Livro {
private:
    // atributos privados 
    std::string titulo;
    std::string autor;
    float preco;

public:
    // garante que todo livro já nasce com dados
    Livro(std::string t, std::string a, float p) {
        titulo = t;
        autor = a;
        preco = p;
    }

    // método CONST
    // NÃO alterar o objeto
    void exibir_informacoes() const {
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Preco: R$ " << preco << std::endl;
    }

    // getters const irão preservar os dados e apenas deixar que o usuario veja, nunca altere
    float getPreco() const {
        return preco;
    }

    std::string getTitulo() const {
        return titulo;
    }
};
class VisualizarAcervo (){
    std::cout << "\n--- LISTA DE LIVROS ---\n";

            for(int i = 0; i < qtd_livro; i++) {

                // acessando objeto através do ponteiro
                livro_ptr[i]->exibir_informacoes(); //Pega o ponteiro armazenado na posição i. acessar algo dentro do objeto apontado. resumindo:
                //vá até o endereço do livroe e execute o método exibir_informacoes()
                std::cout << "-------------------\n";
            }
            break;
}

int main() {

    // vetor de PONTEIROS para Livro, apenas para limitar a quantidade
    // cada posição guardará o ENDEREÇO de um livro criado com new(vai servir para que cada coisa nova adiconada tenha seu devido lugar na memoria a partir do uso do vetor)
    Livro* livro_ptr[20];

    int qtd_livro = 0; // quantidade atual cadastrada
    int opcao_user;

    // menu repetindo até usuário sair
    do {

        std::cout << "\n===== ACERVO DE LIVROS =====\n";
        std::cout << "1 - Cadastrar livro\n";
        std::cout << "2 - Mostrar livros\n";
        std::cout << "3 - Comprar livro\n";
        std::cout << "0 - Sair\n";
        std::cout << "Opcao: ";

        std::cin >> opcao_user;

   
        switch(opcao_user) {

        
        case 1: {
            if(qtd_livro >= 20) {
                std::cout << "Limite atingido!\n";
                break;
            }

            std::string titulo, autor;
            float preco;

            std::cin.ignore(); // ignora as quebras de linhas do getline

            std::cout << "Titulo: ";
            getline(std::cin, titulo); //std::getline() 
            //no C++ é a forma padrão de ler uma linha inteira de texto, incluindo espaços em branco, 
            //do fluxo de entrada (como cin ou arquivos) até encontrar uma quebra de linha \n

            std::cout << "Autor: ";
            getline(std::cin, autor);

            std::cout << "Preco: ";
            std::cin >> preco;

            livro_ptr[qtd_livro] =
                new Livro(titulo, autor, preco); //new(vai servir para que cada coisa nova adiconada tenha seu devido lugar na memoria a partir do uso do vetor)

            qtd_livro++;

            std::cout << "Livro cadastrado!\n";
            break;
        }

        case 2: {
            if(qtd_livro == 0) {
                std::cout << "Nenhum livro cadastrado.\n";
                break;
            }

            std::cout << "\n--- LISTA DE LIVROS ---\n";

            for(int i = 0; i < qtd_livro; i++) {

                // acessando objeto através do ponteiro
                livro_ptr[i]->exibir_informacoes(); //Pega o ponteiro armazenado na posição i. acessar algo dentro do objeto apontado. resumindo:
                //vá até o endereço do livroe e execute o método exibir_informacoes()
                std::cout << "-------------------\n";
            }
            break;
        }
        case 3: {
            if(qtd_livro == 0) {
                std::cout << "Nenhum livro disponível.\n";
                break;
            }

            int escolha;

            std::cout << "\nEscolha o numero do livro:\n";

            for(int i = 0; i < qtd_livro; i++) {
                std::cout << i << " - "
                          << livro_ptr[i]->getTitulo()
                          << std::endl;
            }

            std::cin >> escolha; //guarda o numero do livro escolhido

            if(escolha >= 0 && escolha < qtd_livro) {
                std::cout << "Voce comprou: "
                          << livro_ptr[escolha]->getTitulo() // aqui ele procura o ntitulo que a pessoa digitoub pelo numero e encontra
                          << std::endl;
            } else {
                std::cout << "Opcao invalida.\n";
            }

            break;
        }

        case 0:
            std::cout << "Encerrando sistema...\n";
            break;

        default:
            std::cout << "Opcao invalida!\n";
        }

    } while(opcao_user != 0);

    
    for(int i = 0; i < qtd_livro; i++) {
        delete livro_ptr[i]; //ao finalizar, limpa tudo para uma nova rodada.
    }

    return 0;
}
