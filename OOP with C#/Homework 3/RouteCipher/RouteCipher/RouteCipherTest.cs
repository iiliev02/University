using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RouteCipher
{
    public class RouteCipherTest
    {
        public static void Main(string[] args)
        {
            RouteCipher routeCipherOne = new RouteCipher(-5);
            Console.WriteLine(routeCipherOne.Encrypt("abort the mission, you have been spotted"));
            Console.WriteLine(routeCipherOne.Decrypt("&teanitrobatsyvnted&oehomehsoespbui"));
            Console.WriteLine(routeCipherOne.ToString());

            Console.WriteLine();

            RouteCipher routeCipherTwo = new RouteCipher(4);
            Console.WriteLine(routeCipherTwo.Decrypt("TIEIXT&&EAHSIHSPNTLT"));
            Console.WriteLine(routeCipherTwo.Encrypt("THISISTHEPLAINTEXT"));
            Console.WriteLine(routeCipherTwo.ToString());

            Console.WriteLine();

            RouteCipher routeCipherThree = new RouteCipher(2);
            Console.WriteLine(routeCipherThree.Encrypt("Date: 01.11.2021"));
            Console.WriteLine(routeCipherThree.Decrypt("Dt01221011ea"));
            Console.WriteLine(routeCipherThree.ToString());
        }
    }
}
