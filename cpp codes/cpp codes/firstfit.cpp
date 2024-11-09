#include <iostream>

using namespace std;

int main()
{
    int blno,psno;

    cout <<"Enter the number of memory blocks: \t";
    cin >>blno;


    int blocks[blno];

    for (int i=0 ;i<blno;i++){
            cout <<"Enter the size of the block["<<i<<"]:  ";
            cin>>blocks[i];

    }


    cout <<"Enter the processes: \t";
    cin >> psno;

    int prcs[psno];

    for (int i=0 ;i<psno;i++){
            cout <<"Enter the size of the process["<<i<<"]:  ";
            cin>>prcs[i];

    }

    for (int i=0; i< blno;i++){
        for (int j=0;j<psno;j++){
            if (prcs[j]<=blocks[i]){
                cout <<"Process["<<prcs[j]<<"]allocated to block ["<<blocks[i]<<"]\n";
                prcs[j]=100000;
                break;
            }
        }
    }

    for (int j=0;j<psno;j++){
        if (prcs[j]!=100000){
            cout << "Process["<<j<<"]not allocated";
        }
    }
    return 0;
}
