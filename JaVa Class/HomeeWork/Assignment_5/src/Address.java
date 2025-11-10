public class Address {

    private  String name;
    private  String street;
    private String city;
    private String state;
    private String zip;

    Address ( String name, String street,
     String city, String state, String zip)
    {
        this.name = name;
        this.street = street;
        this. city = city;
        this.state = state;
        this.zip = zip;
    }

    public String toString() {
        return name + "\n" + street + "\n" + city + ", " + state + " " + zip;
    }



}
