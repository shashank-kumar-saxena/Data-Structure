package com.shsnk.LinkedList;

import java.util.Scanner;

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
    void insertAtEnd(int data)
    {
        Node temp=new Node();
        temp.data=data;
        temp.next=null;
        if(head==null)
        {
            head=temp;
            System.out.println("Node Insert Successfully");
            return;
        }
        tra=head;
        while (tra.next!=null)
        {
            tra=tra.next;
        }
        tra.next=temp;
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
    void insertAtSpecificPosition(int pos,int data)
    {
        tra=head;
        Node temp=new Node();
        if(head==null&&pos!=1)
        {
            System.out.println("List not found");
        }
        temp.data=data;
        if(pos==1)
        {
            temp.next=head;
            head=temp;
            System.out.println("Node Insert Successfully");
            return;
        }
        pos--;
        while (pos>1&&tra!=null)
        {
            pos--;
            tra=tra.next;
        }
        temp.next=tra.next;
        tra.next=temp;
        System.out.println("Node Insert Successfully");
    }

    void insertAfterElement(int element,int data)
    {
        if(head==null)
        {
            System.out.println("No Data Found");
            return;
        }
        tra=head;
        while (tra!=null)
        {
            if(tra.data==element)
            {
                break;
            }
            tra=tra.next;
        }
        if(tra==null)
            System.out.println("No Element Found");
        else
        {
            Node temp=new Node();
            temp.data=data;
            temp.next= tra.next;
            tra.next=temp;
            System.out.println("Node Insert Successfully");
        }
    }
    void deleteStarting()
    {
        if(head==null)
        {
            System.out.println("No Element Found");
            return;
        }
        tra=head;//here tra is use to hold the stating node
        head=head.next;
        tra=null;
        System.out.println("Node Delete Successfully");
    }
}
