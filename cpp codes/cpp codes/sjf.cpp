#include <iostream>

using namespace std;
struct Pro{
    int pid;
    int arrivalTime ;
    int burstTime ;
    int completionTime;
    int turnaroundTime;
    int waitingTime;

};

void acceptance(Pro proc[],int n ){

    for(int i=0;i<n;i++){
            proc[i].pid = i+1;
        cout << "Enter the (ArrivalTime,BurstTime) of p "<<i<<":"<<endl;
        cin >>proc[i].arrivalTime>>proc[i].burstTime;
    }


}

void findSJF(Pro proc[], int n){
        int completed=0;
        int shortest=-1;
        int minBurst=9999;
        int currentTime=0;

        int remaining[n];
        bool iscompleted[n]={false};

        for (int i=0;i<n;i++){

            remaining[i]=proc[i].burstTime;

        }

        while (completed <n){

            minBurst=9999;

            for (int i=0;i<n;i++ ){
                if (proc[i].arrivalTime<=currentTime && !iscompleted[i] && remaining[i]<minBurst ){

                    minBurst=remaining[i];
                    shortest=i;
                }
            }

            if (shortest==-1){

                currentTime++;
                continue;

            }

            remaining[shortest]--;
            currentTime++;

            if (remaining[shortest]==0){
                completed ++;

                iscompleted[shortest]=true;

                proc[shortest].completionTime=currentTime;
                proc[shortest].turnaroundTime= proc[shortest].completionTime-proc[shortest].arrivalTime;
                proc[shortest].waitingTime= proc[shortest].turnaroundTime-proc[shortest].burstTime;

            }

        }

}

/*void findSJF(Pro proc[],int n){
    int current=0;
    int completed=0;
    int ShortestIndex=0;
    int minBurst =9999;
    int remaining[n];

    for (int i=0 ;i<n ;i++){

        remaining[i]=proc[i].burstTime;

    }

    while (completed<n){

        minBurst=9999;
        for (int i=0 ; i<n ;i++){
            if (proc[i].arrivalTime<=current && remaining[i]<minBurst && remaining[i]>0){
                minBurst = remaining[i];
                ShortestIndex=i;


            }

        remaining[ShortestIndex]--;

        if (remaining[ShortestIndex]==0){
            completed ++;
            proc[ShortestIndex].completionTime = current+1;
            proc[ShortestIndex].turnaroundTime = proc[ShortestIndex].completionTime - proc[ShortestIndex].arrivalTime;
            proc[ShortestIndex].waitingTime = proc[ShortestIndex].turnaroundTime - proc[ShortestIndex].burstTime;

        }

        current++;



    }

}
}*/

void PrintPro(Pro proc[], int n){
    cout <<"PID\t\t"<<"Arrival Time\t\t"<<"Burst Time\t\t"<<"Completion Time\t\t"<<"Turnaround Time\t\t"<<"Waiting Time"<<endl;

    for (int i=0 ; i<n ;i++){
        cout << proc[i].pid<<"\t\t" << proc[i].arrivalTime <<"\t\t\t" << proc[i].burstTime<<"\t\t\t"  << proc[i].completionTime<<"\t\t\t"  << proc[i].turnaroundTime<<"\t\t\t" << proc[i].waitingTime<<endl;
    }
}

int main()
{
    int n ;
    cout << "Enter the Number of processes:  ";
    cin >> n ;
    Pro proc[n];
    acceptance (proc, n);
    findSJF(proc,n);

    PrintPro(proc,n);



    return 0;
}
