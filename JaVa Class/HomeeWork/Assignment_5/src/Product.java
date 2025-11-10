public class Product {

    private String description;
    private double price;

    Product (String desc, double price)
    {
        this.description = desc;
        this.price = price;
    }

    public double getPrice() {return this.price;}

    public String toString() {
        return description + " ($" + String.format("%.2f", price) + ")";
    }

}
