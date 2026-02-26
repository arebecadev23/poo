#include <iostream>
#include <string> // para usar string

using namespace std;

// Classe Livro
class Livro {
private:
    string titulo;
    string autor;
    float preco;

public:
    // Construtor
    Livro(string t, string a, float p) {
        titulo = t;
        autor = a;
        preco = p;
    }

    // Método constante (não altera o objeto)
    void exibir_informacoes() const {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Preco: " << preco << endl;
    }

    float getPreco() const {
        return preco;
    }

    string getTitulo() const {
        return titulo;
    }
};