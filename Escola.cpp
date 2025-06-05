#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Disciplina
{
    static int contador;
    string nome;
    int id_professor;
    int id_disc;

    Disciplina() : id_professor(0), id_disc(contador++) {}
};

int Disciplina::contador = 0;

struct Aluno
{
    static int contador;
    vector<int> id_disciplinas;
    string nome;
    int id_aluno;
    map<int, vector<int>> notas;

    Aluno() : id_aluno(contador++) {}

    
};

int Aluno::contador = 0;

struct Escola; // Forward declaration

struct Turma
{
    vector<int> id_alunos;
    vector<int> id_disciplinas;
    int id_Turma;
    string nome;
    Escola *escola;

    void adicionarAluno(int id_aluno)
    {
        id_alunos.push_back(id_aluno);
    }
};

struct Professor
{
    vector<int> id_turmas;
    int id_disciplina;
    string nome;
    Escola *escola;

    void atribuirNota(int id_aluno, int nota)
    {
        &escola->info_alunos[id_aluno].notas[id_disciplina].push_back(nota);
    };
};

struct Escola
{
    map<int, Aluno> info_alunos;
    map<string, Professor> info_professores;
    map<int, Disciplina> info_disciplinas;
    vector<Turma> turmas;
    vector<int> index_aluno;
    int id_aluno = 1;

    void cadastrarAluno(Aluno aluno)
    {
        info_alunos[aluno.id_aluno] = aluno;
    }

    void cadastrarDisciplina(Disciplina disciplina)
    {
        info_disciplinas[disciplina.id_disc] = disciplina;
    }

    void cadastrarTurma(Turma turma)
    {
        turmas.push_back(turma);
    }

    void cadastrarProfessor(Professor Professor) {
        info_professores[Professor.nome] = Professor;
    }

    void mostrarAlunos()
    {
        for (const auto &par : info_alunos)
        {
            cout << "ID: " << par.first << " | Nome: " << par.second.nome << endl;
        }
    }
};

int main()
{
    Escola escola;

    int opcao = 0;

    do
    {
        cout << "Menu\n";
        cout << "1-Cadastrar Aluno\n";
        cout << "2-Mostrar Aluno\n";
        cout << "4-Adicionar Disciplina\n";
        cout << "Input:";
        cin >> opcao;

        if (opcao == 1)
        {
            string nome_aluno;
            cout << "Digite o nome do aluno:";
            cin >> nome_aluno;
            Aluno aluno;
            aluno.nome = nome_aluno;
            escola.cadastrarAluno(aluno);
        }
        else if (opcao == 2)
        {
            escola.mostrarAlunos();
        }
        else if (opcao == 3)
        {
            string nome_professor;
            cout << "Digite o nome do professor:";
            cin >> nome_professor;
            Professor professor;
            professor.nome = nome_professor;
            professor.escola = &escola;
            escola.cadastrarProfessor(professor);
        }
        else if (opcao == 4)
        {
            string nome_disciplina;
            cout << "Digite o nome da disciplina:";
            cin >> nome_disciplina;
            Disciplina disciplina;
            disciplina.nome = nome_disciplina;
            escola.cadastrarDisciplina(disciplina);
        }
        else if (opcao == 5)
        {
            // Conteudo
        }

    } while (opcao != 0);

    return 0;
}
    