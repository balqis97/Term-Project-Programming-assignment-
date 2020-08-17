# Group Members
1. Sofian Nadilah (1730600)
2. Siti Nurbalqis binti Saharudin (1715230)
3. Julyana binti Rahmad (1912068)
4. Nurul Yuhana Natasha binti Yusri (1812590)

# Introduction

In various circumstances, not every algorithm works better on the significant job. Sometimes, FCFS algorithm is better than the other in short burst time while Priority Scheduling and SJF is better for multiple processes in every single time. However, it cannot be expected what process will come after. Therefore, we want to compare three algorithms between FCFS, SJF and Priority Scheduling. The target is to know which is the best scheduling algorithm to implement in finding the best Class Scheduling solution. Firstly, FCFS is the simplest operating system scheduling algorithm that automatically executes queued requests and processes by order of their arrival. It supports non-preemptive and preemptive scheduling algorithms. A real-life example of the FCFS method is buying a movie ticket on the ticket counter. It is a Non-Preemptive CPU scheduling algorithm, so after the process has been allocated to the CPU, it will never release the CPU until it finishes executing.
Then, SJF scheduling algorithms are based upon the burst time of the process. The processes are put into the ready queue based on their burst times. In this algorithm, the process with the least burst time is processed first. This scheduling method can be preemptive or nonpreemptive. It significantly reduces the average waiting time for other processes awaiting execution. In short, it is associated with each job as a unit of time to complete. Lastly, Priority Scheduling Algorithm is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority. In Priority Preemptive Scheduling, the tasks are mostly assigned with their priorities. Meanwhile, in the Priority Non-preemptive scheduling method, the CPU has been allocated to a specific process. Processes are executed on the basis of priority so high priority does not need to wait for long which saves time. If high priority processes take lots of CPU time, then the lower priority processes may starve and will be postponed for an indefinite time. 

# Consideration

FCFS could not stimulate priority scheduling for all possible parameters of priority scheduling because suppose job one(1) arrives at time one(1) with priority ten(10) and length 1,000,000 and job two(2) arrives at time two(2) with priority one(1) and length 1,000,000. FCFS will run job one(1) to completion, then job two(2) to completion. Priority will run job one(1) for one(1) unit, then job two(2) to completion, then job one(1) to completion. Meanwhile, priority scheduling can stimulate FCFS for all possible parameters of FCFS as we assume that the priority queue breaks ties with FCFS and infinite time quantum meaning that all jobs equal priority. 

# Analysis

## FCFS

FCFS algorithms doesn't include any complex logic, it just puts the process requests in a queue and executes it one by one. Hence is preety simpke and easy to implement. In short, every process will get a chance to run, so starvation doesn't occur.

Course code : 2201  
Duration : 3  
Priority : 2  
Arrival time : 1  

Course code : 3401  
Duration : 2  
Priority : 3  
Arrival time : 2  

Course code : 1103  
Duration : 1  
Priority : 1  
Arrival time : 3  

### Output
Total Waiting Time	= Waiting Time P1 +Waiting Time P2 + Waiting Time P3
	=0+3+5
	=8

Average Waiting Time	=Total Waiting Time/Total Process
	=8/3
	=2.66667

## SJF

Short Job First(SJF) algorithms is one of the most common scheduling algorithms in the batch system. Each process is assigned a priority. The highest priority is to be executed first and so on. If same priority, it executed based on FCFS served basis. Priority can be decided based on memory requirement, time requirements or any other resource requirement. 

Course code : 2201  
Duration : 3   
Waiting time : 0 

Course code : 3401  
Duration : 2  
Waiting time : 1  

Course code : 1103  
Duration : 1   
Waiting time : 3 

### Output
Total Waiting Time	= Waiting Time P1 +Waiting Time P2 + Waiting Time P3
	=0+1+3
	=4

Average Waiting Time	=Total Waiting Time/Total Process
	=4/3
	=1.333

## Priority Scheduling

Priority Scheduling algorithms provide a good mechanism where the relative importance of each process maybe precisely defined. Then the priority of a process can be selected baesd on memory requirement, time requirement or user preference. 

Course code : 2201  
Duration : 3   
Priority : 2
Waiting time : 0 

Course code : 3401  
Duration : 2  
Priority : 3
Waiting time : 1  

Course code : 1103  
Duration : 1   
Priority : 1
Waiting time : 4

### Output
Total Waiting Time	= Waiting Time P1 +Waiting Time P2 + Waiting Time P3
	=0+1+4
	=5

Average Waiting Time	=Total Waiting Time/Total Process
	=5/3
	=1.6667
  
# Conclusion

The calculation of three algorithms shows the different average waiting time. The FCFS is better for small burst time and for SJF is good in time more faster than two algorithm. All algorithms are good, but the speed of the process depends on the processor load.
