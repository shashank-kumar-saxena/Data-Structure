package com.shshnk.stack;

public class StackClass {
    public int a[]=new int[10];
    public int tos;

    public StackClass() {
        this.tos = -1;
    }

    public int getTos() {
        return tos;
    }

    boolean isFull()
    {
        if(tos==9) {
            return true;
        }
        return false;
    }
    public void push(int data)
    {
        if (isFull())
        {
            System.out.println("Stack Overflow");
            return;
        }
        else {
            tos++;
            a[tos] = data;
        }
    }
    boolean isEmpty()
    {
        if(tos==-1) {
            return true;
        }
        return false;
    }
    public int pop()
    {
        int data=-1;
        if(isEmpty())
        {
            System.out.println("Stack Underflow");
            return -1;
        }
        else
        {
            data=a[tos];
            tos--;
        }
        return data;
    }
}
