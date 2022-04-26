using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkOne
{
    public class TableTest
    {
        private const string INCORRECT_VALUE = "You have entered an incorrect value!";

        public static double ReadDouble(string requiredNumberText)
        {
            double result;

            Console.Write(requiredNumberText);
            while (true)
            {
                if (double.TryParse(Console.ReadLine(), out result))
                {
                    break;
                }

                Console.WriteLine(INCORRECT_VALUE);
                Console.Write(requiredNumberText);
            }

            return result;
        }

        public static int ReadInt(string requiredNumberText)
        {
            Console.Write(requiredNumberText);
            while (true)
            {
                try
                {
                    return int.Parse(Console.ReadLine());
                }
                catch (Exception e)
                {
                    Console.WriteLine(INCORRECT_VALUE);
                    Console.Write(requiredNumberText);
                }
            }
        }

        public static void Main(string[] args)
        {
            double initialValue = ReadDouble("Enter initial value: ");
            double finalValue = ReadDouble("Enter final value: ");
            int discretizationSteps = ReadInt("Enter discretization steps: ");

            if (initialValue > finalValue)
            {
                double copyInitialValue = initialValue;
                initialValue = finalValue;
                finalValue = copyInitialValue;
            }

            Table table = new Table(initialValue, finalValue, discretizationSteps);
            table.MakeTable();
        }
    }
}
