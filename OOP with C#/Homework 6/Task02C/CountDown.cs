using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemTwoC
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

        public int OriginalNumber => originalNumber;

        public CountDown(int number)
        {
            Number = number;
            originalNumber = this.number;
            this.number = 0;
        }

        public virtual bool MoveNext()
        {
            if (number - 1 < 0)
            {
                return false;
            }

            number--;
            return true;
        }

        public virtual object Current => number;

        public virtual void Reset()
        {
            number = originalNumber;
        }
    }
}
