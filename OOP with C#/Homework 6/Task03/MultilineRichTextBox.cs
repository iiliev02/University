using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemThree
{
    public class MultilineRichTextBox : RichTextBox
    {
        protected override void Undo()
        {
            Console.WriteLine($"{nameof(MultilineRichTextBox)}.Undo");
        }

        public void PolyTest()
        {
            RichTextBox richTextBox = new RichTextBox();
            MultilineRichTextBox multilineRichTextBox = new MultilineRichTextBox();

            var iUndoableTextBoxes = new[] { richTextBox, multilineRichTextBox };
            foreach (var textBox in iUndoableTextBoxes)
            {
                ((IUndoable)textBox).Undo();
            }

            // A derived class cannot access protected members of its base class through an instance of the base class.
            // An instance of the base class declared in the derived class might, at run time, be an instance of another type
            // that is derived from the same base but is not otherwise related to the derived class.
        }
    }
}
