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
    int pos= -1;

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

int main()
{
    cout << procurar_menor_masc({77, 44, -44, 7, -99});
    return 0;
} 
