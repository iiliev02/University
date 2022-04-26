using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemThree
{
    public class TextBox : IUndoable
    {
        protected virtual void Undo()
        {
            Console.WriteLine($"{nameof(TextBox)}.Undo");
        }

        void IUndoable.Undo()
        {
            Undo();
        }
    }
}
