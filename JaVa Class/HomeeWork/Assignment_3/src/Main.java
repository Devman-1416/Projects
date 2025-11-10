import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class Main {


    public static void main (String[] arg) {

        // Variables
        int numerator = 0, denominator = 0, wholeNumber = 0;
        boolean checkFraction = false;
        String fraction = "";
        Scanner input = new Scanner(System.in);

        // Get User Input, check if its correct formate of a fraction Ex: 1/2
        while (!checkFraction)
        {
            System.out.print("Please Enter Your Fraction: ");
            fraction = input.next().trim();

            // Split it Up

            System.out.println(fraction);
            System.out.println(fraction.charAt(1));

            // Check Slash
            if (fraction.contains("/"))
            {
                int index = fraction.indexOf('/');
                System.out.println(index);

                // Get Numerator and Denominator out of String
                numerator =  Integer.parseInt(fraction.substring(0,index));
                denominator = Integer.parseInt(fraction.substring(index + 1));
                //System.out.println("num: " + numerator + "\ndem: " + denominator);

                checkFraction = true;
            }
            else
            {
                System.out.println("\nNot a proper fraction, try again!");
            }
        } // End While

        // Check if Improper or Proper
        if (numerator > denominator) // Improper Fraction
        {
            wholeNumber = numerator / denominator;
            numerator %= denominator;

            if (numerator != 0) { // Mix Fraction

                String mixFraction = wholeNumber + " " + numerator + "/" + denominator;
                System.out.println("\nImproper Fraction: " + fraction + "  Mix Fraction: " + mixFraction);
            }
            else // Whole Number
            {
                System.out.println("\nImproper Fraction: " + fraction + "  Whole Number: " + wholeNumber);
            }//End If
        }
        else // Proper Fraction
        {
            System.out.println("\nProper Fraction: " + fraction);
        }// End If


    } // end main func

} // end main class

