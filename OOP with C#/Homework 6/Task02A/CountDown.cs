using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemTwoA
{
    public class CountDown : IEnumerator
    {
        private int number;
        private readonly int originalNumber;

        public int Number
        {
            get => number;
            set => number = value >= 0 ? value : 16;
        }

        public CountDown(int number)
        {
            Number = number;
            originalNumber = this.number;
        }

        public bool MoveNext()
        {
            if (number - 1 < 0)
            {
                return false;
            }

            number--;
            return true;
        }

        public object Current => number;

        public void Reset()
        {
            number = originalNumber;
        }
    }
}
