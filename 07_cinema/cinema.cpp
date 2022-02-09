#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Pessoa
{

private:

    string id;
    string telefone;

public:

    Pessoa (string id, string telefone){
        this->id = id;
        this->telefone = telefone;
    }

    string get_id()
    {
        return this->id;
    }

    string get_telefone()
    {
        return this->telefone;
    }

    friend ostream& operator<<(ostream& os, const Pessoa& pessoa) 
    {
        os << pessoa.id;
        return os;
    }
};

class Sala
{

private:

    int capacidade;
    vector<std::shared_ptr<Pessoa>> cadeira;

    bool mesmonome(string id)
    {
        for(int i = 0; i < capacidade; i++)
        {
            if(cadeira[i]->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

public:

    void lugares()
    {
        cout<<"Existem "<<capacidade<<" lugares na sala"<<endl;
    }

    void estado()
    {
        for(int i=0; i<capacidade; i++)
        {
            if (cadeira[i] == nullptr)
            {
                cout<<"-"<<endl;
            }
            else
            {
                cout<<cadeira[i].get()<<endl;
            }
        }
    }
    
    void novaSala()
    {
        for(int i=0; i<capacidade; i++)
        {
            cadeira[i] = nullptr;
        }
    }

    void reservar(string id, string telefone, int numero_cadeira)
    {
        if (mesmonome(id))
        {
            cout<<"Você já está na sala >:c"<<endl;
        }
        else if (cadeira[numero_cadeira] == nullptr)
        {
            cadeira[numero_cadeira] = make_shared<Pessoa>(id, telefone);
        }
        else
        {
            cout<<"Lugar ocupado"<<endl;
        }
    }

    void cancelar(string id, int numero_cadeira)
    {
        if (cadeira[numero_cadeira]->get_id() == id)
        {
            cadeira[numero_cadeira] = nullptr;
        }
    }

    void show_pessoa(string id)
    {
        for(int i=0; i<capacidade; i++)
        {
            if (cadeira[i]->get_id() == id)
            {
                cout<<cadeira[i].get()<<endl;
            }
        }
    }
};

int main (){
    return 0;
}

