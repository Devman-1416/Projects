public class DeliveryItem {
    private double weight;
    private double cost;
    private double totalShippingCost;
    private Address senderAddress;
    private Address receiverAddress;

    DeliveryItem (Address senderAddress, Address receiverAddress, double weight, double cost)
    {
        this.senderAddress = senderAddress;
        this.receiverAddress = receiverAddress;
        this.weight = weight;
        this.cost = cost;
        calculateShippingCost();

    }

    public void calculateShippingCost()
    {
        totalShippingCost = weight * cost;
    }

    public void calculateShippingCost(double flatRate) {
    }



    public String toString()
    {
        return "Sender:" + senderAddress + "\n Reciever: " + receiverAddress +
                "\nWeight:" + weight + "  Cost:" + cost;
    }

}
