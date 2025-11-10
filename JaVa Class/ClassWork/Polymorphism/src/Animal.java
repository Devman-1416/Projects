public class Animal {

    private String type;
    private int age;

    Animal (String type, int age)
    {

        this.type = type;
        this.age = age;

    }

    public void sound()
    {
        System.out.println(type + " makes a sound");
    }

}
