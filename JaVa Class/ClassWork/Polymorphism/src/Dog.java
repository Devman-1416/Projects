public class Dog extends Animal{

    private String name;

    Dog(String type, int age, String name)
    {
        super(type, age);
        this.name = name;
    }

    public void sound ()
    {
        System.out.println("Woof! Woof!");
    }
}
