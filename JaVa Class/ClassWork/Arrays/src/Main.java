import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Main {
    //static Scanner input = new Scanner (System.in); Global Version


    public static void main (String[] arg) {

        Scanner input = new Scanner (System.in);

        int [] myArray = new int[5];

        //loadArray(myArray, input);
        //printArray(myArray);


        //------------------------ 2 Dimension

//        int[][] scoreboard = new int [2][9];
//
//        for (int x = 0; x < scoreboard.length; x++) // row
//        {
//            for (int y = 0; y < scoreboard[0].length; y++) // col
//            {
//                scoreboard[x][y] = input.nextInt();
//
//            }
//        }// end for
//
//        for (int x = 0; x < scoreboard.length; x++) // Row
//        {
//            for (int y = 0; y < scoreboard[0].length; y++) // Col
//            {
//                System.out.print(" " + scoreboard[x][y]);
//            }
//            System.out.println();
//        }// end for


        ArrayList<String> fruits = new ArrayList<>(); // vector

        String inputFruit;

        System.out.println("Enter a fruit to add or type \"exit\" to stop");


        while (true)
        {
            inputFruit = input.nextLine();

            if (inputFruit.equalsIgnoreCase("exit"))
                break;

            fruits.add(inputFruit);
        }

        for (int x = 0; x < fruits.size(); x ++)
        {
            System.out.println(" " + fruits.get(x));
        }

        for ( String oneFruit : fruits)
            System.out.println(" " + oneFruit);

        System.out.println("Enter a fruit to remove: ");
        inputFruit = input.nextLine();

        if (fruits.remove(inputFruit))
            System.out.println(inputFruit + " Fruit Removed");
        else
            System.out.println(inputFruit + " not found");


    } // end main func

    public static void printArray(int[] myArray)
    {
        for (int x = 0; x < myArray.length; x++)
        {
            System.out.println("Number " + x + ":" +  myArray[x]);
        }
    } // end func

    public static void loadArray(int[] myArray, Scanner input)
    {
        System.out.println("Enter 5 Numbers Folly Friend");

        for (int x = 0; x < myArray.length; x++)
        {
            myArray[x] = input.nextInt();
        }
    } // end func

} // end main class

