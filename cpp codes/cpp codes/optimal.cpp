#include <iostream>

using namespace std;
int predict(int page[],int frame[],int  np , int nf , int index){
    int res = -1;
    int farthest = index;

    for (int i=0;i< nf ;i++ ){
        int j ;
        for (j=index;j<np ;j++ ){
            if (frame[i]==page[j]){
                if(j>farthest){
                    farthest =j;
                    res=i;

                }
                break;
            }
        }
        if(j== np ){
            return i;
        }
    }//++++++

    if(res==-1){
        return 0 ;
    }else{
        return res;
    }

}//*****

void Optimal(int np , int nf){
    int hit=0 ;
    int fault = 0;

    int page[np];
    int frame[nf];

    for (int i=0;i<np ;i++ ){
        cout << "Enter the page["<<i+1<<"]";
        cin>> page[i];
    }

    for (int i=0;i<nf ;i++ ){
        frame[i]=-1;
    }

    int flag1,flag2;

    for (int i=0;i<np ;i++ ){
        flag1=flag2=0;
        for (int j=0;j<nf ;j++ ){
            if (page[i]==frame[j]){
                hit++;
                flag1=1;
                flag2=1;
                break;
            }
        }
        if (flag1==0){
            for (int j=0;j< nf ;j++ ){
                if(frame[j]==-1){
                    fault++;
                    frame[j]=page[i];
                    flag2=1;
                    break;

                }
            }
        }
        if (flag2==0){
            fault++;
            int j = predict(page,frame, np , nf , i+1);
            frame[j]=page[i];
        }
        cout << "\n";
        for (int i=0;i<nf ;i++ ){
            cout << frame[i]<<"   ";
        }
    }//+++++++++
        cout << "\nTotal No. of Hits\t"<<hit;
        cout << "\nTotal Number of faults\t"<<fault;


}//***********

int main()
{
   int np , nf;
   cout << "Enter the Number of Reference string Variables: ";
   cin >> np ;
   cout << "Enter the  size of frame: ";
   cin >> nf ;

   Optimal(np, nf);

    return 0;
}

/**/
