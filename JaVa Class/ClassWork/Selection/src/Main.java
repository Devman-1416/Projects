import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {

    public static final DecimalFormat df = new DecimalFormat( "0.00");

    public static void main (String[] arg) {

        int value;
        boolean isEven;

        Scanner input = new Scanner(System.in);
        value = input.nextInt();

        if (value % 2 == 0) {
            isEven = true;
        }
        else {
            isEven = false;
        }

        int number = (isEven) ? 1 : 0;
        System.out.println(number);

        int grade = 62;

        //if (90 <= grade <= 100)
        //    System.out.println("A");

        int bitNumber = 18 & 10;
        System.out.println("Bit Number: " + bitNumber);


        double total = 60.00 - 56.06;

        if (total == 3.94)
            System.out.println("They Equal" + total);
        else System.out.println("They dont equal bitch" + total);

        final double EPSILION = .005;

        if (Math.abs(total - 3.94) <= EPSILION)
            System.out.println("They Equal" + total);
        else System.out.println("They dont equal bitch" + total);

        System.out.println(Math.random() * 6 + 1);

        double var  = 3.14159265456;
        System.out.println("Double: " + var);
        System.out.println("Double: " + String.format("%.2f",var));
        System.out.println("Double: " + );
        df.setRoundingMode(RoundingMode.UP);




    } // end main func

} // end main class