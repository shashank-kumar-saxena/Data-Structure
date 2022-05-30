package StakUsingArray;

public class Stack {
    int arr[]=new int[10];
    int tos=-1;

    public boolean push(int data)
    {
        if(tos>=10)
        {
            return false;
        }
        tos++;
        arr[tos]=data;
        return true;
    }
    public boolean pop()
    {
        if(tos==-1)
        {
            return false;
        }
        tos--;
        return true;
    }
}
