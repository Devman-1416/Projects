import java.util.Scanner;

public class Indoor extends Plant{
    private String sunlight;
    private int daysToWater;


    Indoor(String name, double price)
    {
        super(name,price);
    }

    public void setData()
    {
        Scanner input = new Scanner(System.in);
        int choice=0;
        System.out.println("Enter Sunlight:\n\t1 = Direct\n\t2 = Partial\n\t3 = None");

        while (true) {

            choice = input.nextInt();

            if (choice == 1) {
                sunlight = "direct";
                break;
            } else if (choice == 2) {
                sunlight = "partial";
                break;
            } else if (choice == 3) {
                sunlight = "none";
                break;
            } else System.out.println("Invalid Input Try again");
        }

        System.out.println("\nEnter Water days");
        daysToWater = input.nextInt();


    }// end func

    public  String toString()
    {
        return super.toString() + "sunlight " + sunlight +
                "water " + daysToWater + "day(s) per week";
    }

}
