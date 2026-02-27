📚 Documentação Técnica – Sistema de Cadastro de Livros em C++
📌 Visão Geral do Sistema

O programa implementa um pequeno sistema de gerenciamento de livros utilizando:

Programação Orientada a Objetos (POO)

Ponteiros

Referências

Constantes (const)

Alocação dinâmica de memória (new / delete)

O sistema permite:

Cadastrar livros

Listar livros

Comprar livros

Liberar memória ao final do programa

🧱 1. Programação Orientada a Objetos (POO)

A POO é aplicada principalmente através da classe Livro.

📌 Classe Livro
class Livro {
private:
    std::string titulo;
    std::string autor;
    float preco;

public:
    Livro(const std::string& t, const std::string& a, float p);
    void exibir() const;
    std::string getTitulo() const;
};
🔐 Encapsulamento
private:
    std::string titulo;
    std::string autor;
    float preco;

Esses atributos são privados.

Isso significa que:

Eles só podem ser acessados dentro da própria classe.

Não podem ser modificados diretamente fora da classe.

Isso protege os dados contra alterações indevidas.

🏗 Construtor
Livro(const std::string& t, const std::string& a, float p)
    : titulo(t), autor(a), preco(p) {}

Função do construtor:

Inicializar o objeto no momento da criação.

Garantir que todo livro tenha título, autor e preço.

O uso de lista de inicialização (: titulo(t)) é mais eficiente que atribuição dentro do corpo.

🔎 Método exibir()
void exibir() const

Não altera o objeto.

Apenas exibe informações.

O const garante que os atributos não serão modificados.

🔓 Método getTitulo()
std::string getTitulo() const

Permite acessar o título sem permitir modificação.

Isso mantém o encapsulamento seguro.

👉 2. Ponteiros no Código

Ponteiros armazenam endereços de memória.

📌 Onde os ponteiros aparecem?
1️⃣ Vetor de ponteiros
Livro* livros[20];

Isso significa:

livros é um vetor com 20 posições.

Cada posição armazena um ponteiro para Livro.

Cada posição guarda o endereço de um objeto criado com new.

Visualmente:

livros[0] → endereço do Livro A
livros[1] → endereço do Livro B
2️⃣ Alocação dinâmica
livros[qtd] = new Livro(titulo, autor, preco);

O new:

Cria o objeto na memória heap.

Retorna o endereço do objeto.

Esse endereço é armazenado no vetor.

Sem new, o objeto morreria ao sair da função.

3️⃣ Acesso via ponteiro
livros[i]->exibir();

O operador ->:

Acessa membros do objeto através do ponteiro.

Equivale a:

(*livros[i]).exibir();
4️⃣ Liberação de memória
delete livros[i];

Isso é obrigatório porque usamos new.

Sem delete, ocorreria vazamento de memória (memory leak).

🔁 3. Referências (&)

Referências permitem acessar uma variável original sem copiar.

📌 Referência no construtor
Livro(const std::string& t, const std::string& a, float p)

Por que usar referência?

Evita cópia da string

Melhora desempenho

Mantém integridade dos dados

Sem referência, a string seria copiada ao passar como argumento.

📌 Referência na função cadastrarLivro
void cadastrarLivro(Livro* livros[], int& qtd)

int& qtd significa:

Estamos usando a variável original do main.

Alterações feitas dentro da função afetam o valor no main.

Se fosse:

int qtd

Estaria trabalhando com uma cópia.
O valor original não seria alterado.

🛡 4. Constantes (const)

const impede modificações indevidas.

📌 1️⃣ Const nos parâmetros
const std::string& t

Garante que:

A string não será modificada dentro do construtor.

📌 2️⃣ Const nos métodos
void exibir() const

Isso significa:

O método não altera o estado do objeto.

Pode ser chamado em objetos constantes.

Sem esse const, o compilador pode impedir certas chamadas.

📌 3️⃣ Segurança adicional

O uso correto de const:

Previne erros

Deixa o código mais confiável

Ajuda o compilador a otimizar

🔄 5. Fluxo de Memória do Programa

O programa inicia

livros é criado como vetor de ponteiros

Ao cadastrar:

new Livro(...) cria objeto na heap

Endereço é armazenado no vetor

Ao listar:

Acessa objeto via ->

Ao sair:

delete libera cada objeto

⚙ 6. Relação Entre os Conceitos
Conceito	Onde aparece	Função
POO	Classe Livro	Organização e encapsulamento
Ponteiros	Livro* livros[20]	Armazenar objetos dinamicamente
new / delete	Cadastro e final do main	Controle manual de memória
Referência &	int& qtd	Alterar variável original
const	Construtor e métodos	Segurança e imutabilidade
🧠 7. Por que esse modelo é importante?

Esse código ensina fundamentos essenciais de C++:

Gerenciamento manual de memória

Diferença entre stack e heap

Encapsulamento

Segurança com const

Eficiência com referências

Uso correto de ponteiros

🚀 8. Possível Evolução do Código

Em projetos mais modernos, seria recomendado usar:

std::vector ao invés de array fixo

std::unique_ptr ao invés de new e delete

Separação em arquivos .h e .cpp

Mas para aprendizado, seu código está excelente para entender base estrutural da linguagem.
