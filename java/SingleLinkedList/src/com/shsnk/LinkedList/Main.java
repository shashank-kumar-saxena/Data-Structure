package com.shsnk.LinkedList;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        LinkedList list=new LinkedList();
        int n=0,data;
        while (true)
        {
            System.out.println("\nEnter your choice");
            System.out.println("1 for insert at beginning");
            System.out.println("2 for insert at end");
            System.out.println("3 for insert at specific position");
            System.out.println("4 for insert after specific element");
            System.out.println("5 for traverse");
            System.out.println("6 for delete element from starting");
            System.out.println("7 for delete element from end");
            System.out.println("13 for exit");
             n=sc.nextInt();
            switch (n)
            {
                case 1:
                    System.out.println("Enter the element you want to insert");
                    n=sc.nextInt();
                    list.insertAtBeg(n);
                    break;
                case 2:
                    System.out.println("Enter the data you want to insert");
                    n=sc.nextInt();
                    list.insertAtEnd(n);
                    break;
                case 3:
                    System.out.println("Enter the position and element you want to insert");
                    n=sc.nextInt();
                    data=sc.nextInt();
                    list.insertAtSpecificPosition(n,data);
                    break;
                case 4:
                    System.out.println("Enter the element after you want to insert element and also give element");
                    n= sc.nextInt();
                    data=sc.nextInt();
                    list.insertAfterElement(n,data);
                    break;
                case 5:
                    list.traverse();
                    break;
                case 6:
                    list.deleteStarting();
                    break;
                case 7:
                        list.deleteEnd();
                    break;
                case 13:
                    System.exit(1);
                    break;
                default:
                    System.out.println("Enter the valid choice");
            }
        }
    }
}
