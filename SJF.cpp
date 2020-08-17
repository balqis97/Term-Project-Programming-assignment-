// C++ program to implement Shortest Job first with Arrival Time
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

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
void arrangeArrival(int num, int proc[][3]) {
   for(int i=0; i<num; i++) {
      for(int j=0; j<num-i-1; j++) {
         if(proc[1][j] > proc[1][j+1]) {
            for(int k=0; k<5; k++) {
               swap(proc[k][j], proc[k][j+1]);
            }
         }
      }
   }
}
void completionTime(int num, int proc[][3]) {
   int temp, val ;
   proc[3][0] = proc[1][0] + proc[2][0];
   proc[5][0] = proc[3][0] - proc[1][0];
   proc[4][0] = proc[5][0] - proc[2][0];
    for(int i=1; i<num; i++) {
      temp = proc[3][i-1];
      int low = proc[2][i];
      for(int j=i; j<num; j++) {
         if(temp >= proc[1][j] && low >= proc[2][j]) {
            low = proc[2][j];
            val = j;
         }
      }
      proc[3][val] = temp + proc[2][val];
      proc[5][val] = proc[3][val] - proc[1][val];
      proc[4][val] = proc[5][val] - proc[2][val];
       	
      for(int k=0; k<6; k++) {
         swap(proc[k][val], proc[k][i]);
      }
   }
}
int main() {
   int num = 3, temp, total_wt, total_tat;
   int proc[6][3] = {2201, 3401, 1103, 1, 2, 3, 3, 2, 1};
   cout<<"Before Arrange...\n";
   cout<<"Process ID\tArrival Time\tBurst Time\n";
   for(int i=0; i<num; i++) {
      cout<<proc[0][i]<<"\t\t"<<proc[1][i]<<"\t\t"<<proc[2][i]<<"\n";
   }
   
   arrangeArrival(num, proc);
   completionTime(num, proc);
   cout<<"\nFinal Result...\n\n";
   cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
   for(int i=0; i<num; i++) {
      cout<<proc[0][i]<<"\t\t"<<proc[1][i]<<"\t\t"<<proc[2][i]<<"\t\t"<<proc[4][i]<<"\t\t"<<proc[5][i]<<"\n";
      total_tat = proc[5][0] + proc[5][1] + proc[5][2];
	  total_wt = total_wt + proc[4][i];
   }
   		
    	 cout << "\n\nAverage waiting time = "
         << (float)total_wt/(float)num;
    	cout << "\nAverage turn around time = "
         << (float)total_tat/(float)num;
  	
}
