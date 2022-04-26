package Hamming;

import java.util.Scanner;

public class Hamming {
    public static void main(String[] args) {
        int firstNumber, secondNumber, countHamming = 0;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a value of first number: ");
        firstNumber = input.nextInt();
        System.out.print("Enter a value of second number: ");
        secondNumber = input.nextInt();
        String firstNumberToBinary = toBinary(firstNumber);
        String secondNumberToBinary = toBinary(secondNumber);
        for(int i = 0; i < firstNumberToBinary.length(); i++){
            if(firstNumberToBinary.charAt(i) != secondNumberToBinary.charAt(i)){
                countHamming++;
            }
        }
        System.out.printf("First Number To Binary: %s \nSecond Number To Binary: %s \nHamming: %d", firstNumberToBinary,secondNumberToBinary,countHamming);
    }

    public static String toBinary(int value){
        int displayMask = 1 << 7;
        String bits = "";
        for (int i = 1; i <= 8; i++) {
            if ((value & displayMask) == 0) {
                bits += '0';
            } else {
                bits += '1';
            }
            value <<= 1;
        }
        return bits;
    }
}
