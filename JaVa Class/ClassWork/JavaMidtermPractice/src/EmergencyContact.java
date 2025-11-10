public class EmergencyContact extends Person{

    private String relationship;

    EmergencyContact (String relationship, String fn, char mi, String ln, String pn, String street, String city, String state, String zipCode)
    {
        super(fn,mi,ln,pn,street,city,state,zipCode);
        this.relationship = relationship;

    }

    public String toString()
    {
        return "\nEmergency Contact: " + 
    }

}
