using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace SudokuLib
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : UserControl
    {
        private int[,] initialGame;
        private int[,] processingGame;
        private int[,] solutionGame;
        private DispatcherTimer dispatcherTimer;
        private Stopwatch stopWatch;
        private List<Action> logs;
        private int positionLog;
        private ComboBoxItem cbi;
        public MainWindow()
        {
            dispatcherTimer = new DispatcherTimer();
            stopWatch = new Stopwatch();
            InitializeComponent();
            dispatcherTimer.Tick += new EventHandler(Tick);
            dispatcherTimer.Interval = new TimeSpan(0, 0, 0, 1, 0);

            initialGame = new int[9, 9];
            processingGame = new int[9, 9];
            solutionGame = new int[9, 9];
            logs = new List<Action>();
            positionLog = -1;
            
        }

        private void Tick(object sender, EventArgs e)
        {
            if (stopWatch.IsRunning)
            {
                TimeSpan ts = stopWatch.Elapsed;
                txtClock.Text = String.Format("{0:00}:{1:00}:{2:00}",
                    ts.Hours, ts.Minutes, ts.Seconds);
            }
        }

        private void PresentGrid()
        {
            TextBox tb;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if(processingGame[i, j] != 0)
                    {
                        string cell = "txtCell" + i.ToString() + j.ToString();
                        tb = (TextBox)FindName(cell);
                        tb.Text = processingGame[i, j].ToString();
                        tb.IsReadOnly = true;
                    }
                }
            }
           
        }

        private void btnStartGame_OnClick(object sender, RoutedEventArgs e)
        {
            stopWatch.Reset();
            stopWatch.Start();
            dispatcherTimer.Start();
            PresentGrid();
        }

        private void btnNewGame_OnClick(object sender, RoutedEventArgs e)
        {
            if (cboLevel.SelectedItem == null)
            {    
                bool? result;
                string fileName; 

                OpenFileDialog fileChooser = new OpenFileDialog();

                result = fileChooser.ShowDialog();
                fileName = fileChooser.FileName;
                                               
                if (result.HasValue)
                {
                    if (fileName == string.Empty)
                        MessageBox.Show("Invalid File Name", "Error",
                           MessageBoxButton.OK, MessageBoxImage.Error);
                    else
                    {
                        try
                        {
                            FileStream input = new FileStream(
                               fileName, FileMode.Open, FileAccess.Read);

                            StreamReader fileReader = new StreamReader(input);
                            int currentRow = 0;
                            string inputRecord;
                            char[] inputFields;
                            while (!fileReader.EndOfStream)
                            {
                                inputRecord = fileReader.ReadLine();
                                inputFields = inputRecord.ToCharArray();
                                for (int i = 0; i < 9; i++)
                                {
                                    if(inputFields[i] == '_')
                                    {
                                        inputFields[i] = '0';
                                    }
                                    initialGame[currentRow, i] = int.Parse(inputFields[i].ToString());
                                    processingGame[currentRow, i] = int.Parse(inputFields[i].ToString());
                                    solutionGame[currentRow, i] = int.Parse(inputFields[i].ToString());
                                }
                                currentRow++;
                            }
                            if (!SudokuPuzzle.Validate(initialGame))
                            {
                                initialGame = new int[9, 9];
                                processingGame = new int[9, 9];
                                MessageBox.Show("Invalid sudoku puzzle",
                               "File Error", MessageBoxButton.OK,
                               MessageBoxImage.Error);
                                return;
                            }
                            SudokuPuzzle.SolveSudoku(ref solutionGame, 0, 0);
                            btnStartGame.IsEnabled = true;
                            btnResetGame.IsEnabled = true;
                            btnShowSolution.IsEnabled = true;
                            fileReader?.Close();
                        }
                        catch (IOException)
                        {
                            MessageBox.Show("Error reading from file",
                               "File Error", MessageBoxButton.OK,
                               MessageBoxImage.Error);
                        } 
                    } 
                } 
            }
            else
            {
                cbi = (ComboBoxItem)cboLevel.SelectedItem;
                string selectedLevel = cbi.Content.ToString();
                if (selectedLevel == "Easy")
                {
                    int deletedCells = 38;
                    if (!SudokuPuzzle.EmptySudokuSolution(ref solutionGame))
                    {
                        initialGame = new int[9, 9];
                        processingGame = new int[9, 9];
                        solutionGame = new int[9, 9];
                        for (int i = 0; i < 9; i++)
                        {
                            for (int j = 0; j < 9; j++)
                            {
                                string cell = "txtCell" + i.ToString() + j.ToString();
                                TextBox tb = (TextBox)FindName(cell);
                                tb.Clear();
                                tb.IsReadOnly = false;
                                tb.ClearValue(ForegroundProperty);
                            }
                        }
                    }
                    SudokuPuzzle.GeneredMainDiagonal(ref solutionGame);
                    SudokuPuzzle.SolveSudoku(ref solutionGame, 0, 0);
                    SudokuPuzzle.randomPuzzle(ref solutionGame, ref initialGame, ref processingGame, deletedCells);
                    btnStartGame.IsEnabled = true;
                    btnResetGame.IsEnabled = true;
                    btnShowSolution.IsEnabled = true;

                }
                else if (selectedLevel == "Medium")
                {
                    int deletedCells = 32;
                    if (!SudokuPuzzle.EmptySudokuSolution(ref solutionGame))
                    {
                        initialGame = new int[9, 9];
                        processingGame = new int[9, 9];
                        solutionGame = new int[9, 9];
                        for (int i = 0; i < 9; i++)
                        {
                            for (int j = 0; j < 9; j++)
                            {
                                string cell = "txtCell" + i.ToString() + j.ToString();
                                TextBox tb = (TextBox)FindName(cell);
                                tb.Clear();
                                tb.IsReadOnly = false;
                                tb.ClearValue(ForegroundProperty);
                            }
                        }
                    }
                    SudokuPuzzle.GeneredMainDiagonal(ref solutionGame);
                    SudokuPuzzle.SolveSudoku(ref solutionGame, 0, 0);
                    SudokuPuzzle.randomPuzzle(ref solutionGame, ref initialGame, ref processingGame, deletedCells);
                    btnStartGame.IsEnabled = true;
                    btnResetGame.IsEnabled = true;
                    btnShowSolution.IsEnabled = true;

                }
                else if (selectedLevel == "Hard")
                {
                    int deletedCells = 25;
                    if (!SudokuPuzzle.EmptySudokuSolution(ref solutionGame))
                    {
                        initialGame = new int[9, 9];
                        processingGame = new int[9, 9];
                        solutionGame = new int[9, 9];
                        for (int i = 0; i < 9; i++)
                        {
                            for (int j = 0; j < 9; j++)
                            {
                                string cell = "txtCell" + i.ToString() + j.ToString();
                                TextBox tb = (TextBox)FindName(cell);
                                tb.Clear();
                                tb.IsReadOnly = false;
                                tb.ClearValue(ForegroundProperty);
                            }
                        }
                    }
                    SudokuPuzzle.GeneredMainDiagonal(ref solutionGame);
                    SudokuPuzzle.SolveSudoku(ref solutionGame, 0, 0);
                    SudokuPuzzle.randomPuzzle(ref solutionGame, ref initialGame, ref processingGame, deletedCells);
                    btnStartGame.IsEnabled = true;
                    btnResetGame.IsEnabled = true;
                    btnShowSolution.IsEnabled = true;

                }
                else if (selectedLevel == "Evil")
                {
                    int deletedCells = 22;
                    if (!SudokuPuzzle.EmptySudokuSolution(ref solutionGame))
                    {
                        initialGame = new int[9, 9];
                        processingGame = new int[9, 9];
                        solutionGame = new int[9, 9];
                        for (int i = 0; i < 9; i++)
                        {
                            for (int j = 0; j < 9; j++)
                            {
                                string cell = "txtCell" + i.ToString() + j.ToString();
                                TextBox tb = (TextBox)FindName(cell);
                                tb.Clear();
                                tb.IsReadOnly = false;
                                tb.ClearValue(ForegroundProperty);
                            }
                        }
                    }
                    SudokuPuzzle.GeneredMainDiagonal(ref solutionGame);
                    SudokuPuzzle.SolveSudoku(ref solutionGame, 0, 0);
                    SudokuPuzzle.randomPuzzle(ref solutionGame, ref initialGame, ref processingGame, deletedCells);
                    btnStartGame.IsEnabled = true;
                    btnResetGame.IsEnabled = true;
                    btnShowSolution.IsEnabled = true;
                }
            }
           
        }

        private void btnResetGame_OnClick(object sender, RoutedEventArgs e)
        {
            stopWatch.Reset();
            stopWatch.Start();
            logs.Clear();
            positionLog = -1;
            btnStartGame.IsEnabled = false;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if(processingGame[i, j] != initialGame[i, j])
                    {
                        string cell = "txtCell" + i.ToString() + j.ToString();
                        TextBox tb = (TextBox)FindName(cell);
                        tb.Text = "";
                        tb.IsReadOnly = false;
                    }
                }
            }
        }

        private void btnUndo_OnClick(object sender, RoutedEventArgs e)
        {
            if(positionLog == -1)
            {
                return;
            }
            Action previousLog = logs[positionLog--];
            logs.Remove(previousLog);
            string cell = "txtCell" + previousLog.X.ToString() + previousLog.Y.ToString();
            TextBox tb = (TextBox)FindName(cell);
            if(previousLog.OldSymbol == 0)
            {
                tb.Text = "";
            }
            else
            {
                tb.Text = previousLog.OldSymbol.ToString();
            }
            processingGame[previousLog.X, previousLog.Y] = previousLog.OldSymbol;
            if (processingGame[previousLog.X, previousLog.Y] == solutionGame[previousLog.X, previousLog.Y])
            {
                tb.Foreground = new SolidColorBrush(Color.FromRgb(0, 255, 0));
            }
            else
            {
                tb.Foreground = new SolidColorBrush(Color.FromRgb(255, 0, 0));
            }
        }

        private void btnShowSolution_OnClick(object sender, RoutedEventArgs e)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    processingGame[i, j] = solutionGame[i, j];
                }
            }
            PresentGrid();
            stopWatch.Reset();
            btnStartGame.IsEnabled = false;
        }

        private void btnSaveGame_OnClick(object sender, RoutedEventArgs e)
        {
            bool? result;
            string fileName;
            SaveFileDialog fileChooser = new SaveFileDialog
            {
                CheckFileExists = false
            };
            result = fileChooser.ShowDialog();
            fileName = fileChooser?.FileName;

            if (result.HasValue)
            {
                if (fileName == string.Empty)
                    MessageBox.Show("Invalid File Name", "Error",
                       MessageBoxButton.OK, MessageBoxImage.Error);
                else
                {
                    try
                    {
                        FileStream output = new FileStream(fileName,
                           FileMode.OpenOrCreate, FileAccess.Write);

                        StreamWriter fileWriter = new StreamWriter(output);
                        for (int i = 0; i < 9; i++)
                        {
                            for (int j = 0; j < 9; j++)
                            {
                                fileWriter.Write(processingGame[i,j].ToString());
                            }
                            fileWriter.WriteLine();
                        }
                        fileWriter?.Close();
                    }
                    catch (IOException)
                    {
                        MessageBox.Show("Error opening file", "Error",
                           MessageBoxButton.OK, MessageBoxImage.Error);
                    }
                }
            } 
        }

        private void PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            var cell = sender as TextBox;
            var symbol = int.Parse(e.Text);
            var allowedSymbolsList = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            if (!allowedSymbolsList.Contains(symbol))
            {
                return;
            }

            string nameCell = cell.Name;
            int x = int.Parse(nameCell[7].ToString());
            int y = int.Parse(nameCell[8].ToString());
            var oldSymbol = processingGame[x, y];
            processingGame[x, y] = symbol;

            if (processingGame[x,y] == solutionGame[x,y])
            {
                cell.Foreground = new SolidColorBrush(Color.FromRgb(0, 255, 0));
            }
            else
            {
                cell.Foreground = new SolidColorBrush(Color.FromRgb(255, 0, 0));
            }
            logs.Add(new Action(oldSymbol, symbol, x, y));
            positionLog++;
            btnUndo.IsEnabled = true;
            btnSaveGame.IsEnabled = true;

            if(SudokuPuzzle.SudokuComplete(ref processingGame, ref solutionGame))
            {
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string time = String.Format("{0:00}:{1:00}:{2:00}",
                    ts.Hours, ts.Minutes, ts.Seconds);
                MessageBox.Show("Level: " + cbi.Content.ToString() + "\nTime: " + time,
                               "Exelent", MessageBoxButton.OK,
                               MessageBoxImage.Information);

                btnStartGame.IsEnabled = false;
                btnUndo.IsEnabled = false;
                btnShowSolution.IsEnabled = false;
                
            }
        }
    }
}
