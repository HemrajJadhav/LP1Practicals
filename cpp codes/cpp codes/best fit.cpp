/*#include <iostream>

using namespace std;

int main()
{

    int nb,np,b[100],p[100],frag[100],temp;
    int bf[25],ff[25];
    int lowest=9999;

    for (int i=0;i<25 ;i++ ){
        bf[i]=0;
        ff[i]=0;
    }

    cout <<"Enter the number of processes: ";
    cin >>np;
    cout <<"Enter the number of blocks:  ";
    cin >>nb;

    for (int i=1;i<=np;i++){
        cout << "Enter the size of p["<<i<<"]   ";
        cin>>p[i];

    }

    for (int i=1;i<=nb;i++){
        cout << "Enter the size of b["<<i<<"]   ";
        cin>>b[i];

    }

    for (int i=1;i<=np;i++){
        for (int j= 1;j<=nb;j++){
            if (bf[j]!=1){
                temp=b[j]-p[i];
                if (temp>=0){
                    if (lowest >temp){
                            ff[i]=j;
                        lowest=temp;
                    }
                }
            }
        }
        frag[i]= lowest;
        bf[ff[i]]=1;
        lowest=9999;
    }
    cout <<"process no: \t"<<"process size\t"<<"block no\t"<<"block size\t"<<"fragment\n";
    for (int i =1 ; i< np && ff[i]!=0 ;i++)
        {
        cout <<"\n"<<i<<"\t"<<p[i]<<"\t"<<ff[i]<<"\t"<<b[ff[i]]<<"\t"<<frag[i];
        }


    return 0;
}
*/

/*#include <iostream>

using namespace std;

int main() {
    int nb, np, b[100], p[100], frag[100], temp;
    int bf[25], ff[25];
    int lowest;

    // Initialize arrays to 0
    for (int i = 0; i < 25; i++) {
        bf[i] = 0;
        ff[i] = 0;
    }

    cout << "Enter the number of processes: ";
    cin >> np;
    cout << "Enter the number of blocks: ";
    cin >> nb;

    // Input process sizes
    for (int i = 0; i < np; i++) {
        cout << "Enter the size of p[" << i + 1 << "]: ";
        cin >> p[i];
    }

    // Input block sizes
    for (int i = 0; i < nb; i++) {
        cout << "Enter the size of b[" << i + 1 << "]: ";
        cin >> b[i];
    }

    // Best Fit Allocation
    for (int i = 0; i < np; i++) {
        lowest = 9999;
        for (int j = 0; j < nb; j++) {
            if (bf[j] != 1) {  // If block is not allocated
                temp = b[j] - p[i];
                if (temp >= 0) {  // If block can accommodate the process
                    if (lowest > temp) {
                        ff[i] = j;  // Store block index for process i
                        lowest = temp;
                    }
                }
            }
        }
        frag[i] = lowest;  // Store the fragmentation for process i
        bf[ff[i]] = 1;  // Mark the block as allocated
    }

    // Output the allocation result
    cout << "Process no\tProcess size\tBlock no\tBlock size\n";
    for (int i = 0; i < np; i++) {
        if (ff[i] != 0) {  // If the process is allocated
            cout << i + 1 << "\t\t" << p[i] << "\t\t" << ff[i] + 1 << "\t\t" << b[ff[i]]<<endl;
        } else {
            cout << i + 1 << "\t\t" << p[i] << "\t\t" << "Not Allocated" << endl;
        }
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int nb, np, b[100], p[100], frag[100], temp;
    int bf[100] = {0}, ff[100] = {0};
    int lowest;

    cout << "Enter the number of processes: ";
    cin >> np;
    cout << "Enter the number of blocks: ";
    cin >> nb;

    for (int i = 1; i <= np; i++) {
        cout << "Enter the size of p[" << i << "]: ";
        cin >> p[i];
    }

    for (int i = 1; i <= nb; i++) {
        cout << "Enter the size of b[" << i << "]: ";
        cin >> b[i];
    }

    // Best Fit Allocation Logic
    for (int i = 1; i <= np; i++) {
        lowest = 9999;  // Reset lowest for each process
        for (int j = 1; j <= nb; j++) {  // Correct the loop condition
            if (bf[j] == 0) {  // Check if block is free
                temp = b[j] - p[i];
                if (temp >= 0 && temp < lowest) {  // Find the block with minimum fragmentation
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        if (lowest != 9999) {  // If a suitable block was found
            frag[i] = lowest;
            bf[ff[i]] = 1;  // Mark block as used
        } else {
            ff[i] = 0;  // Mark process as not allocated
        }
    }

    // Output the allocation
    cout << "Process no\tProcess size\tBlock no\tBlock size\n";
    for (int i = 1; i <= np; i++) {
        if (ff[i] != 0) {
            cout << i << "\t\t" << p[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << endl;
        } else {
            cout << i << "\t\t" << p[i] << "\t\tNot Allocated\n";
        }
    }

    return 0;
}
*///************************************************************************************8
#include <iostream>
using namespace std;

int main(){
    int np,nb,b[100],p[100],frag[100],temp;
    int bf[100]={0},ff[100]={0};
    int lowest;

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
        lowest=99999;
        for (int j=1;j<=nb;j++){
            temp=b[j]-p[i];
          if (bf[j]==0){
            if (temp>=0 && temp<=lowest){
                    ff[i]=j;
                    lowest=temp;
            }
          }
        }
        if (lowest != 9999){
            frag[i]=lowest;
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
