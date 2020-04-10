#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
    int btime[20],p[20],wt[20];
	int tat[20],pr[20],i,j,n,total=0,pos,tmp,avg_wt,avg_tat;
	 printf("            ==============Developed by Jatin==========\n");
    printf("            Enter Total Number of Process you want:");
    scanf("%d",&n);
 
    printf("            After Enter Number of process Enter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("            Burst Time :");
        scanf("%d",&btime[i]);
        printf("            Priority: ");
        scanf("            %d",&pr[i]);
        p[i]=i+1;          
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        tmp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=tmp;
 
        tmp=btime[i];
        btime[i]=btime[pos];
        btime[pos]=tmp;
 
        tmp=p[i];
        p[i]=p[pos];
        p[pos]=tmp;
    }
 
    wt[0]=0;	
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=btime[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;   
    total=0;
 
    printf("            \nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=btime[i]+wt[i];    
        total+=tat[i];
        printf("            \nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],btime[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;  
    printf("            \n\n Waiting Time=%d",avg_wt);
    printf("            \nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
