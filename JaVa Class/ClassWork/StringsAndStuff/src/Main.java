import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class Main {


    public static void main (String[] arg) {

//        String greeting = "  Hello  ";
//
//        System.out.println(greeting);
//        System.out.println(greeting.length());
//        System.out.println(greeting.charAt(5)); // String is array of chars
//        System.out.println(greeting.concat( " World!"));
//        System.out.println(greeting.toLowerCase());
//        System.out.println(greeting.toUpperCase());
//        System.out.println(greeting.trim());
//
        Scanner input = new Scanner(System.in);
//        System.out.print("Enter your name: ");
//        String name = input.next();
//        System.out.println(name);
//
//        //clear buffer
//        input.nextLine();
//
//        System.out.print("Next Line Enter your name: ");
//        name = input.nextLine();
//        System.out.println(name);
//
//        System.out.println("Enter first Initial: ");
//        char initial = input.next().trim().charAt(0); // reads the space untill first char, and then spots when hits next space after
//        System.out.println(initial);

        // --------------------------- Time to get spunky ---------------------------------

        String one = "one", two = "one";
        String word;

        if (one == two)
            System.out.println("They Equal");
        else
            System.out.println("Not Equal");

        System.out.println("Enter \"one\"   ");
        word = input.next();

        if (one.equalsIgnoreCase(word)) // How compare Strings
            System.out.println("They Equal");
        else
            System.out.println("Not Equal");

        if (one.compareTo(word) == 0)
            System.out.println("They Equal");
        else if (one.compareTo(word) > 0)
            System.out.println("Word would come first...");
        else if (one.compareTo(word) < 0)
            System.out.println("One would come first...");


        String s1 = "Pre vs. Post Okay!", s2 = "vs.";

        System.out.println(s1.startsWith("Pre")); // True
        System.out.println(s1.endsWith("Post")); // False
        System.out.println(s1.contains("vs.")); // True
        System.out.println(s1.contains(s2)); // True

        System.out.println(s1.substring(0,5)); // Exclusive
        System.out.println(s1.indexOf(word)); //  Find the index Number of entered Character in String

        // -------------------------------------------- Bluebird ---------------------------

        String stringV;
        int intV;

        System.out.println("Enter A Numerical Value: ");
        stringV = input.next();
        intV = Integer.parseInt(stringV);
        System.out.println(intV);

        String s = 12345 + "";

        System.out.printf("\n %.2f", 123.4567);
        System.out.printf("\n %10.2f", 123.4567);
        System.out.printf("\n %-10.2f", 123.4567);
        System.out.printf("\n %,.2f", 9999999999999.4567);
        System.out.printf("\n %010.2f", 123.4567);





    } // end main func

} // end main class
