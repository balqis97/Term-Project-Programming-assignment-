#include<iostream>
 
using namespace std;

struct Process
{
   int ccode;     // course code
   int duration;      // class duration
   int priority;  //priority
   int arrival_time;   //prefered arrival time
};
 
// courses CSC2201 with priority 2 for 3 hours with prefered to start first, 
// CSC3401 with priority 3 for 2 hours prefered to start second, 
// and CSC1103 with priority 1 for 1 hour 
//Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};

int main()
{
    int waiting_time[20],turnaround_time[20],i,j,n,total=0,pos,temp;
    int ccode[3]= {2201,3401,1103};
    int duration[3] = {3,2,1};
    int priority[3] = {2,3,1};
    n = 3;


    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
 
        temp=duration[i];
        duration[i]=duration[pos];
        duration[pos]=temp;
 
        temp=ccode[i];
        ccode[i]=ccode[pos];
        ccode[pos]=temp;
    }
 
    waiting_time[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=duration[j];
 
        total+=waiting_time[i];
    }
 
    float avg_wt=(float)total/(float)n;    //average waiting time
    total=0;
 
    cout<<"\nProcess\t    Duration   \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turnaround_time[i]=duration[i]+waiting_time[i];     //calculate turnaround time
        total+=turnaround_time[i];
        cout<<"\nP["<<ccode[i]<<"]\t\t  "<<duration[i]<<"\t\t    "<<waiting_time[i]<<"\t\t\t"<<turnaround_time[i];
    }
 
    float avg_tat=(float)total/(float)n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time = "<<avg_wt;
    cout<<"\nAverage Turnaround Time = "<<avg_tat;
 
    return 0;
}
