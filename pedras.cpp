#include<bits/stdc++.h>
using namespace std;

int adj_cost, swap_cost;
size_t black_rock;

size_t custo( size_t lower_pointer, size_t upper_pointer)
{
  size_t price = swap_cost;
  size_t p = (upper_pointer - lower_pointer) * adj_cost;

  price = price < p ? price : p;

  return price;
}

int main()
{
  string st;

  cin >> swap_cost >> adj_cost;
  // O custo real da troca por adj e swap - adj
  adj_cost = swap_cost - adj_cost;
  cin >> st;

  size_t upper_pointer = st.size();
  size_t lower_pointer = 0, cost = 0;

  black_rock = count(st.begin(),st.end(),'B');

  while(lower_pointer < black_rock)
  {
    if( st[lower_pointer] == 'W' )
    {
      while( st[upper_pointer] != 'B' ) upper_pointer--;

      cost += custo(lower_pointer, upper_pointer);
      swap(st[lower_pointer],st[upper_pointer]);
    }
    lower_pointer++;
  }

  cout << cost << endl;
  return 0;
}

// URI 1744
// https://www.beecrowd.com.br/judge/pt/problems/view/1744
// Qual o custo minimo de mover as pedras pretas para a esquerda ?
// -------------------------
// Informacoes necessarias :
// adj action - > perde swap_cost - adj_cost
// swap action - > perde swap_cost
