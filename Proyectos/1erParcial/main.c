#include<stdio.h>

int a[10];
int ans[50];
int n,m;

void inc(){
	a[n]++;
	int i=n;
	while(a[i] == 10){
		a[i]=0;
		i--;
		a[i]++;
	}
}
int getSum()
{
	int sum=0,i;
	for(i=1;i<=n;i++)
		sum=sum+a[i];
	return sum;
}
int main() 
{
	int i,j,b,c,d;
	scanf("%d",(int) m);
	n=m/2;
	while(a[0]==0)
	{
		ans[getSum()]++;
		inc();
	}
	for(i=0;i<=n;i++)
		a[i]=0;
	int finAns=0;
	while(a[0]==0)
	{
		finAns=finAns+ans[getSum()];
		inc();
	}
	printf("Resultado: %d",finAns);
	return 0;
} 