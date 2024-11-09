#include <iostream>

using namespace std;

int pos(int time[], int nf){
    int loci= 0;
    int mini;
    mini= time[0];
    for (int i = 0 ; i< nf ; i++){
        if(time[i]< mini){
            mini = time[i];
            loci=i;
        }
    }
    return loci;
}

void LRU(int np, int nf){
    int hit = 0;
    int fault = 0 ;

    int page[np];
    int frame[nf];
    int time[nf];


    for (int i=0; i<np; i++){
        cout << "Enter Page string no["<<i+1<<"]"<<"\t";
        cin >> page[i];
        }

    for(int i= 0 ; i< nf ; i++){
        frame[i]= -1;
        time[i] = -1;
    }

    int countf = 0 ;
    int flag1,flag2;

    for (int i= 0 ; i< np ;i++){
        flag1= flag2 = 0 ;
        for (int j= 0 ; j< nf ; j++){
            if (page[i] == frame[j]){
                hit ++;
                countf++;
                time[j]=countf;
                flag1= 1;
                flag2= 1 ;
                break;
            }
        }
        if (flag1==0){
            for(int j=0; j< nf ;j++){
                if (frame[j]==-1){
                    fault+=1;
                    countf++;
                    frame[j]=page[i];
                    time[j]=countf;
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0){
            fault +=1;
            countf++;
            int loci=pos(time,nf);
            frame[loci]=page[i];
            time[loci]=countf;


        }
        cout << "\n";
        for(int i = 0 ; i< nf; i++){
            cout << frame[i]<<"    ";
        }
    }//++++++++++++


}//*************

int main()
{
    int np , nf ;
    cout << "Enter size of reference string: ";
    cin >> np ;
    cout << "Enter size of the frame: ";
    cin >> nf;
    LRU(np , nf);

    return 0;
}


int pos(int nf, int time[]){
    int mini=time[0];
    int loci=0;

    for (int i=0;i<nf;i++){
        if (time[i]<mini){
            mini=time[i];
            loci=i;
        }
    }
    return loci;
}

int lru(int np, int nf){
    
    int hit=0;
    int fault=0;

    int page[np];
    int frame[nf];
    int time[nf];

    for (int i=0 ; i <nf; i++){
        time[i]=-1;
        frame[i]=-1;
    }

    int countf=0;
    int flag0,flag1;

    for(int i=0 ; i< np;i++){
        flag0=0;
        flag1=0;
        for(int j=0;j<nf;j++){
            if (page[i]==frame[j]){
                hit++;
                countf++;
                time[j]=countf;
                flag0=1;
                flag1=1;
                break;

            }
        }


        if (flag1==0){
            for(int j=0;j<nf;j++){
                if (frame[j]==-1){
                        fault++;
                        countf++;
                        frame[j]=page[i];
                        time[j]=countf;
                        flag1=1;
                        break;

                }
            }
        }
        if (flag1==0){
            fault++;
            countf++;
            int loci=pos(nf,time);
            frame[loci]=page[i];
            time[loci]=countf;
        }
        cout <<"/n";
        for (int i=0;i<nf;i++){
            cout <<frame[i]<<"  ";
        }
    }
}

int main()
{
    int np , nf ;
    cout << "Enter size of reference string: ";
    cin >> np ;
    cout << "Enter size of the frame: ";
    cin >> nf;
    lru(np , nf);

    return 0;
}
