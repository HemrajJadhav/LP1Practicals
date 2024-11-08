
import java.util.Scanner;

public class FIFO {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int noofpages, capacity, index = 0;
        int hit = 0, fault = 0;
        double faultRatio, hitRatio;
        System.out.print("Enter the number of pages you want to enter: ");
        noofpages = sc.nextInt();
        int pages[] = new int[noofpages];
        System.out.println("Enter the pages : ");
        for (int i = 0; i < noofpages; i++) {
            System.out.print("Enter page " + (i + 1) + ": ");
            pages[i] = sc.nextInt();
        }
        System.out.print("Enter the capacity of frame: ");
        capacity = sc.nextInt();
        int frame[] = new int[capacity];
        int table[][] = new int[noofpages][capacity];

        for (int i = 0; i < capacity; i++) {
            frame[i] = -1;
        }
        System.out.println("\n----------------------------------------------------------------------");
        for (int i = 0; i < noofpages; i++) {
            int search = -1;
            for (int j = 0; j < capacity; j++) {
                if (frame[j] == pages[i]) {
                    search = j;
                    hit++;
                    System.out.printf("%4s", "H");
                    break;
                }
            }
            if (search == -1) {
                frame[index] = pages[i];
                fault++;
                System.out.printf("%4s", "F");
                index++;
                if (index == capacity) {
                    index = 0;
                }
            }
            System.arraycopy(frame, 0, table[i], 0, capacity);
        }
        System.out.println("\n----------------------------------------------------------------------");
        for (int i = 0; i < capacity; i++) {
            for (int j = 0; j < noofpages; j++)
                System.out.printf("%3d ", table[j][i]);
            System.out.println();
        }

        System.out.println("----------------------------------------------------------------------");
        faultRatio = ((double) fault / noofpages) * 100;
        hitRatio = ((double) hit / noofpages) * 100;
        System.out.println("Page Fault: " + fault + "\nPage Hit: " + hit);
        System.out.printf("Hit Ratio:%.2f \nFault Ratio:%.2f ", hitRatio, faultRatio);
        sc.close();
    }

}

/*
 * Output:
 * 
 * Enter the number of pages you want to enter: 20
 * Enter the pages :
 * Enter page1:6
 * Enter page2:1
 * Enter page3:1
 * Enter page4:2
 * Enter page5:0
 * Enter page6:3
 * Enter page7:4
 * Enter page8:6
 * Enter page9:0
 * Enter page10:2
 * Enter page11:1
 * Enter page12:2
 * Enter page13:1
 * Enter page14:2
 * Enter page15:0
 * Enter page16:3
 * Enter page17:2
 * Enter page18:1
 * Enter page19:2
 * Enter page20:0
 * Enter the capacity of frame: 3
 * 
 * ----------------------------------------------------------------------
 * F F H F F F F F F F F H H H H F H H H F
 * ----------------------------------------------------------------------
 * 6 6 6 6 0 0 0 6 6 6 1 1 1 1 1 1 1 1 1 1
 * -1 1 1 1 1 3 3 3 0 0 0 0 0 0 0 3 3 3 3 3
 * -1 -1 -1 2 2 2 4 4 4 2 2 2 2 2 2 2 2 2 2 0
 * ----------------------------------------------------------------------
 * Page Fault: 12
 * Page Hit: 8
 * Hit Ratio:40.00
 * Fault Ratio:60.00
 */
