public class Person {
    private String firstName;
    private char middleInital;
    private String lastName;
    private String phoneNumber;
    private Address address;

    Person (String fn, char mi, String ln, String pn, String street, String city, String state, String zipCode)
    {
        this.firstName = fn;
        this.lastName = ln;
        this.middleInital = mi;
        this.phoneNumber = pn;
        this.address = new Address(street,city,state,zipCode);
    }

    public String getPhoneNumber () {return phoneNumber;}
    public String getFullName ()
    {
        return firstName + " " + middleInital + " " + lastName;
    }

    public String toString()
    {
        return address.toString();
    }

}
