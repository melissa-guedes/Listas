#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Funcionario {
    int prontuario;
    std::string nome;
    double salario;
};

std::vector<Funcionario> funcionarios;

int buscarFuncionario(int prontuario) {
    for (size_t i = 0; i < funcionarios.size(); ++i) {
        if (funcionarios[i].prontuario == prontuario) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void incluirFuncionario() {
    Funcionario f;
    std::cout << "Digite o prontuario: ";
    std::cin >> f.prontuario;

    if (buscarFuncionario(f.prontuario) != -1) {
        std::cout << "Prontuario ja cadastrado.\n";
        return;
    }

    std::cin.ignore(); // limpar buffer
    std::cout << "Digite o nome: ";
    std::getline(std::cin, f.nome);

    std::cout << "Digite o salario: ";
    std::cin >> f.salario;

    funcionarios.push_back(f);
    std::cout << "Funcionario incluido com sucesso.\n";
}

void excluirFuncionario() {
    int prontuario;
    std::cout << "Digite o prontuario do funcionario a excluir: ";
    std::cin >> prontuario;

    int indice = buscarFuncionario(prontuario);
    if (indice == -1) {
        std::cout << "Funcionario nao encontrado.\n";
        return;
    }

    funcionarios.erase(funcionarios.begin() + indice);
    std::cout << "Funcionario excluido com sucesso.\n";
}

void pesquisarFuncionario() {
    int prontuario;
    std::cout << "Digite o prontuario do funcionario a pesquisar: ";
    std::cin >> prontuario;

    int indice = buscarFuncionario(prontuario);
    if (indice == -1) {
        std::cout << "Funcionario nao encontrado.\n";
        return;
    }

    const Funcionario& f = funcionarios[indice];
    std::cout << "Nome: " << f.nome << "\n";
    std::cout << "Salario: " << std::fixed << std::setprecision(2) << f.salario << "\n";
}

void listarFuncionarios() {
    if (funcionarios.empty()) {
        std::cout << "Nenhum funcionario cadastrado.\n";
        return;
    }

    double totalSalarios = 0.0;

    std::cout << "\nLista de funcionarios:\n";
    for (const auto& f : funcionarios) {
        std::cout << "Prontuario: " << f.prontuario << "\n";
        std::cout << "Nome: " << f.nome << "\n";
        std::cout << "Salario: " << std::fixed << std::setprecision(2) << f.salario << "\n\n";
        totalSalarios += f.salario;
    }

    std::cout << "Total de salarios: " << std::fixed << std::setprecision(2) << totalSalarios << "\n";
}

int main() {
    int opcao;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Incluir\n";
        std::cout << "2. Excluir\n";
        std::cout << "3. Pesquisar\n";
        std::cout << "4. Listar\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0:
                std::cout << "Encerrando o programa.\n";
                break;
            case 1:
                incluirFuncionario();
                break;
            case 2:
                excluirFuncionario();
                break;
            case 3:
                pesquisarFuncionario();
                break;
            case 4:
                listarFuncionarios();
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}
