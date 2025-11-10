import java.text.DecimalFormat;
import java.util.Scanner;



public class Main {

    public static final DecimalFormat df = new DecimalFormat( "0.00");

    public static void main (String[] arg) {

//    Indoor indoorPlant = new Indoor("Fern",14.99);
//    indoorPlant.setData();
//
//    System.out.println(indoorPlant);

//    Outdoor outdoorPlant = new Outdoor("Pine", 175.00);
//    outdoorPlant.setData();
//    System.out.println(outdoorPlant);

        Tree tree = new Tree("Oak", 250.00);
        tree.setData();
        System.out.println(tree);

    } // end main()
} // end of the waking world


