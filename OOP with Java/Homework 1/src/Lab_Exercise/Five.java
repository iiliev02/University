package Lab_Exercise;

import java.util.Scanner;

public class Five {

    public static void main(String args[]) {
        int originalNumber;
        int number;
        String inputString;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        inputString = input.nextLine();
        if(inputString != null && inputString.length() == 5)
        {
            originalNumber = Integer.parseInt(inputString);

            int digit1;
            int digit2;
            int digit3;
            int digit4;
            int digit5;

            digit1 = originalNumber / 10000;
            number = originalNumber % 10000;
            digit2 = number / 1000;
            number %= 1000;
            digit3 = number / 100;
            number %= 100;
            digit4 = number / 10;
            number %= 10;
            digit5 = number;

            String resultString = digit1 + " " + digit2 + " " + digit3 + " " + digit4 + " " + digit5;
            System.out.printf("Result: %s", resultString);
        }
        else
        {
            System.out.println("The number must consist 5 digit...");
        }
    }
}
