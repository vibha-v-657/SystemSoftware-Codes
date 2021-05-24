#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 

vector<int> processes,bt,wt,atime,tat;
void findWaitTime(int n,int quantum) 
{ 
	vector<int> rem_bt; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt.push_back( bt[i]); 
	int t = 0;  
	while (1) 
	{ 
		bool done = true; 
		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = false;  
				if (rem_bt[i] > quantum) 
				{ 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				else
				{ 
					t = t + rem_bt[i]; 
					wt.push_back(t - bt[i]-atime[i]); 				
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
    
} 
void findTurnAroundTime(int n) 
{ 
    
	for (int i = 0; i < n ; i++) 
    {
		tat.push_back( bt[i] + wt[i]); 
    }
} 
void findAvgTime(int n,int quantum) 
{ 
    float total_wt = 0, total_tat = 0; 
	findWaitTime(n,quantum); 
	findTurnAroundTime(n); 
	cout << "Processes "<<" Arrival time "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" <<atime[i]<<"\t\t"<< bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< total_tat / (float)n; 
} 
int main() 
{  
    vector<int> processes;
    int x;
    cout<<"Enter the number of processes "<<endl;
    cin>>x;
    int quantum;
    cout<<"Enter the Arrival time and burst time for each process "<<endl;
    for(int i=0;i<x;i++)
    {
        processes.push_back(i+1);
        int art,burst_time;
        cin>>art>>burst_time;
        atime.push_back(art);
        bt.push_back(burst_time);
    }
    cout<<"Enter the quantum size for each process "<<endl;
    cin>>quantum;
	findAvgTime(x,quantum); 
	return 0; 
} 
