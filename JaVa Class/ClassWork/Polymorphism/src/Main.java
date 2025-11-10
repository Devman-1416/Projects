import javax.xml.crypto.dsig.spec.C14NMethodParameterSpec;
import java.text.DecimalFormat;

public class Main {

    public static final DecimalFormat df = new DecimalFormat( "0.00");

    public static void main (String[] arg) {

        Animal newA = new Animal("Dragon", 22);

        Dog newDogg = new Dog("border Collie", 2, "Jupiter");

        Cat newCat = new Cat("Killa", "Tabby", 4);


        makeSound(newA);
        makeSound(newCat);
        makeSound(newDogg);

    } // end main()


    public static void makeSound(Animal oneAni)
    {
        oneAni.sound();
    }
} // end of the waking world

