using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;


namespace SudokuLib
{
    class SudokuPuzzle
    {
		private static Random rnd = new Random();
		//Checks if the solution is empty
		public static bool EmptySudokuSolution(ref int[,] puzzle)
        {
			bool isEmpty = true;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
					if(puzzle[i, j] != 0)
                    {
						isEmpty = false;
						break;
                    }
                }
            }
			return isEmpty;
        }
		//Checks if the processing game is complete
		public static bool SudokuComplete(ref int[,] puzzleProgrecing, ref int[,] puzzleComplete)
        {
			bool isComplete = true;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (puzzleProgrecing[i, j] != puzzleComplete[i, j])
					{
						isComplete = false;
						break;
					}
				}
			}

			return isComplete;
		}
		//Checks if the number is already exist in random generate matrix
		private static bool IsAlreadyHasNumber(int[,] puzzle, int row, int col, int num)
        {
			for (int i = row; i < row + 3; i++)
			{
				for (int j = col; j < col + 3; j++)
				{
					if (puzzle[i, j] == num) return false;
				}
			}
			return true;
		}
		//Generate the 3-th submatrix of main diagonal for generate random sudoku puzzle and its solution
		public static void GeneredMainDiagonal(ref int[,] puzzle)
        {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					int number = rnd.Next(9) + 1;
					while (!IsAlreadyHasNumber(puzzle, 0, 0, number))
					{
						number = rnd.Next(9) + 1;
					}
					puzzle[i, j] = number;
				}
			}
			for (int i = 3; i < 6; i++)
            {
				for(int j = 3; j < 6; j++)
                {
					int number = rnd.Next(9) + 1;
					while(!IsAlreadyHasNumber(puzzle, 3, 3, number))
                    {
						number = rnd.Next(9) + 1;
					}
					puzzle[i, j] = number;
                }
            }
			for (int i = 6; i < 9; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					int number = rnd.Next(9) + 1;
					while (!IsAlreadyHasNumber(puzzle, 6, 6, number))
					{
						number = rnd.Next(9) + 1;
					}
					puzzle[i, j] = number;
				}
			}
		}
		//Cenerate the random sudoku puzzle
		public static void randomPuzzle(ref int[,] completedPuzzle, ref int[,] initialPuzzle, ref int[,] processingPuzzle, int countCells)
        {
            for (int i = 0; i < countCells; i++)
            {
				int x = rnd.Next(9);
				int y = rnd.Next(9);
				while(initialPuzzle[x, y] == completedPuzzle[x, y])
                {
					x = rnd.Next(9);
					y = rnd.Next(9);
                }
				initialPuzzle[x, y] = completedPuzzle[x, y];
				processingPuzzle[x, y] = completedPuzzle[x, y];
			}
        }
		//Solev random sudoku puzzle
		public static bool SolveSudoku(ref int[,] puzzle, int row, int col)
		{
			if (row < 9 && col < 9)
			{
				if (puzzle[row, col] != 0)
				{
					if ((col + 1) < 9) return SolveSudoku(ref puzzle, row, col + 1);
					else if ((row + 1) < 9) return SolveSudoku(ref puzzle, row + 1, 0);
					else return true;
				}
				else
				{
					for (int i = 0; i < 9; ++i)
					{
						if (IsAvailable(puzzle, row, col, i + 1))
						{
							puzzle[row, col] = i + 1;

							if ((col + 1) < 9)
							{
								if (SolveSudoku(ref puzzle, row, col + 1)) return true;
								else puzzle[row, col] = 0;
							}
							else if ((row + 1) < 9)
							{
								if (SolveSudoku(ref puzzle, row + 1, 0)) return true;
								else puzzle[row, col] = 0;
							}
							else return true;
						}
					}
				}

				return false;
			}
			else return true;
		}
		//Checks if the number already available to reach a correct solution
		private static bool IsAvailable(int[,] puzzle, int row, int col, int num)
		{
			int rowStart = (row / 3) * 3;
			int colStart = (col / 3) * 3;

			for (int i = 0; i < 9; ++i)
			{
				if (puzzle[row, i] == num) return false;
				if (puzzle[i, col] == num) return false;
				if (puzzle[rowStart + (i % 3), colStart + (i / 3)] == num) return false;
			}

			return true;
		}
		//Validate sudoku puzzle from file
		public static bool Validate(int[,] grid)
		{
			for (int i = 0; i < 9; i++)
			{
				bool[] row = new bool[10];
				bool[] col = new bool[10];

				for (int j = 0; j < 9; j++)
				{
					if (row[grid[i, j]] & grid[i, j] > 0)
					{
						return false;
					}
					row[grid[i, j]] = true;

					if (col[grid[j, i]] & grid[j, i] > 0)
					{
						return false;
					}
					col[grid[j, i]] = true;

					if ((i + 3) % 3 == 0 && (j + 3) % 3 == 0)
					{
						bool[] sqr = new bool[10];
						for (int m = i; m < i + 3; m++)
						{
							for (int n = j; n < j + 3; n++)
							{
								if (sqr[grid[m, n]] & grid[m, n] > 0)
								{
									return false;
								}
								sqr[grid[m, n]] = true;
							}
						}
					}

				}
			}
			return true;
		}
	}
}
