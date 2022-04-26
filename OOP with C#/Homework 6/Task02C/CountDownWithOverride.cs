using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemTwoC
{
    public class CountDownWithOverride : CountDown
    {
        public CountDownWithOverride(int number) : base(number) { }

        public override bool MoveNext()
        {
            if (Number + 1 > OriginalNumber)
            {
                return false;
            }

            Number++;
            return true;
        }

        public override object Current => Number;

        public override void Reset()
        {
            Number = 0;
        }
    }
}
