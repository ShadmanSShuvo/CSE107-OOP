class MyClass
{
private
    int x;
    MyClass() { x = 0; }
    MyClass(int n) { x = n; }
public
    int getX() { return x; }
}

public class Main
{
public
    static void main(String[] args)
    {
        Array of Object
            MyClass[] ob = new MyClass[5];
        for (int i = 0; i < ob.length; ++i)
        {
            if (i % 2 != 0)
                ob[i] = new MyClass();
            else
                ob[i] = new MyClass(i + 1);
        }

        for (int i = 0; i < ob.length; ++i)
        {
            System.out.print(ob[i].getX() + " ");
        }
    }
}