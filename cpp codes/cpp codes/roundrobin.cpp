/*#include <iostream>

using namespace std;

struct Pro{

    int PID;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;


};

void acceptance(Pro proc[],int n ){

    for(int i=0;i<n;i++){
            proc[i].PID = i+1;
        cout << "Enter the (ArrivalTime,BurstTime) of p "<<i<<":"<<endl;
        cin >>proc[i].AT>>proc[i].BT;

    }


}

void CalculateCT(Pro proc[],int n,int QT){
    int current = 0;
    int remaining[n];

    for (int i=0 ; i< n ;i++){

        remaining[i]=proc[i].BT;


    }
     bool alldone = false;

    while (!alldone){

        alldone = true ;

        for (int i=0 ; i< n ;i++){

                if (remaining[i]>0 ){
                        alldone=false;
                    if (remaining[i]>QT){
                        current+=QT;
                        remaining[i]-=QT;

                    }
                    else {
                        current+=remaining[i];
                        remaining[i]=0;
                        proc[i].CT=current;
                    }

                }

        }
    }
}




int main()
{
    int n ;
    int QT;


    cout << "Enter the Number of processes:  ";
    cin >> n ;
    cout << "Enter the Time Quantum:  ";
    cin >> QT;

     Pro proc[n];

    acceptance(proc,n);
    CalculateCT(proc,n,QT);

    return 0 ;

}
*/
#include<iostream>

using namespace std;

struct process{
    int pid ;
    int art;
    int bt;
    int ct ;
    int tat;
    int wt;

};



void roundrobin(process proc[],int n , int qt){
    int current=0;
    int remaining[n];
    for (int i=0;i<n  ;i++ ){
        remaining[i]=proc[i].bt;

    }

    bool alldone=false;

    while(!alldone){
        alldone =true;
        for(int i = 0 ; i<n;i++){
            if (remaining[i]>0){
                alldone=false;
                if (remaining[i]>qt){
                    current +=qt;
                    remaining[i]-=qt;

                }else{
                    current=current+remaining[i];
                    remaining[i]=0;
                    proc[i].ct=current;
                }
            }
        }
    }
}

void calctat(process proc[],int n){
    for (int i=0;i< n;i++){

        proc[i].tat=proc[i].ct-proc[i].art;


    }
}

void calcwt(process proc[],int n){
    for (int i=0;i< n;i++){

        proc[i].wt=proc[i].tat-proc[i].bt;


    }
}

int main(){
    int n =4;
    process proc[n];
    int qt=2;

    for(int i = 0; i<n;i++){
        cout <<"Enter arrival time and curst time: ";
        cin>>proc[i].art>>proc[i].bt;
        proc[i].pid=i+1;
    }

    roundrobin(proc,n,qt);
    calctat(proc,n);
    calcwt(proc,n);

    cout << "\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].art << "\t" << proc[i].bt << "\t"
             << proc[i].ct << "\t\t" << proc[i].tat << "\t\t" << proc[i].wt << endl;
    }
return 0;
}
