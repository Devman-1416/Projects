import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class Main {


    public static void main (String[] arg) {

        Scanner input = new Scanner (System.in);
        char[] specialCharacters = {'!','@','#','%','^','&','*','?'};
        boolean passwordValid;
        String password;


        System.out.println("Password Rules:\n*The password must be at least 8 characters long" +
                "\n*It must include at least one uppercase letter, one lowercase letter, one number, " +
                "\n\tand one special character (for example: ! @ # $ % ^ & * ?) ");

        do{

            boolean hasUpper = false, hasLower = false,
                    hasSpecialChar = false, hasNumber = false;

            passwordValid = true;


            System.out.printf("\n\nEnter Password:  ");
            password = input.nextLine().trim();

            //--------------------------Check Length
            if (password.length() < 8)
            {
                System.out.println("Must be more than 8 Characters");
                passwordValid = false;
            }

            // -----------------------Check if Has an Upper Case
            for (int i = 0; i < password.length(); i++ )
            {
                hasUpper = Character.isUpperCase(password.charAt(i));
                if (hasUpper) break;
            }
            if (!hasUpper)
            {
                System.out.println("Password must include a Upper Case!");
                passwordValid = false;
            }

            // ------------------------Check if Has an Lower Case
            for (int i = 0; i < password.length(); i++ )
            {
                hasLower = Character.isLowerCase(password.charAt(i));
                if (hasLower) break;
            }
            if (!hasLower) {
                System.out.println("Password must include a Lower Case!");
                passwordValid = false;
            }

            //-------------------Check for Special Character
            for (int x = 0; x < password.length(); x++ )
            {
                for (char specialCharacter : specialCharacters) // The IDE Suggestion
                {
                    if (password.charAt(x) == specialCharacter)
                    {
                        hasSpecialChar = true;
                        break;
                    }// end if
                }// end for
                if (hasSpecialChar) break;
            }// end for

            if (!hasSpecialChar) {
                System.out.println("Password must have a" +
                        "one of the following Special Characters:" +
                        "\n! @ # $ % ^ & * ?");
                passwordValid = false;
            }

            // -------------------------Check for number
            for (int i = 0; i < password.length(); i++ )
            {
                hasNumber = Character.isDigit(password.charAt(i));
                if (hasNumber) break;
            }// end for

            if (!hasNumber)
            {
                System.out.println("Password must include Number!");
                passwordValid = false;
            }

            if (passwordValid)
            {
                while (true)
                {
                    System.out.println("Please Confirm Password: ");
                    String retypePassword = input.nextLine().trim();

                    if (!password.equals(retypePassword)) {
                        System.out.println("Passwords Don't Match");
                    }
                    else break;
                }// end while

            }// end if

        }while (!passwordValid);

        System.out.println("Password successfully created!: " + password);

    } // end main func

} // end main class