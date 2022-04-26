using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemThree
{
    public class RichTextBox : TextBox
    {
        protected override void Undo()
        {
            Console.WriteLine($"{nameof(RichTextBox)}.Undo");
        }
    }
}
