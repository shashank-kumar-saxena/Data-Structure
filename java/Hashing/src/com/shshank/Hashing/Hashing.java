package com.shshank.Hashing;

public class Hashing {
    Node head[]=new Node[10];
    int store;
    void search(int data)
    {
        store=data%10;
        switch (store)
        {
            case 0->insert(data,head[0]);
            case 1->insert(data,head[1]);
            case 2->insert(data,head[2]);
            case 3->insert(data,head[3]);
            case 4->insert(data,head[4]);
            case 5->insert(data,head[5]);
            case 6->insert(data,head[6]);
            case 7->insert(data,head[7]);
            case 8->insert(data,head[8]);
            case 9->insert(data,head[9]);
        }
    }
    void insert(int data,Node head)
    {
        
    }
}
