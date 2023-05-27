#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CITY_LENS  11
#define MAX_COST 200000
#define MAX_NO 10000
int graph[MAX_NO][MAX_NO];
int n;
char cities[MAX_NO][MAX_CITY_LENS];
int previous[MAX_NO];
int dis[MAX_NO];

int min_dis_find(int visited[],int *index);

void initialise()
{
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        graph[i][j]=-1;


    }
}

void addconnection(int sourceindex,int destinationindex,int cost)
{

    graph[sourceindex][destinationindex]=cost;

   // if paths are bidirectional uncomment this line-
   // graph[destinationindex][sourceindex]=cost;
    
}

void dijkstras(char start[], char end[])
{
    int startindex,endindex;
    for(int i=0;i<n;i++)
    {
        if(strcmp(start,cities[i])==0)
        startindex=i;

        if(strcmp(end,cities[i])==0)
        endindex=i;
    }


    int visited[MAX_NO];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        previous[i]=-1;
        dis[i]=MAX_COST;
    }
    dis[startindex]=0;

    visited[startindex]=-1;

    int min_dis= MAX_COST+1;

    int currentindex=startindex;

    int count=0;

    while(count<(n-1))
    {
       // printf("hi")

        for(int i=0;i<n;i++)
        {
            if(visited[i]!=-1 && dis[currentindex]!= MAX_COST && graph[currentindex][i]!=-1 && (dis[currentindex]+graph[currentindex][i])<dis[i])
            {
                dis[i]=dis[currentindex] + graph[currentindex][i];
                previous[i]=currentindex;
            }
        }

        count++;
        min_dis=min_dis_find(visited,&currentindex);

        visited[currentindex]=-1;
    }

    //printf("The minimum cost from city %s to city %s is ", cities[startindex],cities[endindex]);
    printf("%d\n",dis[endindex]);
}

int min_dis_find(int visited[],int *index)
{
    int min=MAX_COST;
    for(int i=0;i<n;i++)
    {
        if(visited[i]!=-1 && dis[i]<min)
        {
            min=dis[i];
            *index=i;
        }
    }
    return min;
}

void dijkstras_runner()
{
   // printf("enter number of test cases");
    int s;
   scanf("%d",&s);
for(int x=0;x<s;x++)
{
   
   // printf("enter number of cities=");
    scanf("%d",&n);
    
    initialise();

     
    int p,nr,cost;
    for(int y=0;y<n;y++)
    {
   // printf("enter city names=");
     scanf("%s",cities[y]);
     
    // printf("number of connections for this city");
     scanf("%d",&p);
     for(int z=0;z<p;z++)
     {
       //printf("enter neighbour index and the cost of transport");
        scanf("%d %d",&nr,&cost);
        addconnection(y,nr-1,cost);
     }

    }
   // printf("paths you want to find");
    int r;
    scanf("%d",&r);
    char sourcestore[100][11],destinationstore[100][11];

for(int m=0;m<r;m++)
{
    
    //printf("enter start point=");
    scanf("%s",sourcestore[m]);

    //printf("enter end point=");
    scanf("%s",destinationstore[m]);

}

for(int m=0;m<r;m++)
dijkstras(sourcestore[m],destinationstore[m]);
    
}

}

int main()
{
    dijkstras_runner();

    return 0;
}
