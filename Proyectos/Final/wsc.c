#include <stdio.h>
#include <string.h>
#define MAX 11
 
int main(){
	int n;
    int m;
    int a[MAX][MAX];
    int i,j;
    int t;
    int x, y;
    int flag;
    int count;
 
	scanf("%d",&t);
 
	while(t--){
		scanf("%d %d",&n,&m);
        
        //If this flag triggers, it means it probably aint the solution.
		flag = 0;
		memset(a,0,sizeof(a));
 
		count = 0;
		for(i = 0;i<m;i++){
			scanf("%d %d",&x,&y);
 
			if(x == y){
				flag = 1;
            }
			else if(a[x][y] != 1 || a[y][x] != 1){
				a[x][y] = 1;
				count++;
			}
		}
 
		if(n == 1 || (n == 2 && flag != 1) || (n == 3 && flag !=1 && count <= 2) || m <= 1){
			printf("YES\n");
            //The problem just wants a yes or no.
        }
        else if(flag == 1){
			printf("NO\n");
            //The problem just wants a yes or no.
        }
        else if(count == 2 ){
			for(i = 1;i<=n;i++)
				for(j =1;j<=n;j++)
					if(a[i][j] == 1 && flag == 0){
						x = i; y = j;
						flag = 1;
					}
					else if(a[i][j] == 1){
						if((i == x) || (i == y) || (j == x) || (j == y))
							flag = 0;
						break;
					}	
			if(flag == 1){
				printf("NO\n");
            }
            else{
				printf("YES\n");
            }
		}
		else
			printf("NO\n");
	}
	return 0;
} 