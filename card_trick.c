#include <stdio.h>

int cards[13];
int head, rear;
int n;
int cnt;
int main()
{
    
    int *p = cards;
    p = &head;
    p = &rear;
    
    cards = &head;
    char a;
    int i,j, c=0;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        for(j=0;j<i+1;j++) {
            c++;
            if(c>=n) c=c%(n);
            if(cards[c] != 0) j--;
        }
        //printf(" c : %d\n", c); 

        if(c>=n) c=c%(n);
        //printf("2 c : %d\n", c); 
        
        cards[c] = ++cnt;
        //printf("cnt %d\n", cnt);
        do {
            c++;
            if(cnt == n) break;
            if(c>=n) c=c%(n);
            
        }while(cards[c] !=0);
        //printf("3 c : %d\n", c); 
    }
    for(i=0;i<n;i++) {
        printf("%d ", cards[i]);
    }
    putchar('\n');
    return 0;
}
