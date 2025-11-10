import java.util.Scanner;

public class Outdoor extends Plant{

    private int minHard;
    private int maxHard;

    Outdoor(String name, double price)
    {
        super(name, price);
    }

    public void setData()
    {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter Max Hardness Zone");
        maxHard = input.nextInt();

        System.out.println("Enter Min Hardness Zone");
        minHard = input.nextInt();
    }

    public String toString()
    {
        return super.toString() + " Zones: " + minHard + " - " + maxHard;
    }

}
