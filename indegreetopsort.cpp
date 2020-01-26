#include<stdio.h>

int n,adj[50][50];

int front = -1,rear = -1,queue[50];
void enqueue(int n)
{
    if(front==-1)
    {
        front=0;
        rear =0;
        queue[0]=n;
    }
    queue[rear++]=n;

}
int delete_queue()
{
    int a=queue[front++];
    return a;
}
void create_graph()
{
    int i,v1,edge,v2;

    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter no of Edges = ");
    scanf("%d",&edge);

    for(i = 1; i <= edge; i++)
    {

        printf("n Enter edge %d :",i);
        scanf("%d %d",&v1,&v2);
        adj[v1][v2] = 1;

    }

}


int indegree(int node)
{

    int i,in_degree = 0;
    for(i = 1; i <= n; i++)
        if(adj[i][node] == 1)
            in_degree++;
    return in_degree;

}
int main()
{
    int i,j = 0,k;

    int topsort[50],indeg[50];

    create_graph();

    for(i=1; i<=n; i++)
    {

        indeg[i]=indegree(i);
        if(indeg[i]==0)
            enqueue(i);

    }

    while(front<=rear)
    {
        k=delete_queue();
        topsort[j++]=k;
        for(i=1; i<=n; i++)
        {
            if(adj[k][i]==1)
            {
                adj[k][i]=0;
                indeg[i]=indeg[i]-1;
                if(indeg[i]==0)
                    enqueue(i);
            }
        }
    }

    printf("After sorting  :");

    for(i=0; i<=n; i++)

        printf("%d  ",topsort[i]);

}
