#include<stdio.h>
#define max 100
int arr[max][max];
void dfs(int s,int *visited,int a)
{
	int stack[max]={0};
	int top=-1;
	top++;
	stack[top]=s;
	while(top!=-1)
	{
		int k=stack[top];
		top--;
		if(visited[k]!=1)
		{
			visited[k]=1;
		}
		for(int i=0;i<a;i++)
		{
			if(visited[i]!=1 && arr[k][i]==1)
			{
				top++;
				stack[top]=i;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int i,a,b,c,d,j,k;
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		for(k=0;k<a;k++)
		{
			for(j=0;j<a;j++)
			{
				arr[j][k]=0;
			}
		}
		int visited[a];
		int count=0;
		for(j=0;j<a;j++)
		{
			visited[j]=0;
		}
		for(j=0;j<b;j++)
		{
			scanf("%d %d",&c,&d);
			arr[c][d]=1;
		}
		for(j=0;j<a;j++)
		{
			if(visited[j]==0)
			{
				count++;
				dfs(j,visited,a);
			}
		}
		printf("%d",count);
	}
}
