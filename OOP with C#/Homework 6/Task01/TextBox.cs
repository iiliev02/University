using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemOne
{
    public abstract class TextBox
    {
        protected string baseText = $"{nameof(TextBox)}: Type baseText";
        protected string text = $"{nameof(TextBox)}: Type text";

        protected virtual void TypeText()
        {
            Console.WriteLine(text);
        }

        public abstract void EditTextAllowed();

        public abstract void EditTextDisAllowed();
    }
}
