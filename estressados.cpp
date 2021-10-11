#include<iostream>
#include<vector>

using namespace std;

bool existe(vector<int> vetor, int a)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i]==a) return true;
        return false;
    }
}

int contar(vector<int> vetor, int a)
{
    int b=0;
    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i]==a) b++;
    } 
    return b;
}

int procurar(vector<int> vetor, int a)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i]==a) return i;
    } 
}

int procurar_inicio(vector<int> vetor, int a, int start)
{
    for (int i = start; i < vetor.size(); i++)
    {
        if (vetor[i]==a) return i;
    }  return -1;
}

int procurar_menor(vector<int> vetor)
{
    int menor = 100;
    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i]<menor)
        {
            menor = vetor[i];
        }
    }
    return menor;
}

int procurar_menor_pos(vector<int> vetor)
{
    int menor = 100;
    int pos;
    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i]<menor)
        {
            menor = vetor[i];
            pos = i;
        }
    }
    return pos;
}

int procurar_menor_pos_inicio(vector<int> vetor, int start)
{
    int menor = 100;
    int pos;
    for (int i = start; i < vetor.size(); i++)
    {
        if (vetor[i]<menor)
        {
            menor = vetor[i];
            pos = i;
        }
    }
    return pos;
}

int procurar_menor_masc(vector<int> vetor)
{
    int menor = 100;
    int pos = -1;

    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i]<menor && vetor[i]>0)
        {
            menor = vetor[i];
            pos = i;
        } 
    }
    return pos;
}

int calcular_media(vector<int> vetor)
{
    int soma=0;
    for (int i = 0; i < vetor.size(); i++)
    {
        soma+=vetor[i];
    }
    int media= soma/vetor.size();
    return media;
}

void homens_mulheres(vector<int> vetor)
{
    int m = 0;
    int h = 0;
    for (int i = 0; i < vetor.size(); i++)
    {
        if(vetor[i]>0) h++;
        else m++;
    }
    if (m==h) cout << "empate";
    else if (m>h) cout << "mulheres";
    else cout << "homens";
}

void homens(vector<int> vetor)
{
    int somah = 0;
    int somam = 0;
    for (int i = 0; i < vetor.size(); i++)
    {
        if(vetor[i]>0) somah += vetor[i];
        if (vetor[i]<0) somam += vetor[i];
    }
    int mediah = somah/(int)vetor.size();
    int mediam = somam/(int)vetor.size();
    if (mediah > mediam) cout << "homens tem media maior";
    else cout << "homens tem media menor ou igual";
}

vector<int> clonar(const vector<int>& vetor )
{
    vector<int> newv;
    for (int i = 0; i < (int)vetor.size(); i++)
    {
        newv.push_back(vetor[i]);
    }
    return newv;   
}

vector<int> pegar_homens(const vector<int>& vetor )
{
    vector<int> newv;
    for (int i = 0; i < (int)vetor.size(); i++)
    {
        if(vetor[i]>0)
        {
            newv.push_back(vetor[i]);
        }
    }
    return newv;   
}

vector<int> pegar_calmos(const vector<int>& vetor )
{
    vector<int> newv;
    for (int i = 0; i < (int)vetor.size(); i++)
    {
        if(abs(vetor[i])<10)
        {
            newv.push_back(vetor[i]);
        }
    }
    return newv;   
}

vector<int> pegar_calmas(const vector<int>& vetor )
{
    vector<int> newv;
    for (int i = 0; i < (int)vetor.size(); i++)
    {
        if(vetor[i]>-10 && vetor[i]<0)
        {
            newv.push_back(vetor[i]);
        }
    }
    return newv;   
}

vector<int> inverter_com_copia(const vector<int>& vetor)
{
    vector<int> newv;
    for (int i = (int)vetor.size()-1; i >= 0 ; i--)
    {
        newv.push_back(vetor[i]);
    }
    return newv; 
}

void inverter(vector<int> vetor)
{
        for (int i = (int)vetor.size()-1; i >= 0 ; i--)
    {
        cout << vetor[i];
    }
}

void sortear(vector<int> vetor)
{
    int r = 0;

    for (int i = 0; i < (int)vetor.size(); i++)
	{
	    r = rand() % (int)vetor.size();
	}

    cout << r;
}

void embaralhar(vector<int> vetor)
{

    for (int i = 0; i < (int)vetor.size(); i++)
	{
		int r = rand() % (int)vetor.size();

		int temp = vetor[i];
		vetor[i] = vetor[r];
		vetor[r] = temp;
	}

    for (int i = 0; i < (int)vetor.size(); i++)
    {
        cout << vetor[i] << " ";
    }
    
}

void ordenar( vector<int> vetor)
{
    int aux = 0;

    for (int i = 0; i < (int)vetor.size(); i++)
    {
        for (int j = i + 1; j < (int)vetor.size(); j++)
        {
            if (vetor[i]>vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux; 
            }
        }
    }

    for (int i = 0; i < (int)vetor.size(); i++)
    {
        cout << vetor [i];
    }
}

void exclusivos(vector<int> vetor)
{
    
}


int main()
{
    //vector<int> v;
    exclusivos({4, 2, 1, 1, -2, -1, -10, -20});
    /*for (int i = 0; i < v.size(); i++)
    {
        cout <<  v[i] << " ";
    }*/
    return 0;
} 
