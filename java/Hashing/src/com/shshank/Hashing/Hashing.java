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
            case 0->insertAtBeg(data,0);
            case 1->insertAtBeg(data,1);
            case 2->insertAtBeg(data,2);
            case 3->insertAtBeg(data,3);
            case 4->insertAtBeg(data,4);
            case 5->insertAtBeg(data,5);
            case 6->insertAtBeg(data,6);
            case 7->insertAtBeg(data,7);
            case 8->insertAtBeg(data,8);
            case 9->insertAtBeg(data,9);
        }
    }
   private void insertAtBeg(int data,int HeadNum)
    {
          flag=searchForInsert(data,head[HeadNum]);
        if (flag)
        {
            temp=new Node();
            temp.info=data;
            temp.next=head[HeadNum];
            head[HeadNum]=temp;
            System.out.println("Data Inserted");
        }
    }
  private  boolean searchForInsert(int data,Node head)
    {
        while (head!=null)
        {
            if(data==head.info)
            {
                return(false);
            }
            head=head.next;
        }
        return true;
    }
    boolean hashing(int data)
    {
        store=data%10;
        switch (store)
        {
            case 0->flag=hashSearch(data,head[0]);
            case 1->flag=hashSearch(data,head[1]);
            case 2->flag=hashSearch(data,head[2]);
            case 3->flag=hashSearch(data,head[3]);
            case 4->flag=hashSearch(data,head[4]);
            case 5->flag=hashSearch(data,head[5]);
            case 6->flag=hashSearch(data,head[6]);
            case 7->flag=hashSearch(data,head[7]);
            case 8->flag=hashSearch(data,head[8]);
            case 9->flag=hashSearch(data,head[9]);
        }
        return flag;
    }
    private boolean hashSearch(int data,Node head)
    {
        if(head==null)
        {
            return false;
        }
        if(head.info==data)
        {
            return true;
        }
            return(searchForHash(data,head));

    }
    private boolean searchForHash(int data,Node head)
    {

        while (head!=null)
        {
            if(head.info==data)
            {
                return true;
            }
            head=head.next;
        }
        return false;
    }
}

