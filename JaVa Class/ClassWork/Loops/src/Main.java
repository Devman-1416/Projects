import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class Main {


    public static void main (String[] arg) {

        Scanner input = new Scanner (System.in);
        int num, total;

        System.out.println("Enter Positive Number to add or -1 to stop: ");

        while (true) {
            System.out.println("Enter a number: ");
            num = input.nextInt();
            if (num == -1) break;
            else if (num % 2 != 0) {
                System.out.println("Odd numbers are not added!");
                continue; // skip rest of the loop
            }
        }
        num = 0;
        total =0;

        while ( num == -1)
        {
            System.out.println("Enter a number: ");
            num = input.nextInt();
            if(num == -1)   break;
            else if (num % 2 != 0) {
                System.out.println("Odd numbers are not added!");
                continue; // skip rest of the loop
            }

        }


        //-------------------------------------------------------------------------------

        int count = 0;

        do {
            System.out.println("Count is:   " + count);
            count ++;
        } while (count < 5);

        //-------------------------------------------------------------------------------

        for (int x = 0; x < count; x++)
            System.out.println("   " + x);


        //--------------------------------------Functions-----------------------------------------

        System.out.println("The sum is: " + sum(10,5));
        System.out.println("The sum is: " + sum(10,5,2));

    } // end main func

    // all  // Static mean no object is needed
    public static int sum(int a, int b)
    {
        return a + b;
    }

    public static int sum(int a, int b, int c)
    {
        return a + b + c;
    }

} // end main class

