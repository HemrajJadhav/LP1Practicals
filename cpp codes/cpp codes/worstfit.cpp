#include <iostream>
using namespace std;

int main(){
    int np,nb,b[100],p[100],frag[100],temp;
    int bf[100]={0},ff[100]={0};
    int highest;

    cout <<"Enter the number of processes: ";
    cin>>np;
    cout<<"Enter the number of blocks:  ";
    cin>>nb;
    for (int i= 1;i<=np;i++){
        cout <<"Enter the size of process["<<i<<"]   ";
        cin>>p[i];
    }
    cout <<"*****************************************\n";

    for (int i= 1;i<=nb;i++){
        cout <<"Enter the size of block["<<i<<"]   ";
        cin>>b[i];
    }

    for (int i=1;i<=np;i++){
        highest=0;
        for (int j=1;j<=nb;j++){
            temp=b[j]-p[i];
          if (bf[j]==0){
            if (temp>=0 && temp>highest){
                    ff[i]=j;
                    highest=temp;
            }
          }
        }
        if (highest!= 0){
            frag[i]=highest;
            bf[ff[i]]=1;
        }
        else{
            ff[i]=0;
        }

    }
    cout <<"process no"<<"\t\t"<<"processsize"<<"\t"<<"blockno\t"<<"blocksize\n";
    for (int i =1;i<=np;i++){
        if (ff[i]!=0){
            cout <<i<<"\t"<<p[i]<<"\t"<<ff[i]<<"\t"<<b[ff[i]]<<"\n";
        }else{
        cout <<i<<"\t"<<p[i]<<"\tnot allocated!\n";
        }
    }

return 0;
}
