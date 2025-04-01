
#include<stdio.h>
#include<stdlib.h>
int pl[10][5][3];
int av[3];
int main()
{
    int n,i,j;
    printf("enter number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        pl[i][0][0]=i;
        pl[i][1][0]=0;
        printf("enter the allocations of process P%d A,B,C ",i);
        scanf("%d %d %d",&pl[i][2][0],&pl[i][2][1],&pl[i][2][2]);
        printf("enter the max values of process P%d A,B,C ",i);
        scanf("%d %d %d",&pl[i][3][0],&pl[i][3][1],&pl[i][3][2]);
        pl[i][4][0]=pl[i][3][0]-pl[i][2][0];
        pl[i][4][1]=pl[i][3][1]-pl[i][2][1];
        pl[i][4][2]=pl[i][3][2]-pl[i][2][2];
    }
    printf("enter available");
    scanf("%d %d %d",&av[0],&av[1],&av[2]);
    j = 0;
    int k = 0;
    while(j<n)
    {
        for(i=0;i<n;i++)
        {
            if((pl[i][4][0]<=av[0])&&(pl[i][4][1]<=av[1])&&(pl[i][4][2]<=av[2]))
            {
                if(pl[i][1][0]==0){
                    av[0]=av[0]+pl[i][2][0];
                    av[1]=av[1]+pl[i][2][1];
                    av[2]=av[2]+pl[i][2][2];
                    j=j+1;
                    pl[i][1][0]=1;
                }
            }
        }
        k++;
        if(k>=n)
        {
             break;
        }
    }
    printf("final available: %d %d %d",av[0],av[1],av[2]);
    return 0;
}
