#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int beginning, end;
};

struct Pair allPairs[100005];
struct Pair solution[100005];

void merge(struct Pair *v, int l, int m, int r){
	struct Pair *c=malloc(sizeof(struct Pair)*(r-l+1));
	int i=l,j=m+1,k=0;

	while(i<=m && j<=r){
	    if(v[i].beginning <= v[j].beginning)
		    c[k++]=v[i++];
    	else
    		c[k++]=v[j++];
  	}

  	while(i<=m)
    	c[k++]=v[i++];
  	while(j<=r)
      	c[k++]=v[j++];

  	k=0;
  	for(i=l;i<=r;i++)
    	v[i]=c[k++];
  	free(c);
}

void merge_sort(struct Pair *v, int l, int r){
	if(l>=r)return;
	int m = (l+r)/2;
	
	merge_sort(v, l, m);
	merge_sort(v, m+1, r);
	
	merge(v, l, m, r);
}


int main() {

    int test_cases, M;
    scanf("%d", &test_cases);

    while(test_cases-->0) {

        printf("\n");
        scanf("%d", &M);

        int numPairs = 0;
        while (scanf("%d %d", &allPairs[numPairs].beginning, &allPairs[numPairs].end),
                allPairs[numPairs].beginning != 0 || allPairs[numPairs].end !=0){     
            if (allPairs[numPairs].end > 0 && allPairs[numPairs].beginning < M)
                ++numPairs;
        }

        merge_sort(allPairs, 0, numPairs-1);

        // garante que um par > M nunca será selecionado
        allPairs[numPairs].beginning = M + 1;
        
        int count = 0;
        int currentX = 0;
        int currentPair = 0;
        
        // escolhe o melhor 'end' entre todos os pares possíveis
        while (currentX < M && currentPair < numPairs) {
            solution[count].end = 0;
            for (; allPairs[currentPair].beginning <= currentX; ++currentPair)
                if (allPairs[currentPair].end > solution[count].end)
                    solution[count] = allPairs[currentPair];
            
            if (solution[count].end == currentX)
                break;
            currentX = solution[count].end;
            ++count;
        }
        
        if (currentX >= M) {
            printf("%d\n", count);
            int j = 0;
            for (; j < count; ++j)
                printf("%d %d\n", solution[j].beginning, solution[j].end);
        }
        else
            printf("0\n");

    }

    return 0;
}


// UVA - questão 10020
// Obs: Compilador ANSI C 5.3.0
// Obs2: Tirar comentários para submeter o código!
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=961
//
// Dado uma distância de 0 a M e varios segmentos de linha [beginning, end], qual a quantidade mínima de segmentos
// ... de linha necessária para cobrir a distância.