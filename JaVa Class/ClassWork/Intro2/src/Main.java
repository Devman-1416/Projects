import java.text.DecimalFormat;
import java.util.Scanner;



public class Main {

    public static final DecimalFormat df = new DecimalFormat( "0.00");

    public static void main (String[] arg) {

//        System.out.println("Pretty Pleasant Practical Petunia");
//
        Scanner input = new Scanner(System.in);
//        System.out.println("Please Enter a Number");
//        int num = input.nextInt();
//
//        if (num > 10) {
//            System.out.println(num);
//            return;
//        } else
//            System.out.println("Number is double digits or more! ");
//
//        int birthYear, currentYear, age;

        //------------------------------- Age Fun ------------------------------------------
//
//        Scanner life = new Scanner(System.in);
//
//        System.out.println("\n\nEnter Your Birth Year");
//        birthYear = input.nextInt();
//
//        System.out.println("\n\nEnter Current Year");
//        currentYear = input.nextInt();
//
//        System.out.println("In the Year: " + currentYear + " you will be "
//        + (age = currentYear - birthYear));



        long myInt = 2_147_483_647L;
        System.out.println("My Int is: " + myInt);
        int x = (int) 5.9;
        System.out.println("x is " + x);

        String formattedValue = String.format("%,d",myInt);
        System.out.println(formattedValue);

        // Default is double, cast to float
        float myFloat = 1250.0f / 3.5f;
        System.out.println("myFloat is " + myFloat);

        double myDs = 1250.0 / 3.5;
        System.out.println("myDs is " + myDs);
        System.out.println("MyDs formatted using df " + df.format(myDs));

        String doubleFormate = String.format("%,.2f", myDs);
        System.out.println("MyDs formatted using string " + doubleFormate);

        int myVar = 0B10;
        System.out.println("MyVar: " + myVar);

        double answer = Math.pow(2,3);
        System.out.println("My answer is: " + answer);

        String greeting;
        greeting = "Hello Harry!";
        System.out.println(greeting);
        int stringSize = greeting.length();
        System.out.println("String Length: " + stringSize);

        //Enter Key Buffer Issue Fix
        inputObject.nextLine();


        char initial;
        String charInput;

        System.out.println("Please enter a character");
        initial = input.next().charAt(0);
        System.out.println(initial);

        String allInput;
        System.out.println("Enter a birth year... ");
        allInput = input.next();

        int birthYear = Integer.parseInt(allInput);
        System.out.println(birthYear + 10);



    } // end main()
} // end of the waking world
