import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Main {



    public static void main (String[] arg) {

        ArrayList<String>  fruits = new ArrayList <>();
        ArrayList<Integer>  numbers = new ArrayList <Integer>(); // wrapper classes

        // Double    --> double
        // Character --> char
        // Boolean   --> boolean

        numbers.add(100); // Autoboxing
        numbers.add(50);

        for (int i = 0; i < numbers.size(); i++) {
            System.out.print(numbers.get(i) + " ");
        }

        System.out.println();

        for (int number : numbers)
        {
            System.out.print(number + " ");
        }

        double price = 56.06, amount = 60.00;
        double total = amount - price;
        System.out.println(total);

        String stringPrice = String.valueOf(price); // Convert to string
        String stringAmount = String.valueOf(amount); // Convert to string

        BigDecimal price2 = new BigDecimal(stringPrice); // stored as a string, only send as string
        BigDecimal amount2 = new BigDecimal(stringAmount);
        BigDecimal total2 = new BigDecimal(total);

        total2 = amount2.subtract(price2);

        System.out.println(total2);


    } // end func

} // end main class

