import java.util.Scanner;

public class Tree extends Outdoor{

    private int minHeight;
    private int maxHeight;


    Tree(String name, double price)
    {
        super(name, price);
    }

    public void setData()
    {

        super.setData();

        Scanner input = new Scanner(System.in);

        System.out.println("Enter Max Height in Feet");
        maxHeight = input.nextInt();

        System.out.println("Enter Min Height in Feet");
        minHeight = input.nextInt();
    }

    public String toString()
    {
        return super.toString() +" Max Height: " + maxHeight + "  Min Height: " + minHeight;
    }
}
