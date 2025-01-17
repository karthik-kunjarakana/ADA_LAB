// 1. Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given connected
// undirected graph using Kruskal's algorithm
#include<stdio.h>
#define INFI 99
#define MAX 10
int a[MAX][MAX],b[MAX][MAX],n,cost=0;
void findmin(int * v1,int *v2)//finding the edge having minimum weight.
{
int edge=INFI,i,j;
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
if(a[i][j]>0 && a[i][j]<edge)
{
edge=a[i][j];
*v1=i;
*v2=j;
}
}
void update(int root[],int v1,int v2)
{
int temp,i;
temp=root[v2];
for(i=1;i<=n;i++)
{
if(root[i]==temp)
root[i]=root[v1];
}
}
void kruskal()
{
int i ,v1,v2,root[MAX],edge,count=0;
for(i=1;i<=n;i++)
root[i]=i;
i=0;
while(i!=n-1)
{
findmin(&v1,&v2);
edge=a[v1][v2];
a[v1][v2]=a[v2][v1]=0;//do not select the same edge on next time.
if(root[v1]!=root[v2])
{
printf("(%d,%d)\n",v1,v2);
update(root,v1,v2);
cost+=edge;
i++;
}
}
}
int main()
{
int i,j;
printf("\n Enter the number of vertices : ");
scanf("%d",&n);
printf("\n Enter the weighted graph : \n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("\n Edges of spanning tree are:\n");
kruskal();
printf("\n Minimum cost=%d:",cost);
return(0);
}
