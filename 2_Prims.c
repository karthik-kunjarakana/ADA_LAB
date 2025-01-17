// 2. Design and implement C/C++ Program to find Minimum Cost Spanning Key of a given connected
// undirected graph using Prim’s Algorithm.
#include<stdio.h>
#define INFI 99
int edges[10][3],n,wt[10][10];;
void prims();
void main()
{
int i,j;
printf("\n Enter the number of vertices: ");
scanf("%d",&n);
printf("\n Enter the cost matrix? \n");
for( i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&wt[i][j]);
prims();
}
void prims()
{
int u[10],lowcost[10],visited[10];
int min,mincost=0,i,j,v;
//mark nodes as unvisited
visited[1]=1;
//find low cost edge
for(i=2;i<=n;i++)
{
visited[i]=0;
u[i]=1;
lowcost[i]=wt[1][i];
}
for(i=1;i<=n-1;i++)
{ min=lowcost[2];
v=2;
for(j=3;j<=n;j++)
{
if(lowcost[j]<min)
{
min=lowcost[j];
v=j;
}
}
//save edge
edges[i][1]=u[v];
edges[i][2]=v;
mincost+=lowcost[v];
visited[v]=1;
lowcost[v]=INFI;
for(j=2;j<=n;j++)
if(wt[v][j]<lowcost[j] && !visited[j])
{
lowcost[j]=wt[v][j];
u[j]=v;
}
}
printf("\n\n The edges of this minimum cost spanning tree are\n");
for(i=1;i<=n-1;i++)
printf(" (%d,%d)\n",edges[i][1],edges[i][2]);
printf("\n Minimum cost Spanning Tree is:%d",mincost);
}
