public class Customer {

    private String name;
    private Address address;
    private Date dateOfBirth;

    public Customer(String name,
                    String street, String city, String state, String zipCode, // address
                    int month, int day, int year) // date
    {
        this.name = name;
        this.address = new Address(street,city,state,zipCode);
        this.dateOfBirth = new Date(month, day, year);
    }

    public Customer (String name, Address address, Date datOfBirth)
    {
        this.name = name;
        this.address = address;
        this.dateOfBirth = datOfBirth;
    }


    public String toString() {
        return "Customer{" +
                "name='" + name + '\'' +
                ", address=" + address.toString() +
                ", dateOfBirth=" + dateOfBirth.toString() +
                '}';
    }
}
