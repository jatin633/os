#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
            int queue[20],n,head;
			int i,j,k,dist=0,maximum,diff;
            float avgerage;
            printf("==============Developed by Jatin==========\n");
            printf("Enter the maximum range of disk you want\n");
            scanf("%d",&maximum);
            printf("After enter range enter the size of queue request \n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            scanf("%d",&queue[i]);
            printf("Enter the current serving request or initial head position\n");
            scanf("%d",&head);
            queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        dist+=diff;
                        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
            }
            printf("\nTotal distance that the disk arm move  is %d\n",dist);
            avgerage=dist/(float)n;
            printf("Average seek time is %f\n",avgerage);
            return 0;
}
