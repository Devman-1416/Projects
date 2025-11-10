public class Pet
{
    private String name;
    private String petType;

    private int age;
    private double weight;

    // -------------------------------- Constructor ---------------------------------

    public Pet (String name)
    {
        this.name = name;
        this.petType = "";
        this.age = 0;
        this.weight = 0;
    }

    public Pet ()
    {

    }

    public Pet (String name, String petType, int age, double weight)
    {
        this.name = name;
        this.petType = petType;
        this.age = age;
        this.weight = weight;
    }


    // ------------------------------------ Methods ----------------------------------------

    public void setName (String name){
        this.name = name;
    }

    public void setAge (int age){
        this.age = age;
    }

    public void setPetType (String petType){
        this.petType = petType;
    }

    public void setWeight (double weight){
        this.weight = weight;
    }


    public String getName (){
        return this.name;
    }
    public String getPetType (){
        return this.petType;
    }
    public int getAge (){
        return this.age;
    }
    public double getWeight (){
        return this.weight;
    }

    // ------------------------------------ Utility ----------------------------------------

    void displayPet ()
    {
        System.out.println("Name: " +this.name);
        System.out.println("Type: " + this.petType);
        System.out.println("Age: " + this.age);
        System.out.println("Weight: " + this.weight);

    }

    public String toString() {
        return "Name" + name + "Pettype" + petType;
    }

} // end Pet
