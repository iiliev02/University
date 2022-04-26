package Task03;

import java.text.NumberFormat;
import java.util.Random;

public class Frequency {
    public static void main(String[] args) {
        double frequency1 = 0.0, frequency2 = 0.0, frequency3 = 0.0;
        loop10000(frequency1,frequency2,frequency3);
        loop60000(frequency1,frequency2,frequency3);
    }
    public static int drawRandomNumber(){
        Random random = new Random();
        int number = random.nextInt(10) + 1;
        if(number <= 2){
            return 1;
        }
        else if(number <= 5){
            return 2;
        }
        else {
            return 3;
        }
    }
    public static void loop10000(double frequency1, double frequency2, double frequency3){
        for(int i = 0; i <= 10000; i++)
        {
            int number = drawRandomNumber();
            if(number == 1)
            {
                frequency1++;
            }
            else if(number == 2)
            {
                frequency2++;
            }
            else
            {
                frequency3++;
            }
        }
        NumberFormat fmtPercent = NumberFormat.getPercentInstance();
        System.out.println("When you generate 10,000 random numbers...");
        System.out.println("Frequency 1: " + fmtPercent.format(frequency1 / 10000));
        System.out.println("Frequency 2: " + fmtPercent.format(frequency2 / 10000));
        System.out.println("Frequency 3: " + fmtPercent.format(frequency3 / 10000));
    }
    public static void loop60000(double frequency1, double frequency2, double frequency3){
        for(int i = 0; i <= 60000; i++)
        {
            int number = drawRandomNumber();
            if(number == 1)
            {
                frequency1++;
            }
            else if(number == 2)
            {
                frequency2++;
            }
            else
            {
                frequency3++;
            }
        }
        NumberFormat fmtPercent = NumberFormat.getPercentInstance();
        System.out.println("When you generate 60,000 random numbers...");
        System.out.println("Frequency 1: " + fmtPercent.format(frequency1 / 60000));
        System.out.println("Frequency 2: " + fmtPercent.format(frequency2 / 60000));
        System.out.println("Frequency 3: " + fmtPercent.format(frequency3 / 60000));
    }
}
