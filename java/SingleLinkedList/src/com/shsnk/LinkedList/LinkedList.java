package com.shsnk.LinkedList;

public class LinkedList {
    Node head=null;
    Node tra=new Node();
    void insertAtBeg(int data)
    {
        Node temp=new Node();
        temp.data=data;
        temp.next=head;
        head=temp;
        System.out.println("Node Insert Successfully");
    }
    void traverse()
    {
        if(head==null)
        {
            System.out.println("No Element Found");
            return;
        }
        tra=head;
        while(tra!=null)
        {
            System.out.print(tra.data+" ");
            tra=tra.next;
        }
    }
}
