using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemTwoD
{
    public class Program
    {
        public static void Main(string[] args)
        {
            IEnumerator countDown = new CountDown(16);

            Console.Write(countDown.Current);
            while (countDown.MoveNext())
            {
                Console.Write(countDown.Current);
            }

            Console.WriteLine();
        }
    }
}
