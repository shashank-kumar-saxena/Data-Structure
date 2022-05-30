package StakUsingArray;

public class Queue {
        private Stack s1=new Stack();
        private boolean b;
        void enqueue(int data)
        {
            b=s1.push(data);
            if(b)
            {
                System.out.println("Element pushed");
            }
            else
            {
                System.out.println("StackOverflow");
            }
        }
        void dequeue()
        {
            Stack s2=new Stack();
            while (s1.tos!=-1)
            {
                s2.push(s1.arr[s1.tos]);
                b=s1.pop();
                if(!b)
                {
                    break;
                }
            }
            System.out.println("pop element"+s2.arr[s2.tos]);
            s2.pop();
            while (s2.tos!=-1)
            {
                s1.push(s2.arr[s2.tos]);
                b=s2.pop();
                if(!b)
                {
                    break;
                }
            }
        }
       public void traverse()
       {
           int count=s1.tos;
           while (count>-1)
           {
               System.out.print(s1.arr[count--]+" ");
           }
       }
    }
