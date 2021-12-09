#include<iostream> 
using namespace std; 

void fWaitingTime(int bt[],int n, int wt[], int quantum){ 
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; 

	while (1){ 
		bool done = true; 
		for (int i = 0 ; i < n; i++){ 
			if (rem_bt[i] > 0){ 
				done = false;
				if (rem_bt[i] > quantum){  
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				else{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
} 

void fTurnAroundTime(int bt[], int n, int wt[], int tat[]){ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int bt[], int n, int quantum){ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
 
	fWaitingTime(bt, n, wt, quantum); 
	fTurnAroundTime(bt, n, wt, tat); 
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 

	for (int i=0; i<n; i++){ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "\nAverage waiting time = "<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

int main() 
{   int n,time_slice;
    cout<<"\n Enter Number of Process: ";
    cin>>n;
    int bt[n];
    cout<<"\n Enter Burst time for each process:\n";
    for(int i=0; i<n; i++){
        cout<<"Process P"<<(i+1)<<" : ";
        cin>>bt[i];
    }
    
    cout<<"\nEnter time slice: ";
    cin>>time_slice;
	findavgTime(bt,n,time_slice); 
	return 0; 
} 
