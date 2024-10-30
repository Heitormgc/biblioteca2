#include <iostrean>
#include <cstdio>

using namespace std;

struct emprestimo {
    char dt_emp[10], dt_dev[10], usuarios[255];
};

struct livros {
    int codigo, paginas;
    char area[255], titulo[255], autores[255], editora[255];
    struct emprestimo emp;
};


struct livros livro;