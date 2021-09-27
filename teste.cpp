#include<iostream>

using namespace std;

int main(){

    int b, c, soma;

    cin >> b;
    cin >> c;

    soma= b+c;

    if (soma%2==0)
    {
        cout << "Bino";
    }
    else
    {
        cout << "Cino";
    }
    
    
    return 0;
}