public class LineItem {

    private int quantity;
    private Product product;

    LineItem (int quantity, Product product)
    {
        this.quantity = quantity;
        this.product = product;
    }


    public double calculateSubTotal ()
    {
        return this.quantity * product.getPrice();
    }

    public String toString() {
        return quantity + " x " + product +
                " = $" + String.format("%.2f", calculateSubTotal());
    }

}
