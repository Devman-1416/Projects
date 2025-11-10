import java.util.ArrayList;
import java.util.List;

public class Invoice {

    private Address address;
    private List<LineItem> allItems;

    Invoice ( Address address)
    {
        this.address = address;
        this.allItems = new ArrayList<LineItem>();
    }

    public void add(Product product, int quantity)
    {
        allItems.add(new LineItem(quantity, product));

    }

    public double calculateTotal()
    {
        double total = 0.0;

        for (LineItem item: allItems)
        {
            total += item.calculateSubTotal();
        }
        return total;
    }

    public void printInvoice() {

        System.out.println("---- Invoice ----");
        System.out.println(address);
        System.out.println("\nItems:");

        for (LineItem item : allItems) {
            System.out.println("  " + item);
        }// end for

        System.out.println("\nTotal Due: $" + String.format("%.2f", calculateTotal()));
    }

}
