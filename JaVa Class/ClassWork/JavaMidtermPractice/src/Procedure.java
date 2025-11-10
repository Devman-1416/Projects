public class Procedure {

    private String procedureName;
    private String practitionerName;
    private double price;

    Procedure (String proName, String pracName, double price)
    {
        this.practitionerName = pracName;
        this.procedureName = proName;
        this.price = price;
    }

    public String getProcedureName () {return this.procedureName;}
    public String getPractitionerName () {return this.practitionerName;}
    public double getPrice () {return this.price;}
}
