package StakUsingArray;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Queue q =new Queue();
        int n;
        while(true)
        {
            System.out.println("\nEnter your choice");
            System.out.println("1 for enqueue");
            System.out.println("2 for dequeue");
            System.out.println("3 for traverse");
            System.out.println("4 for exit");
            n=sc.nextInt();
            switch (n)
            {
                case 1:
                    System.out.println("Enter your choice");
                    n=sc.nextInt();
                    q.enqueue(n);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.traverse();
                    break;
                case 4:
                    System.exit(1);
                default:
                    System.out.println("Enter the valid choice");
            }
        }
    }
}
