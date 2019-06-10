#include <stdio.h> 
int main() 
{ 

    printf("Digite quantas threads vão ter e quantos recursos cada uma vai ter: ");

    int n,m,f = 3;
    scanf("%d %d", &n, &m);
    int maxThreads[n][m];
    int allocation[n][m];
    int need[n][m];
    int available[f];

    printf("Digite os valores do available: ");
    for(int i = 0;i < f;i++){
    
        scanf("%d", &available[i]);
    }

    printf("Digite os recursos das suas threads: ");
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){

            scanf("%d",&maxThreads[i][j]);
        }
    }

    printf("Digite quantos recursos deseja no allocation: ");
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){

            scanf("%d",&allocation[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){

            need[i][j] = maxThreads[i][j] - allocation[i][j];
        }
    }

    int work[f];
    for(int i = 0; i < f; i++){

        work[i] += available[i]; 
    }


    int l[n], ans[n], cont = 0; 
    for (int k = 0; k < n; k++) { 
        l[k] = 0; 
    } 

    int y = 0; 
    for (int k = 0; k < 5; k++) { 
        for (int i = 0; i < n; i++) { 
            if (l[i] == 0) { 
  
                int flag = 0; 
                for (int j = 0; j < m; j++) { 
                    if (need[i][j] > available[j]) 
                        flag = 1; 
                    break; 
                } 
  
                if (flag == 0) { 
                    ans[cont++] = i; 
                    for (y = 0; y < m; y++) 
                        available[y] += allocation[i][y]; 
                    l[i] = 1; 
                } 
            } 
        } 
    } 
  
    printf("Sequência dos safes \n"); 
    for (int i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
  
    return (0);
}   
