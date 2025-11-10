public class Address {
    private String state;
    private String zip;
    private String city;
    private String street;

    // Non-default constructor
    public Address(String state, String zip, String city, String street) {
        this.state = state;
        this.zip = zip;
        this.city = city;
        this.street = street;
    }

    // toString() method
    @Override
    public String toString() {
        return "Address{" +
                "state='" + state + '\'' +
                ", zip='" + zip + '\'' +
                ", city='" + city + '\'' +
                ", street='" + street + '\'' +
                '}';
    }
}
