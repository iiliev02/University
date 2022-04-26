using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkOne
{
    public class Table
    {
        #region Fields
        private double initialValue;
        private double finalValue;
        private int discretizationSteps;
        #endregion

        #region Properties
        public double InitialValue
        {
            get { return initialValue; }
            set { initialValue = value; }
        }

        public double FinalValue
        {
            get { return finalValue; }
            set { finalValue = value; }
        }

        public int DiscretizationSteps
        {
            get { return discretizationSteps; }
            set { discretizationSteps = value; }
        }
        #endregion

        #region Constructors
        public Table(double initialValue, 
                     double finalValue,
                     int discretizationSteps)
        {
            InitialValue = initialValue;
            FinalValue = finalValue;
            DiscretizationSteps = discretizationSteps;
        }
        #endregion

        #region Methods
        public void MakeTable()
        {
            int counter = 0;
            string input = string.Empty;
            double step = (finalValue - initialValue) / discretizationSteps;

            for (double x = initialValue; x <= finalValue; x+=step)
            {
                Console.WriteLine($"{x:F2}\t\t{Math.Pow(Math.Abs(x - 2), 2)/(Math.Pow(x, 2) + 1):F4}");
                counter++;

                if (counter % 20 == 0 && x + step <= finalValue)
                {
                    while (input != "Return" && input != "return")
                    {
                        Console.WriteLine("Press return to continue...");
                        Console.Write("Waiting for a response: ");
                        input = Console.ReadLine();
                    }

                    input = string.Empty;
                }
            }
        }
        #endregion
    }
}
