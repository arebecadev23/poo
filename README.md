# 📚 Documentação Técnica: Sistema de Cadastro em C++
Este projeto foi desenvolvido como parte dos meus estudos em Ciência da Computação, com o objetivo de aplicar de forma prática os pilares da Programação Orientada a Objetos (POO) e o gerenciamento de memória em baixo nível com C++.

# 🏗️ Arquitetura do Código e Conceitos Aplicados
Abaixo, detalho onde cada conceito fundamental da linguagem foi implementado e o porquê de cada escolha técnica.

## 1. Programação Orientada a Objetos (POO)
O sistema utiliza a classe Livro como molde para a criação de objetos.

Encapsulamento: Os atributos titulo, autor e preco estão na seção private. Isso significa que eles estão protegidos contra acessos externos diretos, garantindo a integridade dos dados através de métodos de interface (public).

Abstração: Criamos uma representação simplificada de um livro real, focando apenas nos dados necessários para o sistema.

Construtor com Lista de Inicialização: ```cpp
Livro(const std::string& t, const std::string& a, float p) : titulo(t), autor(a), preco(p) {}

Diferente da atribuição comum, a **lista de inicialização** define os valores no momento em que o objeto nasce, o que é mais eficiente e recomendado em C++.

## 2. Gestão de Memória com Ponteiros
Ponteiros são utilizados para dar flexibilidade ao armazenamento dos livros.

Vetor de Ponteiros: Livro* livros[20];
Em vez de criar 20 objetos de uma vez na memória Stack (estática), criamos 20 "ponteiros" (endereços). Isso permite que os livros reais sejam criados apenas quando necessário.

Alocação Dinâmica (new):

C++

livros[qtd] = new Livro(titulo, autor, preco);
Aqui o objeto é alocado na Heap. Isso é crucial porque objetos na Heap permanecem vivos até que nós decidamos deletá-los, permitindo que os dados persistam durante toda a execução do menu.

Operador Seta (->): Usado para acessar métodos através de ponteiros, como em livros[i]->exibir();. Ele faz o trabalho de desreferenciar o endereço e chamar a função do objeto.

## 3. Uso Estratégico de Referências (&)
As referências foram usadas para otimizar o desempenho e permitir a modificação de variáveis globais.

Evitando Cópias: No construtor, usamos const std::string& t. Sem o &, o C++ criaria uma cópia inteira do texto na memória toda vez que cadastrássemos um livro. Com a referência, trabalhamos direto com o dado original.

Modificação de Variáveis (Passagem por Referência):

C++

void cadastrarLivro(Livro* livros[], int& qtd)
Ao usar int& qtd, a função não recebe uma cópia do número de livros, mas sim o acesso à variável real que está dentro do main. Assim, quando aumentamos qtd++ dentro da função, o main fica sabendo imediatamente.

## 4. Segurança com Constantes (const)
O modificador const foi aplicado como uma "trava de segurança" em três níveis:

Parâmetros de Entrada: Impede que o construtor altere o título ou autor recebido.

Métodos de Leitura: void exibir() const;
Isso avisa ao compilador que a função exibir garante que não vai mudar o preço ou o nome do livro, apenas mostrar. Isso evita bugs acidentais.

Integridade: Ajuda na otimização do compilador e torna o código mais legível para outros desenvolvedores.

# 🛠️ Fluxo de Execução
Início: O programa reserva espaço para 20 endereços de memória.

Cadastro: O usuário digita os dados -> O new reserva um espaço na Heap -> O endereço desse espaço é guardado no vetor.

Listagem: O código percorre o vetor, segue os endereços (ponteiros) e chama o método exibir() de cada objeto.

Finalização: O programa executa um loop de delete, limpando a memória Heap e evitando o uso desnecessário de RAM do computador.
