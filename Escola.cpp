#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Aluno {
    static int contador;
    vector<int> id_disciplinas;
    string nome;
    int id_aluno;
    map<int, vector<int>> notas;

    //Método estático para fazer o incremento 

    static int acresContador(){
        return contador++;
    }    

    void atribuirNota(int id_disciplina, int nota) {
        notas[id_disciplina].push_back(nota);
    };

    void mostrarNotas() {
        for (const auto& par : boletim.notas) {
            int id_disciplina = par.first;
            const vector<int>& lista_notas = par.second;

            cout << "Disciplina " << id_disciplina << ": ";
            for (int nota : lista_notas) {
                cout << nota << " - ";
            }
            cout << endl;
        };
    };

    double calcularMedia(int id_disciplina) {
        if (boletim.notas.find(id_disciplina) == boletim.notas.end()) {
            cout << "Disciplina não encontrada!" << endl;
            return -1.0;
        };
        const vector<int>& lista_notas = boletim.notas[id_disciplina];

        if (lista_notas.empty()) {
            cout << "Sem notas para essa disciplina!" << endl;
            return 0.0;
        }

        int soma = 0;
        for (int nota : lista_notas) {
            soma += nota;
        }

        return static_cast<double>(soma) / lista_notas.size();
    };
};
int Aluno::contador = 0;


struct Turma {
    vector<int> id_alunos;
    vector<int> id_disciplinas;
    int id_Turma;
    string nome;
    Escola* escola;

    void adicionarAluno(int id_aluno) {
        id_alunos.push_back(id_aluno);
    };

    void mostrarAlunos(){
        for (int i = 0; i < id_alunos.size(); ++i){
            cout << "Aluno: " << id_alunos[i] << " - Nome: " << escola->info_alunos[id_alunos[i]] << endl;
        };
    };

    // Terminar
    void mostrarDisciplinas() {
        for (int i = 0; i < id_disciplinas.size(); ++i){
            cout << "Código da disciplina: " << id_disciplinas[i] << " - Nome: " << escola->info_disciplinas[id_disciplinas[i]] << " - Docente: " << endl;
        };
    };
};

struct Professor{
    vector<int> id_turmas;
    int id_disciplina;
    string nome;

    atribuirNota(int id_aluno) {
        escola->info_alunos
    };
};

struct Escola{

    map<int, Aluno> info_alunos;
    map<int, map<string, string>> info_disciplinas;
    vector<Turma> turmas;
    vector<int> index_aluno;
    int id_aluno = 1;
    
    void cadastrarAluno(Aluno aluno) {
        info_alunos[aluno.id_aluno] = aluno;
    }

    void cadastrarDisciplina(Disciplina disciplina) {
        disciplinas.push_back(disciplina);
    }

    void cadastrarTurma(Turma turma){
        turmas.push_back(turma);
    }
    
    void cadastrarProfessor(Professor professor){
        professores.push_back(professor);
    }
};


int main()
{
Escola escola;

int opcao = 0;

do{
    cout<< "1-Cadastrar Aluno";
    cin >> opcao;
    
    if(opcao == 1){
        string nome_aluno;
        cout<<"Digite o nome do aluno:";
        cin>>nome_aluno;
        Aluno aluno;
        aluno.nome = nome_aluno;
        aluno.id_aluno = Aluno::acresContador();
        escola.cadastrarAluno(aluno);   
        

    }else if(opcao == 2){
        cout<<"Mostrar Alunos:";
    }else if(opcao == 3){
        "Conteudo";
    }else if(opcao == 4){
        "Conteudo";
    }else if(opcao == 5){
        "Conteudo";
    }
    
}while(opcao != 0);


    return 0;
}
