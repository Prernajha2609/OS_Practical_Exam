# OS_Practical_Exam

# PRACTICAL 1
Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way.
Steps to find waiting times of all processes: 
1- Create an array rem_bt[] to keep track of remaining
   burst time of processes. This array is initially a 
   copy of bt[] (burst times array)
2- Create another array wt[] to store waiting times
   of processes. Initialize this array as 0.
3- Initialize time : t = 0
4- Keep traversing the all processes while all processes
   are not done. Do following for i'th process if it is
   not done yet.
    a- If rem_bt[i] > quantum
       (i)  t = t + quantum
       (ii) rem_bt[i] -= quantum;
    c- Else // Last cycle for this process
       (i)  t = t + rem_bt[i];
       (ii) wt[i] = t - bt[i]
       (ii) rem_bt[i] = 0; // This process is over
Once we have waiting times, we can compute turn around time tat[i] of a process as sum of waiting and burst times, i.e., wt[i] + bt[i]



# PRACTICAL 2
fork() is used to create new process by duplicating the current calling process, and newly created process is known as child process and the current calling process is known as parent process. So we can say that fork() is used to create a child process of calling process.
