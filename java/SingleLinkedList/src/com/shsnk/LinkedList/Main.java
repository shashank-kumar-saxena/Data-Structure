package com.shsnk.LinkedList;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        LinkedList list=new LinkedList();
        int n=0;
        while (true)
        {
            System.out.println("\nEnter your choice");
            System.out.println("1 for insert at beginning");
            System.out.println("2 for traverse");
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
                    list.traverse();
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
