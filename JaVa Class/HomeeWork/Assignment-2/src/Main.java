import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {

    public static void main(String[] arg) {

        Scanner input = new Scanner(System.in);

        System.out.println("Please Enter a Seven Digit Number");

        int number = input.nextInt();
        int mod = 10;
        int reverse = 0;

        //System.out.println(number % 100);

        for (int i = 3; i < 10; i++) {
            // Get The Digit in the ones place going up
            int temp = (number % mod) / (mod / 10);

            //System.out.println("Before: : " + number % mod);

            // Get the tens digits (like 100, 1000) to be used to properly place the temp digit
            // in reverse
            int tens = Math.powExact(10,9 - i);

            reverse += temp * tens;
            mod *= 10;

            //System.out.println(i + ": " + reverse + "  Temp: " + temp);
            //System.out.println("Mod " + i + ": " + mod);
        }

        System.out.println("\nReverse:" + reverse);

    }
}