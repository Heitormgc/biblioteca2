#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>

using namespace std;

struct emprestimo
{
    char dt_emp[10], dt_dev[10], usuarios[255];
};

struct livros
{
    int codigo, paginas;
    char area[255], titulo[255], autores[255], editora[255];
    struct emprestimo emp;
};

int opcPrinc, cod, pos, opcAlteracao;
char opcSecun;
FILE *arq, *arqAux;
struct livros liv;

int main()
{
    do
    {
        cout << "1- Cadastro" << endl;
        cout << "2- Emprestimo" << endl;
        cout << "3- Devolução" << endl;
        cout << "4- Alteração" << endl;
        cout << "5- Exclusão" << endl;
        cout << "6- Consulta de livros" << endl;
        cout << "7- Livros disponíveis" << endl;
        cout << "8- Listagem geral de livros" << endl;
        cout << "9 - Sair" << endl;
        cout << "Escolha uma opção!";
        cin >> opcPrinc;

        switch (opcPrinc)
        {
        case 1:
            cout << "Deseja cadastrar um livro(S ou N)?";
            cin >> opcSecun;
            while (opcSecun == 'S' || 's')
            {
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

                arq = fopen("dados.dat", "ab");
                if (arq != NULL)
                {
                    arq = fopen("dados.dat", "wb");
                }
                if (fwrite(&liv, sizeof(struct livros), 1, arq) == 1)
                {
                    cout << "Livro cadastrado com sucesso";
                }
                else
                {
                    cout << "Não foi possível acessar os arquivos";
                }
                fclose(arq);
                cin.ignore();
                cin.get();
            }
            break;
        case 2:
            arq = fopen("dados.dat", "rb+");
            if (arq != NULL)
            {
                cout << "Digite o código do livro para emprestimo";
                cin >> cod;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                pos = -1;
                while (!feof(arq))
                {
                    fread(&liv, sizeof(struct livros), 1, arq);
                    pos++;

                    if (cod == liv.codigo)
                    {
                        cout << "Qual a data de emprestimo?";
                        cin.get(liv.emp.dt_emp, 10);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Digite a data de devolução";
                        cin.get(liv.emp.dt_dev, 10);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Digite o usuario";
                        cin.get(liv.emp.usuarios, 255);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        fwrite(&liv, sizeof(struct livros), 1, arq);
                        break;
                    }
                }
                fclose(arq);
            }
            else
            {
                cout << "Não foi possível acessar os arquivos";
                cin.ignore();
                cin.get();
            }
            break;
        case 3:
            arq = fopen("dados.dat", "rb+");
            if (arq != NULL)
            {
                cout << "Digite o codigo do livro";
                cin >> cod;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                pos = -1;
                while (!feof(arq))
                {
                    fseek(arq, sizeof(struct livros) * pos, SEEK_SET);
                    strcpy(liv.emp.dt_emp, "");
                    strcpy(liv.emp.dt_dev, "");
                    fwrite(&liv, sizeof(struct livros), 1, arq);
                    break;
                }
                fclose(arq);
            }
            else
            {
                cout << "Não foi possível acessar os arquivos";
            }
            break;
        case 4:
            arq = fopen("dados.dat", "rb+");
            if (arq != NULL)
            {
                cout << "Digite o código do livro";
                cin >> cod;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                pos = -1;
                while (!feof(arq))
                {
                    fread(&liv, sizeof(struct livros), 1, arq);
                    if (cod == liv.codigo)
                    {
                        fseek(arq, sizeof(struct livros) * pos, SEEK_SET);
                        cout << "Qual informação deseja alterar?" << endl;
                        cout << "1 - Título" << endl;
                        cout << "2 - Autores" << endl;
                        cout << "3 - Área de atuação" << endl;
                        cout << "4 - Editora" << endl;
                        cout << "5 - Número de páginas" << endl;
                        cout << "Escolha uma opção: ";
                        cin >> opcAlteracao;

                        switch (opcAlteracao)
                        {
                        case 1:
                            cout << "Digite o novo título";
                            cin.get(liv.titulo, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        case 2:
                            cout << "Digite o(s) novo(s) autor(es):";
                            cin.get(liv.autores, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        case 3:
                            cout << "Digite a nova área de atuação:";
                            cin.get(liv.area, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        case 4:
                            cout << "Digite o nome da nova editora:";
                            cin.get(liv.editora, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        case 5:
                            cout << "Digite o número de páginas";
                            cin >> liv.paginas;
                            break;
                        default:
                            cout << "Digite uma opção válida" << endl;

                            break;
                        }

                        fwrite(&liv, sizeof(struct livros), 1, arq);
                        break;
                    }
                }
                fclose(arq);
            }
            else
            {
                cout << "Não foi possível acessar os arquivos";
                cin.ignore();
                cin.get();
            }
            break;
        case 5:
            cout << "Digite o código do livro que deseja excluir";
            cin >> cod;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            arq = fopen("dados.dat", "rb");
            arqAux = fopen("arqAux", "wb");
            fread(&liv, sizeof(struct livros), 1, arq);
            while (!feof(arq))
            {
                if (cod == liv.codigo)
                {
                    fwrite(&liv, sizeof(struct livros), 1, arqAux);
                }
                fread(&liv, sizeof(struct livros), 1, arq);
            }
            fclose(arq);
            fclose(arqAux);
            remove("dados.dat");
            rename("dados.aux", "dados.dat");
            break;
        case 6:
            arq = fopen("dados.dat", "rb");
            if (arq != NULL)
            {
                cout << "Digite o código do livro";
                cin >> cod;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (!feof(arq))
                {
                    fread(&liv, sizeof(struct livros), 1, arq);
                    if (cod == liv.codigo)
                    {
                        cout << "Código" << liv.codigo;
                        cout << "Área" << liv.area;
                        cout << "Título" << liv.titulo;
                        cout << "Autor(es)" << liv.autores;
                        cout << "Editora" << liv.editora;
                        cout << "Número de páginas" << liv.paginas;
                        cin.get();
                        break;
                    }
                }
                fclose(arq);
            }
            else
            {
                cout << "Não foi possível acessar os arquivos";
                cin.ignore();
                cin.get();
            }
            break;
        case 7:
            arq = fopen("dados.dat", "rb"); 
            if ( arq != NULL )
            {
                fread(&liv, sizeof(struct livros), 1, arq);
                if (strcmp(liv.emp.dt_emp, "") == 0)
                {
                    cout << "Área" << liv.area;
                    cout << "Título" << liv.titulo;
                    cout << "Autor(es)" << liv.autores;
                    cout << "Editora" << liv.editora;
                    cout << "Número de páginas" << liv.paginas;
                    cin.get();
                }
                fclose(arq);
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Não foi possível acessar os arquivos";
                cin.ignore();
                cin.get();
            }
            break;
        case 8:
            arq = fopen("dados.dat", "rb") ;
            if ( arq != NULL )
            {
                fread(&liv, sizeof(struct livros), 1, arq);
                cout << "Área" << liv.area;
                cout << "Título" << liv.titulo;
                cout << "Autor(es)" << liv.autores;
                cout << "Editora" << liv.editora;
                cout << "Número de páginas" << liv.paginas;
                cin.get();

                fclose(arq);
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Não foi possível acessar os arquivos";
                cin.ignore();
                cin.get();
            }
            break;
        case 9:
            cout << "Obrigado por usar nosso sistema";
            break;

        default:
            break;
        }
        cout << "\e[2J" << "\e[0;0";
    } while (opcPrinc != 9);
}