public class Student {

    private String name;
    private double gpa;

    Student () {}
    Student(String name) {this.name = name;}
    Student(String name, double gpa)
    {
        this.name = name;
        this.gpa = gpa;
    }

    public String getName () {return this.name;}
    public double getGpa () {return this.gpa;}

    public void setName (String name) {this.name = name;}
    public void setGpa (double gpa) {this.gpa = gpa;}

    public String toString()
    {
        return "Name: " + name + "  GPA: " + gpa;
    }

    public boolean isHonorRoll()
    {
        return gpa <= 3.7;
    }

}
