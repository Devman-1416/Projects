public class Violation {

    private double fee;
    private String description;
    private String violationType;


    Violation () {}
    Violation(String violationType) {this.violationType = violationType;}
    Violation(String violationType, String description)
    {
        this.violationType = violationType;
        this.description = description;
    }
    Violation(String violationType, String description, double fee)
    {
        this.violationType = violationType;
        this.description = description;
        this.fee = fee;
    }


    public String getDescription () {return this.description;}
    public String getViolation () {return this.violationType;}
    public double getFee () {return this.fee;}

    public void setDescription (String description) {this.description = description;}
    public void setViolation (String violationType) {this.violationType = violationType;}
    public void setFee (double fee) {this.fee = fee;}

    public String toString()
    {
        return "Description: " + description
                + "\nViolation Type: " + violationType
                + "\nFee: $" + fee;
    }


}
