using System;
using System.Collections.Generic;
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

namespace ProblemOne
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Fields
        private enum Operation
        {
            NO_OPERATION,
            MULTIPLY,
            PLUS,
            SUBTRACT,
            DIVIDE,
            SIN,
            COS,
            EXP,
            SQRT,
            LOG,
            ONEDIVIDEDBY
        }

        private Operation operation;
        private double inputOne;
        private double inputTwo;
        private double result;
        #endregion

        public MainWindow()
        {
            InitializeComponent();
        }

        #region Utility methods
        /// <summary>
        /// Types a digit
        /// </summary>
        /// <param name="digit"></param>
        private void TypeDigit(string digit)
        {
            if (txtInput.Text.Equals("0"))
            {
                if (digit == "00" || digit == "0")
                {
                    return;
                }

                if (digit == ".")
                {
                    txtInput.Text = "0.";
                }
                else
                {
                    txtInput.Text = digit;
                }
            }
            else
            {
                if (digit == "." && txtInput.Text.Contains("."))
                {
                    return;
                }

                txtInput.Text += digit;
            }
        }
        #endregion

        #region Event handlers
        private void BtnClick(object sender, RoutedEventArgs e)
        {
            TypeDigit((string)((Button)sender).Content);
        }

        private void OperationClick(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(txtInput.Text, out inputOne))
            {
                string operationCode = (string)((Button)sender).Content;

                switch (operationCode)
                {
                    case "+":
                        operation = Operation.PLUS;
                        break;
                    case "-":
                        operation = Operation.SUBTRACT;
                        break;
                    case "x":
                        operation = Operation.MULTIPLY;
                        break;
                    case "/":
                        operation = Operation.DIVIDE;
                        break;
                    case "sin":
                        operation = Operation.SIN;
                        break;
                    case "cos":
                        operation = Operation.COS;
                        break;
                    case "exp":
                        operation = Operation.EXP;
                        break;
                    case "√":
                        operation = Operation.SQRT;
                        break;
                    case "log":
                        operation = Operation.LOG;
                        break;
                    case "1/x":
                        operation = Operation.ONEDIVIDEDBY;
                        break;
                }
            }
            else
            {
                MessageBox.Show("Wrong input!");
            }

            txtInput.Text = "0";
        }

        private void ComputeClick(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(txtInput.Text, out inputTwo))
            {
                switch (operation)
                {
                    case Operation.MULTIPLY:
                        result = inputOne * inputTwo;
                        break;
                    case Operation.PLUS:
                        result = inputOne + inputTwo;
                        break;
                    case Operation.SUBTRACT:
                        result = inputOne - inputTwo;
                        break;
                    case Operation.DIVIDE:
                        result = inputOne / inputTwo;
                        break;
                    case Operation.SIN:
                        result = Math.Sin(inputTwo);
                        break;
                    case Operation.COS:
                        result = Math.Cos(inputTwo);
                        break;
                    case Operation.EXP:
                        result = Math.Exp(inputTwo);
                        break;
                    case Operation.SQRT:
                        result = Math.Sqrt(inputTwo);
                        break;
                    case Operation.LOG:
                        result = Math.Log10(inputTwo);
                        break;
                    case Operation.ONEDIVIDEDBY:
                        result = 1.0 / inputTwo;
                        break;
                }
            }
            else
            {
                MessageBox.Show("Wrong input!");
                result = 0;
            }

            txtInput.Text = "" + result;
            operation = Operation.NO_OPERATION;
        }

        private void btnC_Click(object sender, RoutedEventArgs e)
        {
            inputTwo = 0;
            txtInput.Text = "0";
            operation = Operation.NO_OPERATION;
        }

        private void btnCA_Click(object sender, RoutedEventArgs e)
        {
            inputOne = inputTwo = 0;
            txtInput.Text = "0";
            operation = Operation.NO_OPERATION;
        }

        private void BtnOff_Click(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }
        #endregion
    }
}
