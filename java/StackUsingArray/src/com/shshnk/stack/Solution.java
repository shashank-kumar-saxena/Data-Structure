package com.shshnk.stack;

import java.util.Scanner;
import java.util.Stack;

public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        StackClass st=new StackClass();
        System.out.println(st.getTos());
        while (true)
        {
            System.out.println("Enter you choice");
            System.out.println("1 for push\n2 for pop\n3 for exit");
            int n=sc.nextInt();
            switch (n)
            {
                case 1:
                    System.out.println("Enter the element you want to insert");
                    int data=sc.nextInt();
                    st.push(data);
                break;
                case 2:
                    int k= (int) st.pop();
                    if(k!=-1)
                        System.out.println(k);
                    break;
                case 3:
                    System.exit(1);
                    break;
                default:
                    System.out.println("Enter the valid choice");
            }
        }
    }
}
