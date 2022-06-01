package com.shshnk.palindrom;

public class LinkedList {
    Node head,temp;

    void insert(int data)
    {
        temp=new Node(data);
        temp.next=head;
        head=temp;
        System.out.println("Node Insert Successfully");
    }
}
