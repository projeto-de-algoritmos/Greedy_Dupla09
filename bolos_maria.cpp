#include <bits/stdc++.h>
using namespace std;
int main() {

  int t;
  cin >> t;
  while(t--)
  {
    int d,i,b;
    cin >> d >> i >> b;

    // Preco de cada ingrediente.
    vector<unsigned int>ing(i);
    for(size_t r = 0; r < i; r++)
      cin >> ing[r];

    // Preco do bolo, que depende da combinacao de ingredientes.
    vector<unsigned long>bolos(b,0);
    size_t ind,qt,qi;
    for(size_t r = 0; r < b ; r++)
    {
      // Quantidade de ingredientes para fazer o bolo r
      cin >> qi;
      while(qi--)
      {
        // Ingrediente i e a quantia necessaria.
        cin >> ind >> qt;
        bolos[r] += (ing[ind] * qt);
      }
    }
    // Alterando o significado da variavel bolos.
    // Ao inves de armazenar o valor do bolo, armazena o 'rendimento' relativo ao dinheiro d.
    for(size_t r = 0; r < b; r++)
      bolos[r] = bolos[r] != 0 ? (unsigned long) d/bolos[r] : 0 ;

    // Seleciona o bolo com maior rendimento :)
    cout << *max_element(bolos.begin(),bolos.end()) << '\n';

  }

  return 0;
}

// URI 1608
// https://www.beecrowd.com.br/judge/pt/problems/view/1608
// -------------------------------------------------------
// Algoritmo ganancioso trivial, dada uma quantia de ingredientes com precos p e o dinheiro d maximo a ser gasto
// qual o bolo que mais pode ser produzido dados os ingredientes e dinheiro que possuimos ?
// C++11 || C++17
