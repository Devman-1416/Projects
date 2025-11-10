public class Address {

    private String street = null;
    private String city = null;
    private String state = "";
    private String zipCode = "";

    Address (String street, String city, String state, String zipCode)
    {
        this.street = street;
        this.city = city;
        this.state = state;
        this.zipCode = zipCode;
    }

    public String toString()
    {
        return "Address: " + street + "\n" + city + ", "
            + state + ", " + zipCode;
    }

}
