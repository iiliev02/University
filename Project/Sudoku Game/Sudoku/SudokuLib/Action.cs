using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SudokuLib
{
    class Action
    {
        public int OldSymbol { get; set; }
        public int NewSymbol { get; set; }
        public int X { get; set; }
        public int Y { get; set; }

        public Action(int oldSymbol, int newSymbol, int x, int y)
        {
            OldSymbol = oldSymbol;
            NewSymbol = newSymbol;
            X = x;
            Y = y;
        }
    }
}
