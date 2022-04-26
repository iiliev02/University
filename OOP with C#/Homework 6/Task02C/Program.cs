using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemTwoC
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var countDownWithOverride = new CountDownWithOverride(16);

            Console.Write(countDownWithOverride.Current);
            while (countDownWithOverride.MoveNext())
            {
                Console.Write(countDownWithOverride.Current);
            }

            Console.WriteLine();
        }
    }
}
