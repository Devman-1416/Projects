public class OverNight extends DeliveryItem {

    private double additionalFee;

    OverNight(Address senderAddress, Address receiverAddress, double weight, double cost, double additionalFee)
    {
        super(senderAddress,receiverAddress,weight,cost + additionalFee); // must be first





    }

}
