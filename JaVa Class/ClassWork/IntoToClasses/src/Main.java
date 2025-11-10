import java.text.DecimalFormat;
import java.util.Scanner;



public class Main {

    public static final DecimalFormat df = new DecimalFormat( "0.00");

    public static void main (String[] arg) {

        Pet doggy = new Pet(); // Instantiate / Create / Declare a Object

        doggy.setAge(12);
        doggy.setName("Dog");
        doggy.setPetType("Canine");
        doggy.setWeight(120);

        Pet kitty = new  Pet("Church Hill");

    } // end main()
} // end of the waking world
