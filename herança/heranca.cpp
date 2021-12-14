#include<iostream>

using namespace std;

class summoner
{
private:
    bool conected {true};
public:
    summoner()
    {
        cout<<"Bem vindos a Summoners Rift "<<endl;
    }
    void build()
    {
        cout<<"O campeão comprou uma espada de doran *macetar os inimigos na porrada*"<<endl;
    }
    void walking()
    {
        cout<<"Caminhando até a rota *que demorado >:c prox vez compro uma bota*"<<endl;
    }
    void die ()
    {
        cout<<"O campeão morreu *mata afk msm seu filho da p***, server lixo*"<<endl;
    }
    void disconected()
    {
        conected = false;
        cout<<"Um aliado foi desconectado *NÃÃÃO PUTA MERDA Q PC DE BOSTA >:O*"<<endl;
    }
    bool isAlive()
    {
        return conected;
    }
    friend ostream& operator<<(ostream& os, summoner& summoner)
    {
        os<<"nunca mais jogo esse jogo lixo"<<endl;
        return os;
    }

};

class champion : public summoner
{
    string name {""};
    public:
    champion(string name): name{name}
    {
        cout<<"O campeão "<<name<<" entrou na partida *plmd que o adc não fique 0/todos nesse game*"<<endl;
    }
    void skin()
    {
        cout<<""<<name<<" está vestido de Emissário da Luz *pra quê dois rins se posso ter a melhor skin do yone e ainda sobra um*"<<endl;
    }
    void build()
    {
        cout<<this->name <<" comprou uma espada de doran *macetar os inimigos na porrada*"<<endl;
    }
    void die ()
    {
        cout<<this->name<<" morreu *mata afk msm seu filho da p***, server lixo*"<<endl;
    }
    void baron()
    {
        cout<<this->name<<" desce até o rio para ajudar seu time no baron"<<endl;
    }
    void ziggs()
    {
        cout<<"O inimigo Ziggs utiliza uma blue tricket no baron e avista o time adversário fazendo"<<endl;
    }
    void ziggsult()
    {
        cout<<"Ziggs ulta"<<endl;
    }
};

int main()
{
    champion summoner("Yone");
    summoner.skin();
    summoner.build();
    summoner.walking();
    summoner.baron();
    summoner.ziggs();
    summoner.ziggsult();
    summoner.disconected();
    summoner.die();
    return 0;
}
