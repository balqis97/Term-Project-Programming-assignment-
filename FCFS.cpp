#include <iostream>

using namespace std;

const int size = 3;
 
struct Process
{
   int ccode;     // course code
   int duration;      // class duration
   int priority;  //priority
   int arrival_time;   //prefered arrival time
};

void sortData(Process[], int);
void findWaitingTime(Process [], int, int);
void findTurnAroundTime(Process [], int, int, int);
void findAverageTime(Process [], int);

int main()
{
	// courses CSC2201 with priority 2 for 3 hours with prefered to start first, 
	// CSC3401 with priority 3 for 2 hours prefered to start second, 
	// and CSC1103 with priority 1 for 1 hour 
	Process proc[size] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};
	
	for (int i=0; i<size; i++)
	{
		cout << "Course code : " << proc[i].ccode << endl;
		cout << "Duration : " << proc[i].duration << endl;
		cout << "Priority : " << proc[i].priority << endl;
		cout << "Arrival time : " << proc[i].arrival_time << "\n" << endl;
	}
	
	cout << endl;
	
	sortData(proc, size);

	findAverageTime(proc, size);
	
	return 0;
}

//sorting data according course code & arrival time
void sortData(Process p[size], int size)
{
	bool swap = true;
	while(swap)
	{
		swap = false;
		for(int i = 0; i > size-1; i++)
		{
			if(p[i].ccode > p[i+1].ccode)
			{
				if(p[i].arrival_time < p[i+1].arrival_time)
				{
					swap = true;
				
					Process temp = p[i];
					p[i] = p[i+1];
					p[i + 1] = temp;
				}
			}
		}
	}
}

// function to find the waiting time for all processes
void findWaitingTime(Process p[size], int size, int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;
    // calculating waiting time

    for (int i = 1; i < size ; i++)
    {
        wt[i] = p[i-1].duration + wt[i-1];
    }

}

// function to calculate turn around time
void findTurnAroundTime(Process p[size], int size, int wt[], int tat[])
{
    // calculating turnaround time by adding
    for (int i = 0; i < size ; i++)
    {
        tat[i] = p[i].duration + wt[i];
        
    }
    
}

void findAverageTime(Process p[size], int size)
{
    int wt[size], tat[size], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(p, size, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(p, size, wt, tat);
 
    // display processes along with all details
    cout << "Course Code  "<< " Duration  "<< " Waiting time  " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < size; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " <<p[i].ccode << "\t\t" << p[i].duration <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "\nAverage waiting time = "<< (double)total_wt / size;
    cout << "\nAverage turn around time = "<< (double)total_tat / size;
}


