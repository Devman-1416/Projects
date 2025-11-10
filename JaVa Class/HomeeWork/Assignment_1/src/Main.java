import java.util.Scanner;

public class Main {
    public static void main (String[] arg) {

        // User Input for points
        Scanner userNum = new Scanner(System.in);

        System.out.println("Slope Calculator\n\nPoint One -\nx1: ");
        short x1 = userNum.nextShort();

        System.out.println("y1: ");
        short y1 = userNum.nextShort();

        System.out.println("\nPoint Two -\nx2: ");
        short x2 = userNum.nextShort();

        System.out.println("\ny2: ");
        short y2 = userNum.nextShort();

        // Calculate Slope

        float slope = (float) ( (y2 - y1) / (x2 - x1) );

        // Display Results

        System.out.println("The slope ofr the line that connects points ("
                +x1 + "," +y1 +") and ("
                +x2 + "," +y2 +") is " + slope);

    }
}