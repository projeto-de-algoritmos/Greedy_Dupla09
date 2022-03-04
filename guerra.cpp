#include <bits/stdc++.h>
using namespace std;

int quadradonia[(int)1e5+5];
int noglandia[(int)1e5+5];

int main() {
  int soldiers;
  scanf("%d",&soldiers);


  for( int i = 0; i < soldiers; i++ )
    scanf("%d",&quadradonia[i]);

  for( int i = 0; i < soldiers; i++ )
    scanf("%d",&noglandia[i]);

  sort(quadradonia, quadradonia + soldiers);
  sort(noglandia, noglandia + soldiers);

  int wins = 0,i = 0, j = 0;
  // Select soldier.
  while( i < soldiers && j < soldiers )
  {
    if(quadradonia[i] < noglandia[j])
      { wins++; j++; i++; }

    while((quadradonia[i] >= noglandia[j]) && j < soldiers)
      j++;
  }

  printf("%d\n",wins);
  return 0;
}

// URI 2095
// https://www.beecrowd.com.br/judge/pt/problems/view/2095
// -------------------------------------------------------
// Ordenar os vetores quadradonia e noglandia
// Escolher o mais forte minimo de noglandia que vence
// o soldado na posicao quadradonia[i].
// C++17
