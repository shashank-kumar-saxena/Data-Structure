package com.shshank.Hashing;

import java.util.Scanner;

public class MyHashFun {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Hashing hash=new Hashing();
        int n;
        while (true)
        {
            System.out.println("Enter Your Choice");
            System.out.println("1 for insert");
            System.out.println("2 for search");
            System.out.println("3 for exit");
            n=sc.nextInt();
            switch (n)
            {
                case 1:
                    System.out.println("Enter the number you want to insert");
                    n=sc.nextInt();
                    hash.insert(n);
                    break;
                case 2:
                    System.out.println("Enter the data you want to search");
                    n=sc.nextInt();
                    if(hash.hashing(n))
                    {
                        System.out.println("Element present");
                    }
                    else
                    {
                        System.out.println("Not Present");
                    }
                    break;
                case 3:
                    System.exit(12);
                    break;
                default:
                    System.out.println("Enter the valid choice");
            }
        }
    }
}
