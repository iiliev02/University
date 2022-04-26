using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemTwo
{
    public class Program
    {
        private static void CalculateCos(double accuracy)
        {
            double x = 1.5;
            double term = 1;
            double sum = 1;

            int counter = 0;
            while (Math.Abs(term) > accuracy)
            {
                counter += 2;

                term = -term * x * x / (counter * (counter - 1));
                sum += term;
            }

            double valueCosX = Math.Cos(x);
            Console.WriteLine($"Cos({x}) = {valueCosX} ({valueCosX:F4})");
            Console.WriteLine($"Approximate Cos({x}) = {sum} ({sum:F4})");
        }

        public static void Main(string[] args)
        {
            double accuracy;
            Console.Write("Accuracy: ");

            if (double.TryParse(Console.ReadLine(), out accuracy))
            {
                if (accuracy > 0 && accuracy < 1)
                {
                    CalculateCos(accuracy);
                }
                else
                {
                    Console.WriteLine("Accuracy must be between 0 and 1!");
                }
            }
            else
            {
                Console.WriteLine("Wrong input!");
            }
        }
    }
}
