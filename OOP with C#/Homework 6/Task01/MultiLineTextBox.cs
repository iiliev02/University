using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemOne
{
    public class MultiLineTextBox : RichTextBox
    {
        protected new string text = $"{nameof(MultiLineTextBox)}: Type text";

        protected override void TypeText()
        {
            Console.WriteLine(text);
        }

        public override void EditTextAllowed()
        {
            base.TypeText();
            Console.WriteLine(base.text);
            Console.WriteLine(baseText);
        }

        public override void EditTextDisAllowed()
        {
            RichTextBox richTextBox = new MultiLineTextBox();

            // richTextBox.TypeText();
            // Because a derived class cannot access protected members of its base class through an instance of the base class.
            // The compiler cannot determine at compile time what the run-time type of textBox will be.

            // richTextBox.text = string.Empty;
            // Because protected members can be accessed only by derived types, any attempts to access protected members
            // that might not be valid at run time are marked by the compiler as not valid.

            // richTextBox.baseText = string.Empty;
            // Due to the aforementioned reason.
        }
    }
}
