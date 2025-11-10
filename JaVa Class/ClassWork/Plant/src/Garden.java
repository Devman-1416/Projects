import java.util.Scanner;

public class Garden extends Outdoor{

    private int minHeight;
    private int maxHeight;


    Garden(String name, double price)
    {
        super(name, price);
    }

    public void setData()
    {

        super.setData();

        Scanner input = new Scanner(System.in);

        System.out.println("Enter Max Height in inches");
        maxHeight = input.nextInt();

        System.out.println("Enter Min Height in inches");
        minHeight = input.nextInt();
    }

    public String toString()
    {
        return super.toString() +" Max Height: " + maxHeight + "  Min Height: " + minHeight;
    }

}
