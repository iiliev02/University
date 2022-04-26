using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ProblemOne
{
    public class TestPolymorphismProtected
    {
        public static void Main(string[] args)
        {
            var textBoxes = new TextBox[] { new EditTextBox(), new RichTextBox(), new MultiLineTextBox() };
            
            foreach (var textBox in textBoxes)
            {
                // textBox.TypeText();
                // The method is inaccessible because of its protected level. 
            }
        }
    }
}
