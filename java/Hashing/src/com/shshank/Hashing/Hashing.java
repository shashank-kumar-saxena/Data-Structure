package com.shshank.Hashing;

public class Hashing {
    private Node head[]=new Node[10],temp;
   private int store;
   private boolean flag;
    void insert(int data)
    {
        store=data%10;
        switch (store)
        {
            case 0->insertAtBeg(data,head[0]);
            case 1->insertAtBeg(data,head[1]);
            case 2->insertAtBeg(data,head[2]);
            case 3->insertAtBeg(data,head[3]);
            case 4->insertAtBeg(data,head[4]);
            case 5->insertAtBeg(data,head[5]);
            case 6->insertAtBeg(data,head[6]);
            case 7->insertAtBeg(data,head[7]);
            case 8->insertAtBeg(data,head[8]);
            case 9->insertAtBeg(data,head[9]);
        }
    }
   private void insertAtBeg(int data,Node head)
    {
        if(head!=null)
        {
          flag=search(data,head);
        }
        if (flag)
        {
            temp=new Node();
            temp.info=data;
            temp.next=head;
            head=temp;
        }
        System.out.println("Data Inserted");
    }
  private  boolean search(int data,Node head)
    {
        while (head!=null)
        {
            if(data==head.info)
            {
                return(false);
            }
        }
        return true;
    }

}
