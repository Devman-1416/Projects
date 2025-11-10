import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Main {



    public static void main (String[] arg) {

        Address innAddress = new Address(
                "The Green Dragon Inn",
                "1 Bywater Road",
                "Hobbiton",
                "The Shire",
                "00001"
        );

        Invoice innInvoice = new Invoice(innAddress);
        Scanner input = new Scanner(System.in);

        System.out.println("Welcome to the Green Dragon Inn");

        while (true) {
            System.out.print("Enter product description (or 'exit' to quit): ");
            String desc = input.nextLine();

            if (desc.equalsIgnoreCase("exit")) {
                break;
            }

            System.out.print("Enter price: ");
            double price = input.nextDouble();

            System.out.print("Enter quantity: ");
            int quantity = input.nextInt();
            input.nextLine();

            Product newProduct = new Product(desc, price);
            innInvoice.add(newProduct, quantity);
        }

        innInvoice.printInvoice();

    } // end func

} // end main class

