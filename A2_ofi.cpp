#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#ifndef ulong 
#define ulong unsigned long int
#endif
using namespace std;

ulong max(ulong a, ulong b) { return (a > b) ? a : b; } //obtiene el mayor ulong entre dos números
void pokefichas(ulong n, vector<ulong> entrada);

int main()
{
    ulong num;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ulong> entrada; 
    while (cin>>num)     //O(c) Siendo c un valor entre 1 y 10
    {
        entrada.push_back(num);//se reciben todas las entradas de pokefichas
    }
    auto n=max_element(entrada.begin(),entrada.end()); //O(c-1) Siendo c un valor entre 1 y 10  //obtiene el máximo elemento de todos los ingresados
    ulong v=*n;
    pokefichas(v,entrada);  //O(n/2+c)
    return 0;  
}
void pokefichas(ulong n,vector<ulong> entrada)
{
    ulong *val=new ulong[(n + 1)/2];
    val[0] = 0;
    ulong i, max_val;
    max_val = 0;
    for (i = 1; i <= n/2; i++)    //O(n/2)
    {
        max_val = max(i, (val[i / 2] + val[i / 3] + val[i / 4]));   //Se obtiene el máximo valor de cada número hasta n/2 y se guardan
        val[i] = max_val; 
    }
    for (unsigned int i = 0; i < entrada.size(); i++)  //O(c)  Siendo c un valor entre 1 y 10
    {
        cout << max(entrada[i], val[entrada[i] / 2] + val[entrada[i] / 3] + val[entrada[i] / 4]) << endl; //Se imprimen los valores máximos ya calculados de los que nos piden
    }
}