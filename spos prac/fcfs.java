
import java.util.Scanner;

public class fcfs {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n, temp;
        float avgtat = 0, avgwt = 0;
        System.out.println("*** First come first serve Scheduling ***");
        System.out.print("Enter the number of processes: ");
        n = scan.nextInt();
        int process[] = new int[n];
        int arrivalTime[] = new int[n];
        int burstTime[] = new int[n];
        int completionTime[] = new int[n];
        int TAT[] = new int[n];
        int waitingTime[] = new int[n];

        for (int i = 0; i < n; i++) {
            process[i] = (i + 1);
            System.out.print("\n Enter the arrival time for processor " + (i + 1) + ":");
            arrivalTime[i] = scan.nextInt();
            System.out.println("Enter Burst time for processor" + (i + 1) + ":");
            burstTime[i] = scan.nextInt();

        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arrivalTime[i] > arrivalTime[j]) {
                    temp = process[j];
                    process[j] = process[i];
                    process[i] = temp;
                    temp = arrivalTime[j];
                    arrivalTime[j] = arrivalTime[i];
                    arrivalTime[i] = temp;
                    temp = burstTime[j];
                    burstTime[j] = burstTime[i];
                    burstTime[i] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                completionTime[i] = arrivalTime[i] + burstTime[i];
            } else {
                if (arrivalTime[i] > completionTime[i - 1]) {
                    completionTime[i] = arrivalTime[i] + burstTime[i];
                } else {
                    completionTime[i] = completionTime[i - 1] + burstTime[i];
                }
            }
        }

        System.out.println("\n FCFS");
        System.out.println("Processor\t Arrival time\tBurst time\tCompletion time\tTurn Around time\t Waiting time");
        System.out.println(
                "-------------------------------------------------------------------------------------------------------");

        for (int i = 0; i < n; i++) {
            TAT[i] = completionTime[i] - arrivalTime[i];
            waitingTime[i] = TAT[i] - burstTime[i];
            avgtat += TAT[i];
            avgwt += waitingTime[i];
            System.out.println(process[i] + "\t\t" + arrivalTime[i] + "ms\t\t" + burstTime[i] + "ms\t\t"
                    + completionTime[i] + "ms\t\t" + TAT[i] + "ms\t\t\t" + waitingTime[i] + "ms");
        }
        System.out.println("\n Average turn around time of processor: " + (avgtat / n)
                + "ms\n Average waiting time of processor: " + (avgwt / n) + "ms");
        scan.close();

    }
}

/*
 * Output:
 *** First come first serve Scheduling ***
 * Enter the number of processes: 4
 * 
 * Enter the arrival time for processor 1:0
 * Enter Burst time for processor1:
 * 1
 * 
 * Enter the arrival time for processor 2:2
 * Enter Burst time for processor2:
 * 5
 * 
 * Enter the arrival time for processor 3:2
 * Enter Burst time for processor3:
 * 6
 * 
 * Enter the arrival time for processor 4:3
 * Enter Burst time for processor4:
 * 1
 * 
 * FCFS
 * Processor Arrival time Burst time Completion time Turn Around time Waiting
 * time
 * -----------------------------------------------------------------------------
 * --------------------------
 * 1 0ms 1ms 1ms 1ms 0ms
 * 2 2ms 5ms 7ms 5ms 0ms
 * 3 2ms 6ms 13ms 11ms 5ms
 * 4 3ms 1ms 14ms 11ms 10ms
 * 
 * Average turn around time of processor: 7.0ms
 * Average waiting time of processor: 3.75ms
 * 
 */