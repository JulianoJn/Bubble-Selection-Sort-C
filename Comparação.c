#include<stdio.h>
#include<time.h>


// função para preencher os numeros de forma descrente e testar o piores casos do algortimos 
void preencherDecrescente(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}


// algoritmo de bubble sort
void bubble(int arr[], int n, long long *compb, long long *movb){
    *compb = 0; // utilização de ponteiros para que o programa uma vez que as atualizações aqui precisam ser passadas para o programa principal por meio de manipulação de memoria onde ele vai acessar dentro do ponteiro
    *movb = 0;
    int i, j, temp;

    for ( i = 0; i < n- 1; i++)
    {
        
        for (j = 0; j < n - i - 1; j++)
        {

            (*compb) ++; 
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                (*movb)++;
            }
            
        }
        
    }
    

}

// algoritmo selection sort

void selection (int arr[], int n, long long *comps, long long *movs){
    *comps = 0;
    *movs = 0;

    int i, j, temp, min_idx;

    for (i = 0; i < n-1 ; i++)
    {
        min_idx = i;
       
        for (j = i+1; j < n; j++)
        {
             (*comps) ++;
            if (arr[j]<arr[min_idx])
            {
                min_idx = j;
            }
            
            
        }
        temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

            (*movs)++;
    }
    

}

// para fazer o quadro de saída

void imprimirLinha(char *algoritmo, int tamanho, double tempo,
                   long long comps, long long movs) {
    printf("%-15s %-10d %-12.6f %-15lld %-15lld\n",
           algoritmo, tamanho, tempo, comps, movs);
           // - alinhado a esquerda, 15 de espaço, s mostra a string, da mesma forma para os outros
}


int main()
{
    int tamanho[] = {100, 1000, 10000}; // tamanho dos vetores de numero
    
    printf("%-15s %-10s %-12s %-15s %-15s\n",
       "Algoritmo", "Tamanho", "Tempo(ms)", "Comparacoes", "Movimentacoes");
    printf("--------------------------------------------------------------------------\n");


        for (int  i = 0; i < 3; i++)
        {
            int n = tamanho[i]; // n = ao meu vetor de tamanho, tamanho[i] o numero do loop
            int arr[n]; // meu array é igual a n que tem o tamanho de 100, etc definidos pelo alogoritmo

            // função clock
            long long movb, compb, movs, comps;
            clock_t inicio, fim;
            double tempo_ms;

                //chama os numeros  
            preencherDecrescente(arr, n);

            // bubble
            inicio = clock();
    
            bubble(arr, n, &compb, &movb);
            fim = clock();
            tempo_ms = (double) (fim - inicio) *1000 / CLOCKS_PER_SEC;
            imprimirLinha("Bubble Sort", n, tempo_ms, compb, movb);

            // selection
            preencherDecrescente(arr, n);

            inicio = clock();
            selection(arr, n, &comps, &movs);
            fim = clock();
            tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

            imprimirLinha("Selection Sort", n, tempo_ms, comps, movs);
        }
        
        return 0;

        /* Qual dos algoritmos apresentou melhor desempenho? 
         R = algoritmo com maior desempenho foi o selection, uma vez que a complexidade seja o(n^2), ele se destaca por fazer menos troca do que o bubble sendo mais eficiente nesse caso, portanto o selection faz trocas por vez e não simultaneamente ele acabou com um melhor desempenho.*/
}
