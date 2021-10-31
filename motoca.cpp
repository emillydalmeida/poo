#include <iostream>
#include <sstream>

struct Pessoa 
{
    std::string nome;
    int idade;

    Pessoa(std::string nome, int idade) 
    {
        this->nome = nome;
        this->idade = idade;
    }

    Pessoa(int idade) : Pessoa("", idade) {}

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p)
    {
        os << "Nome: " << p.nome << " Idade: " << p.idade;
        return os;
    }
    

};

struct Motoca 
{
    Pessoa *pessoa {nullptr};
    int tempo {0};
    int potencia {1};
    Motoca() {}

    void InserirPessoa(Pessoa * p)
    {
        if(this->pessoa != nullptr)
        {
            std::cout << "Motoca cheia" << std::endl;
            return;
        }
        this->pessoa = p;
    }

    Pessoa * removerPessoa()
    {
        Pessoa * p = this->pessoa;
        this->pessoa = nullptr;
        return p;
    }

    std::string buzinar()
    {
        return "P" + std::string(this->potencia, 'e') + "m";
    }

    void dirigir()
    {
        if(this->pessoa != nullptr)
        {
            std::cout << "Dirigindo com " << *this->pessoa << std::endl;
        }
        else
        {
            std::cout << "Dirigindo sem pessoa" << std::endl;
        }
    }

    void duracao(int tempo)
    {
        std::cout << "Duracao: " << tempo << " minutos" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Motoca& m)
    {
        os << "[" << *m.pessoa << "]";
        return os;
    } 
};

int main()
{
    Motoca mitsubishi;
    while(true)
    {
        std::string line;
        std::getline(std::cin, line);
        std:: stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "init")
        {
            int pot = 0;
            ss >> pot;
            mitsubishi = Motoca();
            mitsubishi.potencia = pot;
        }
        else if (cmd == "show")
        {
            std::cout << mitsubishi << std::endl;
        }
        else if (cmd == "insert")
        {
            std::string nome;
            int idade;
            ss >> nome >> idade;
            Pessoa * p = new Pessoa(nome, idade);
            mitsubishi.InserirPessoa(p);
        }
        else if (cmd == "remove")
        {
            Pessoa * p = mitsubishi.removerPessoa();
            if(p != nullptr)
            {
                delete p;
            }
        }
    }
    return 0;
}