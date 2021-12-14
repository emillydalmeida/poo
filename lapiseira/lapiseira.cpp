#include <iostream>
#include <sstream>

struct Grafite 
{
    int tamanho;
    int dureza;

    Grafite(int tamanho, int dureza) 
    {
        this->tamanho = tamanho;
        this->dureza = dureza;
    }
    

};

struct Lapiseira 
{
    Grafite *grafite {nullptr};

    Lapiseira() {}

    void InserirGrafite(Grafite * g)
    {
        if(this->grafite != nullptr)
        {
            std::cout << "Sem grafite" << std::endl;
            return;
        }
        this->grafite = g;
    }

    Grafite * removerGrafite()
    {
        grafite = this->grafite;
        this->grafite = nullptr;
        return grafite;
    }


    void escrever()
    {
        if(this->grafite != nullptr)
        {
            std::cout << "Dirigindo com: " << grafite << std::endl;
        }
        else
        {
            std::cout << "Não da pra escrever" << std::endl;
        }
    }

};

int main()
{
    Grafite g(10, 10);
    Lapiseira l;
    l.InserirGrafite(&g);
    l.escrever();
    return 0;
}