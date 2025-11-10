public class Cat extends Animal{
    private String name;
    private String breed;

    Cat(String name,String breed, int age)
    {
        super("Cat",age);
        this.name = name;
        this.breed = breed;
    }

    public void sound()
    {
        System.out.println("MEOW FUCKERS!");
    }
}
