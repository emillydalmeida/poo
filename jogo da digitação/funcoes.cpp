#include <iostream>
#include <functional>

int soma(int a, int b) 
{
    return a + b;
}

int main()
{
    std::function<int(int, int)> funcao = soma;
    std::cout << funcao(1, 2) << std::endl;
    funcao = [](int a, int b) { return a - b; };
    std::cout << funcao(1, 2) << std::endl;
    return 0;
}