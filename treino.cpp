#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

struct emprestimo {
    char dt_emp[10], dt_dev[10], usuarios[255];
};

struct livros {
    int codigo, paginas;
    char area[255], titulo[255], autores[255], editora[255];
    struct emprestimo emp;
};

int opcPrinc;
char opcSecun;
FILE *arq;
struct livros liv;

int main(){
    do {
        cout << "1- Cadastro" << endl;
        cout << "2- Emprestimo" << endl;
        cout << "3- Devolução" << endl;
        cout << "4- Alteração" << endl;
        cout << "5- Exclusão" << endl;
        cout << "6- Consulta de livros" << endl;
        cout << "7- Livros disponíveis" << endl;
        cout << "8- Listagem geral de livros" << endl;
        cout << "9 - Sair" << endl;
        cout << "Escolha uma opção!" ;
        cin >> opcPrinc;

        switch (opcPrinc)
        {
        case 1:
            cout << "Deseja cadastrar um livro(S ou N)?";
            cin >> opcSecun;
            while (opcSecun == 'S' || 's'){
                cout << "Digite o código do livro da catalogação";
                cin >> liv.codigo;
                cout << "Digite a área de atuação do livro";
                cin.get(liv.area, 255);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Digite o título da obra";
                cin.get(liv.titulo, 255);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Digite os autor(es) do livro";
                cin.get(liv.autores, 255);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Digite o nome da editora";
                cin.get(liv.editora, 255);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Agora digite o número de páginas";
                cin >> liv.paginas;

                if (arq != NULL){

                } else {
                    cout << "Não foi possível acessar os arquivos";
                }
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            cout << "Código" << liv.codigo;
            cout << "Área" << liv.area;
            cout << "Título" << liv.titulo;
            cout << "Autor(es)" << liv.autores;
            cout << "Editora" << liv.editora;
            cout << "Número de páginas" << liv.paginas;

            if {arq != NULL}{

            } else {
                cout << "Não foi possível acessar os arquivos";
            }
         
            break;
        case 9:
        cout << "Obrigado por usar nosso sistema";
            break;
        
        default:
            break;
        }
    cout << "\e[2J" << "\e[0;0";
    } while(opcPrinc != 9);
}