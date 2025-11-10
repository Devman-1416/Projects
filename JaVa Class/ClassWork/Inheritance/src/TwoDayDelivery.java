public class TwoDayDelivery extends DeliveryItem {

    private double flatRate;

    public TwoDayDelivery (Address senderAddress, Address receiverAddress, double weight, double cost){
        super(senderAddress,receiverAddress,weight,cost); // must be first
        calculateShippingCost(flatRate);



    }



    @Override
    public void calculateShippingCost() {
        super.calculateShippingCost();
    }
}
