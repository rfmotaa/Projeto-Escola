#include <iostream>
#include <string>
#include <vector>
#include <map>

// Falta implementar a opção 7 do menu e tratar alguns possíveis erros de input
// Opção 7: consertar a sintaxe para conseguir atribuir através do ponteiro para escola

using namespace std;

struct Disciplina
{
    static int contador;
    int id_disc;
    string nome;

    Disciplina() : id_disc(contador++) {}
};

int Disciplina::contador = 0;

struct Aluno {
    static int contador;
    string nome;
    int id_aluno;
    vector<int> id_disciplinas;
    map<int, vector<int>> notas;

    Aluno() : id_aluno(contador++) {}

    void addDisciplina(int id_disciplina) {
        id_disciplinas.push_back(id_disciplina);
    };

    void mostraBoletim() {
        for (const auto& par : notas) {
            int aluno = par.first;
            const std::vector<int>& notasAluno = par.second;

            std::cout << "Aluno " << aluno << ": ";
            for (int nota : notasAluno) {
                std::cout << nota << " ";
            }
            std::cout << std::endl;
        }
    };
};

int Aluno::contador = 0;

struct Escola; // Forward declaration

struct Turma {
    string nome;
    vector<int> id_alunos;
    vector<int> id_disciplinas;
    Escola *escola;

    void adicionarAluno(int id_aluno) {
        id_alunos.push_back(id_aluno);
    }
};

struct Professor {
    vector<int> id_turmas;
    int id_disciplina;
    string nome;
    Escola *escola;

    void atribuirNota(int id_aluno, int nota) {
        escola->info_alunos[id_aluno].notas[id_disciplina].push_back(nota);
    };
};

struct Escola
{
    map<int, Aluno> info_alunos;
    map<string, Professor> info_professores;
    map<int, Disciplina> info_disciplinas;
    map<string, Turma> turmas;
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
        turmas[turma.nome] = turma;
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

    void mostraDisciplinas() {
        for (const auto &par : info_disciplinas) {
            cout << "ID: " << par.first << " | Nome: " << par.second.nome << endl;
        }
    }

    void mostraBoletim(int id_aluno) {
        info_alunos[id_aluno].mostraBoletim();
    }

    void atribuirDisciplina(string nome_professor, int id_disc) {
        info_professores[nome_professor].id_disciplina = id_disc;
    }

    void adicionaAlunoTurma(int id_aluno, string nome) {
        turmas[nome].id_alunos.push_back(id_aluno);
    }

    void adicionaDisciplinaTurma(int id_disc, string nome) {
        turmas[nome].id_disciplinas.push_back(id_disc);
    }
};

int main()
{
    Escola escola;

    int opcao = 0;

    do
    {
        cout << "Menu\n";
        cout << "0-Sair";
        cout << "1-Cadastrar Aluno\n";
        cout << "2-Mostrar Alunos\n";
        cout << "3-Mostrar boletim de aluno específico\n";
        cout << "4-Cadastrar Disciplina\n";
        cout << "5-Cadastrar Professor\n";
        cout << "6-Atribuir disciplina a um professor\n";
        cout << "7-Atribuir nota a um aluno";
        cout << "8-Criar nova turma\n";
        cout << "9-Adicionar aluno a turma\n";
        cout << "10-Adicionar disciplina a turma\n";
        cout << "Input:";
        cin >> opcao;

        if (opcao == 1) {
            string nome_aluno;
            cout << "Digite o nome do aluno:";
            cin >> nome_aluno;
            Aluno aluno;
            aluno.nome = nome_aluno;
            escola.cadastrarAluno(aluno);
        }
        else if (opcao == 2) {
            escola.mostrarAlunos();
        }
        else if (opcao == 3) {
            int id_aluno;
            escola.mostrarAlunos();
            cout << "Digite o id do aluno que deseja visualizar o boletim.";
            cin >> id_aluno;
            escola.mostraBoletim(id_aluno);
        }
        else if (opcao == 4) {
            string nome_disciplina;
            cout << "Digite o nome da disciplina:";
            cin >> nome_disciplina;
            Disciplina disciplina;
            disciplina.nome = nome_disciplina;
            escola.cadastrarDisciplina(disciplina);
        }
        else if (opcao == 5) {
            string nome_professor;
            cout << "Digite o nome do professor:";
            cin >> nome_professor;
            Professor professor;
            professor.nome = nome_professor;
            professor.escola = &escola;
            escola.cadastrarProfessor(professor);
        }
        else if (opcao == 6) {
            string nome;
            cout << "Digite o nome do professor: ";
            cin >> nome;
            int id_disc;
            cout << "Digite o id da disciplina";
            cin >> id_disc;
            escola.atribuirDisciplina(nome, id_disc);
        }
        else if(opcao = 7) {
            continue;
            // Implementar
        }
        else if (opcao == 8) {
            string nome;
            cout << "Nome da nova turma: ";
            cin >> nome;
            Turma turma;
            escola.cadastrarTurma(turma);
        }
        else if (opcao == 9) {
            int id_aluno;
            escola.mostrarAlunos();
            cout << "Digite o id do aluno que deseja adicionar.";
            cin >> id_aluno;
            string nome;
            cout << "Nome da turma: ";
            cin >> nome;
            escola.adicionaAlunoTurma(id_aluno, nome);
        }
        else if (opcao == 10) {
            int id_disc;
            escola.mostraDisciplinas();
            cout << "Digite o id da disciplina que deseja adicionar.";
            cin >> id_disc;
            string nome;
            cout << "Nome da nova turma: ";
            cin >> nome;
            escola.adicionaAlunoTurma(id_disc, nome);
        }

    } while (opcao != 0);

    return 0;
}
