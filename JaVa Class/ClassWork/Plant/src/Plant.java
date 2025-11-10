public class Plant {
    private String name;
    private double price;

    Plant(String name, double price)
    {
        this.name = name;
        this.price = price;
    }

    public String toString()
    {
        return "\nName: "+name+"\nPrice: $" + price;
    }

    public String getName() {return name;}
    public double getPrice() {return price;}

}
