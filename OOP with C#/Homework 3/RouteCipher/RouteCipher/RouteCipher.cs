using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RouteCipher
{
    public class RouteCipher
    {
        #region Fields
        private int key;
        #endregion

        #region Properties
        public int Key
        {
            get { return key; }
            set { key = value == 0 ? 1 : value; }
        }
        #endregion

        #region Constructors
        public RouteCipher(int key)
        {
            Key = key;
        }
        #endregion

        #region Methods
        public string Encrypt(string plainText)
        {
            string plainTextLetters = "";
            char[] plainTextChars = plainText.ToCharArray();

            foreach (char charInPlainText in plainTextChars)
            {
                // Before encrypting the message, we need to make sure that it contains only letters and maybe (?) numbers.
                if ((charInPlainText >= 'A' && charInPlainText <= 'Z') || (charInPlainText >= 'a' && charInPlainText <= 'z')
                                                                       || (charInPlainText >= '0' && charInPlainText <= '9'))
                {
                    plainTextLetters += charInPlainText;
                }
            }

            // We need to create a matrix where we can place our message letter by letter.

            int sizePlainTextLetters = plainTextLetters.Length;
            int columns = Math.Abs(key); // The columns that our matrix will have.
            int rows = (int)(Math.Ceiling((double)sizePlainTextLetters / columns)); // The rows that our matrix will have.

            char[] plainTextLettersArray = plainTextLetters.ToCharArray();
            char[,] plainTextMatrix = new char[rows, columns]; // We will be able to create our matrix after we have determined the rows and columns.
            int counterPlainTextLetters = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (counterPlainTextLetters < sizePlainTextLetters)
                        plainTextMatrix[i, j] = plainTextLettersArray[counterPlainTextLetters++]; // Fill each cell in the matrix with a letter.
                    else
                    {
                        // By default, the symbol that should fill in the blanks that remain due to the length of the message is the letter 'X'.
                        // However, decryption cannot define the message correctly, as the character must be uniquely identified.
                        // For this reason, I changed the 'X' symbol to '&' symbol.
                        plainTextMatrix[i, j] = '&';
                    }
                }
            }

            // If the key is positive, we use an encryption method that starts from the upper left corner.
            // Otherwise, the encryption method starts from the lower right corner.
            string cipherText;
            if (key > 0)
            {
                cipherText = EncryptFromUpperLeftCorner(rows, columns, plainTextMatrix);
            }
            else
            {
                cipherText = EncryptFromLowerRightCorner(rows, columns, plainTextMatrix);
            }

            return cipherText;
        }

        private bool IsValidCoordinate(int coordinate, int boundary)
        {
            // Check if the coordinate is valid.
            return coordinate >= 0 && coordinate < boundary;
        }

        private char VisitAndTakeLetter(int currentX, int currentY, bool[,] visitedLetters, char[,] textMatrix)
        {
            // We note in the boolean matrix that we have visited a letter and return the letter as a result.
            visitedLetters[currentX, currentY] = true;
            return textMatrix[currentX, currentY];
        }

        private string EncryptFromLowerRightCorner(int rows, int columns, char[,] plainTextMatrix)
        {
            // The coordinates of the last cell of the matrix.
            int currentX = rows - 1;
            int currentY = columns - 1;

            // Boolean matrix with the same dimensions as our matrix of letters to determine which letters we have already visited.
            bool[,] visitedLetters = new bool[rows, columns];
            string cipherText = "";
            cipherText += plainTextMatrix[currentX, currentY]; // We add the letter to our encrypted message.
            visitedLetters[currentX, currentY] = true; // We note that we have already visited the last cell.
            int counterLetters = 1; // Count how many letters we have visited.

            // First we go up as much as we can, then to the left as much as we can, then down as much as we can and
            // finally to the right as much as we can and this cycle is repeated as many times as possible.
            // Thanks to the boolean matrix, we determine where we can get a letter from.
            while (counterLetters != rows * columns)
            {
                while (IsValidCoordinate(currentX - 1, rows) && !visitedLetters[currentX - 1, currentY])
                {
                    currentX--;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY - 1, columns) && !visitedLetters[currentX, currentY - 1])
                {
                    currentY--;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentX + 1, rows) && !visitedLetters[currentX + 1, currentY])
                {
                    currentX++;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY + 1, columns) && !visitedLetters[currentX, currentY + 1])
                {
                    currentY++;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
            }

            return cipherText;
        }

        private string EncryptFromUpperLeftCorner(int rows, int columns, char[,] plainTextMatrix)
        {
            // The coordinates of the first cell of the matrix.
            int currentX = 0;
            int currentY = 0;

            // Boolean matrix with the same dimensions as our matrix of letters to determine which letters we have already visited.
            bool[,] visitedLetters = new bool[rows, columns];
            string cipherText = "";
            cipherText += plainTextMatrix[currentX, currentY]; // We add the letter to our encrypted message.
            visitedLetters[currentX, currentY] = true; // We note that we have already visited the first cell.
            int counterLetters = 1; // Count how many letters we have visited.

            // First we go down as much as we can, then to the right as much as we can, then up as much as we can and
            // finally to the left as much as we can and this cycle is repeated as many times as possible.
            // Thanks to the boolean matrix, we determine where we can get a letter from.
            while (counterLetters != rows * columns)
            {
                while (IsValidCoordinate(currentX + 1, rows) && !visitedLetters[currentX + 1, currentY])
                {
                    currentX++;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY + 1, columns) && !visitedLetters[currentX, currentY + 1])
                {
                    currentY++;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentX - 1, rows) && !visitedLetters[currentX - 1, currentY])
                {
                    currentX--;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY - 1, columns) && !visitedLetters[currentX, currentY - 1])
                {
                    currentY--;
                    cipherText += VisitAndTakeLetter(currentX, currentY, visitedLetters, plainTextMatrix);
                    counterLetters++;
                }
            }

            return cipherText;
        }

        public string Decrypt(string cipherText)
        {
            // We need to create a matrix where we can place our encrypted message letter by letter.

            int sizeCipherTextLetters = cipherText.Length;
            int columns = Math.Abs(key); // The columns that our matrix will have.
            int rows = (int)(Math.Ceiling((double)sizeCipherTextLetters / columns)); // The rows that our matrix will have.

            char[] cipherTextLetters = cipherText.ToCharArray();

            // We create a one-dimensional array, where there are exactly as many characters as we need to fill in the future matrix.
            char[] cipherTextLettersArray = new char[rows * columns];

            // In case a person wants to decrypt a message with a different key from the one given for creating the encrypted message.
            for (int i = 0; i < cipherTextLettersArray.Length; i++)
            {
                if (i < sizeCipherTextLetters)
                {
                    cipherTextLettersArray[i] = cipherTextLetters[i];
                }
                else
                {
                    cipherTextLettersArray[i] = '&';
                }
            }

            // If the key is positive, we use an decryption method that starts from the upper left corner.
            // Otherwise, the decryption method starts from the lower right corner.
            string plainText;
            if (key > 0)
            {
                plainText = DecryptFromUpperLeftCorner(rows, columns, cipherTextLettersArray);
            }
            else
            {
                plainText = DecryptFromLowerRightCorner(rows, columns, cipherTextLettersArray);
            }

            return plainText;
        }

        private void MoveAndWrite(int currentX, int currentY, bool[,] writtenLetters, char[,] plainTextMatrix,
            char[] cipherTextLettersArray, int counterLetters)
        {
            // Fill in a letter of the given position in the matrix of letters
            // and note in the boolean matrix that there is already a letter in this position.
            writtenLetters[currentX, currentY] = true;
            plainTextMatrix[currentX, currentY] = cipherTextLettersArray[counterLetters];
        }

        private string CreatePlainText(int rows, int columns, char[,] plainTextMatrix)
        {
            // Once we have filled in the encrypted message in the matrix of letters,
            // we can now create and decrypt the message by reading it from the beginning of the matrix
            string plainText = "";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (plainTextMatrix[i, j] != '&')
                    {
                        plainText += plainTextMatrix[i, j];
                    }
                }
            }

            return plainText;
        }

        private string DecryptFromLowerRightCorner(int rows, int columns, char[] cipherTextLettersArray)
        {
            // The coordinates of the last cell of the matrix.
            int currentX = rows - 1;
            int currentY = columns - 1;

            // We create an empty matrix in which we have to fill in the encrypted message letter by letter.
            char[,] plainTextMatrix = new char[rows, columns];

            // Boolean matrix with the same dimensions as our matrix of letters to determine which letters we have already written.
            bool[,] writtenLetters = new bool[rows, columns];
            int counterLetters = 0; // Count how many letters we have filled.
            plainTextMatrix[currentX, currentY] = cipherTextLettersArray[counterLetters++]; // Fill in a letter in the last cell of the matrix.
            writtenLetters[currentX, currentY] = true; // We note the filling in the boolean matrix.

            // First we go up as much as we can, then to the left as much as we can, then down as much as we can and
            // finally to the right as much as we can and this cycle is repeated as many times as possible.
            // Thanks to the boolean matrix, we determine where we can fill in a letter.
            while (counterLetters != rows * columns)
            {
                while (IsValidCoordinate(currentX - 1, rows) && !writtenLetters[currentX - 1, currentY])
                {
                    currentX--;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY - 1, columns) && !writtenLetters[currentX, currentY - 1])
                {
                    currentY--;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentX + 1, rows) && !writtenLetters[currentX + 1, currentY])
                {
                    currentX++;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY + 1, columns) && !writtenLetters[currentX, currentY + 1])
                {
                    currentY++;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
            }

            return CreatePlainText(rows, columns, plainTextMatrix);
        }

        private string DecryptFromUpperLeftCorner(int rows, int columns, char[] cipherTextLettersArray)
        {
            // The coordinates of the first cell of the matrix.
            int currentX = 0;
            int currentY = 0;

            // We create an empty matrix in which we have to fill in the encrypted message letter by letter.
            char[,] plainTextMatrix = new char[rows, columns];

            // Boolean matrix with the same dimensions as our matrix of letters to determine which letters we have already written.
            bool[,] writtenLetters = new bool[rows, columns];
            int counterLetters = 0; // Count how many letters we have filled.
            plainTextMatrix[currentX, currentY] = cipherTextLettersArray[counterLetters++]; // Fill in a letter in the first cell of the matrix.
            writtenLetters[currentX, currentY] = true; // We note the filling in the boolean matrix.

            // First we go down as much as we can, then to the right as much as we can, then up as much as we can and
            // finally to the left as much as we can and this cycle is repeated as many times as possible.
            // Thanks to the boolean matrix, we determine where we can fill in a letter.
            while (counterLetters != rows * columns)
            {
                while (IsValidCoordinate(currentX + 1, rows) && !writtenLetters[currentX + 1, currentY])
                {
                    currentX++;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY + 1, columns) && !writtenLetters[currentX, currentY + 1])
                {
                    currentY++;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentX - 1, rows) && !writtenLetters[currentX - 1, currentY])
                {
                    currentX--;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
                while (IsValidCoordinate(currentY - 1, columns) && !writtenLetters[currentX, currentY - 1])
                {
                    currentY--;
                    MoveAndWrite(currentX, currentY, writtenLetters, plainTextMatrix, cipherTextLettersArray, counterLetters);
                    counterLetters++;
                }
            }

            return CreatePlainText(rows, columns, plainTextMatrix);
        }
        #endregion

        public override string ToString()
        {
            string result = $"The cipher key is: {key}";

            if (key > 0)
            {
                return result + "\nThe key is positive -> the route for encrypting and decrypting starts "
                       + "from the first cell in the upper left corner of the grid.";
            }

            return result + "\nThe key is negative -> the route for encrypting and decrypting starts "
                   + "from the last cell in the lower right corner of the grid.";
        }
    }
}
