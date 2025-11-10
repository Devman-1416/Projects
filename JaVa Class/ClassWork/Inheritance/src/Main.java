import java.text.DecimalFormat;
import java.util.Scanner;



public class Main {

    public static final DecimalFormat df = new DecimalFormat( "0.00");

    public static void main (String[] arg) {

        Address address1 = new Address("CA", "90001", "Los Angeles", "123 Main St");
        Address address2 = new Address("NY", "10001", "New York", "456 Broadway");

        DeliveryItem food = new DeliveryItem(address1,address2,12,5);

        System.out.println(food);


    } // end main()
} // end of the waking world

