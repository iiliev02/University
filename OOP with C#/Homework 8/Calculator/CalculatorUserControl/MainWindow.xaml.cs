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

namespace CalculatorUserControl
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : UserControl
    {
        private enum Operation
        {
            Divide,
            Multiply,
            Subtract,
            Add,
            Sqrt,
            Degree,
            OneX,
            Negate,
            None
        }

        private Operation operation;
        private string display;
        private string lastValue;
        private string memory;
        private bool eraseDisplay;

        private bool EraseDisplay
        {
            get => eraseDisplay;
            set => eraseDisplay = value;
        }
        
        private Double Memory
        {
            get => memory == string.Empty ? 0.0 : Convert.ToDouble(memory);
            set => memory = value.ToString();
        }
        
        private string LastValue
        {
            get => lastValue == string.Empty ? "0" : lastValue;
            set => lastValue = value;
        }
        
        private string Display
        {
            get => display;
            set => display = value;
        }

        public MainWindow()
        {
            InitializeComponent();
            eraseDisplay = true;
            operation = Operation.None;
        }

        private void OnWindowKeyDown(object sender, TextCompositionEventArgs args)
        {
            string userInput = args.Text;
            char symbol = userInput.ToCharArray()[0];
            args.Handled = true;

            if ((symbol >= '0' && symbol <= '9') || symbol == '.' || symbol == '\b')
            {
                ProcessKey(symbol);
                return;
            }

            switch (symbol)
            {
                case '+':
                    ProcessOperation("+");
                    break;
                case '-':
                    ProcessOperation("-");
                    break;
                case '*':
                    ProcessOperation("x");
                    break;
                case '/':
                    ProcessOperation("/");
                    break;
                case '=':
                    ProcessOperation("=");
                    break;
            }
        }

        private void ProcessKey(char symbol)
        {
            if (EraseDisplay)
            {
                Display = string.Empty;
                EraseDisplay = false;
            }

            AddToDisplay(symbol);
        }

        private void ProcessOperation(string sign)
        {
            Double d = 0.0;
            switch (sign)
            {
                case "/":
                    if (EraseDisplay)
                    {
                        operation = Operation.Divide;
                        break;
                    }

                    CalcResults();
                    operation = Operation.Divide;
                    LastValue = Display;
                    EraseDisplay = true;
                    break;
                case "x":
                    if (EraseDisplay)
                    {
                        operation = Operation.Multiply;
                        break;
                    }

                    CalcResults();
                    operation = Operation.Multiply;
                    LastValue = Display;
                    EraseDisplay = true;
                    break;
                case "-":
                    if (EraseDisplay)
                    {
                        operation = Operation.Subtract;
                        break;
                    }

                    CalcResults();
                    operation = Operation.Subtract;
                    LastValue = Display;
                    EraseDisplay = true;
                    break;
                case "+":
                    if (EraseDisplay)
                    {
                        operation = Operation.Add;
                        break;
                    }

                    CalcResults();
                    operation = Operation.Add;
                    LastValue = Display;
                    EraseDisplay = true;
                    break;
                case "Sqrt":
                    operation = Operation.Sqrt;
                    LastValue = Display;
                    CalcResults();
                    LastValue = Display;
                    EraseDisplay = true;
                    operation = Operation.None;
                    break;
                case "^":
                    if (EraseDisplay)
                    {
                        operation = Operation.Degree;
                        break;
                    }

                    CalcResults();
                    operation = Operation.Degree;
                    LastValue = Display;
                    EraseDisplay = true;
                    break;
                case "1/X":
                    operation = Operation.OneX;
                    LastValue = Display;

                    CalcResults();
                    LastValue = Display;
                    EraseDisplay = true;
                    operation = Operation.None;
                    break;
                case "+/-":
                    operation = Operation.Negate;
                    LastValue = Display;

                    CalcResults();
                    LastValue = Display;
                    EraseDisplay = true;
                    operation = Operation.None;
                    break;
                case "=":
                    if (EraseDisplay)
                        break;

                    CalcResults();
                    EraseDisplay = true;
                    operation = Operation.None;
                    LastValue = Display;
                    break;
                case "C":
                    operation = Operation.None;
                    Display = LastValue = string.Empty;
                    UpdateDisplay();
                    break;
                case "CE":
                    if (operation == Operation.None)
                    {
                        LastValue = "0";
                    }

                    Display = "0";
                    EraseDisplay = true;
                    UpdateDisplay();
                    break;
                case "MC":
                    Memory = 0.0F;
                    DisplayMemory();
                    break;
                case "M":
                    Memory = Convert.ToDouble(Display);
                    DisplayMemory();
                    EraseDisplay = true;
                    break;
                case "M-":
                    d = Memory - Convert.ToDouble(Display);
                    Memory = d;
                    DisplayMemory();
                    EraseDisplay = true;
                    break;
                case "M+":
                    d = Memory + Convert.ToDouble(Display);
                    Memory = d;
                    DisplayMemory();
                    EraseDisplay = true;
                    break;
            }
        }

        private double Calc(Operation operation)
        {
            double result = 0.0;

            try
            {
                switch (operation)
                {
                    case Operation.Divide:
                        result = Convert.ToDouble(LastValue) / Convert.ToDouble(Display);
                        CheckResult(ref result);
                        break;
                    case Operation.Multiply:
                        result = Convert.ToDouble(LastValue) * Convert.ToDouble(Display);
                        CheckResult(ref result);
                        break;
                    case Operation.Subtract:
                        result = Convert.ToDouble(LastValue) - Convert.ToDouble(Display);
                        CheckResult(ref result);
                        break;
                    case Operation.Add:
                        result = Convert.ToDouble(LastValue) + Convert.ToDouble(Display);
                        CheckResult(ref result);
                        break;
                    case Operation.Sqrt:
                        result = Math.Sqrt(Convert.ToDouble(LastValue));
                        CheckResult(ref result);
                        break;
                    case Operation.Degree:
                        result = Math.Pow(Convert.ToDouble(LastValue), Convert.ToDouble(Display));
                        CheckResult(ref result);
                        break;
                    case Operation.OneX:
                        result = 1.0F / Convert.ToDouble(LastValue);
                        CheckResult(ref result);
                        break;
                    case Operation.Negate:
                        result = Convert.ToDouble(LastValue) * (-1.0F);
                        break;
                }
            }
            catch
            {
                result = 0;
                MessageBox.Show("Cannot divide by zero!");
            }

            return result;
        }

        private void CheckResult(ref double result)
        {
            if (Double.IsNegativeInfinity(result) || Double.IsPositiveInfinity(result) || Double.IsNaN(result))
            {
                MessageBox.Show("Result is undefined!");
                ProcessOperation("C");
                result = 0;
            }
        }

        private void DisplayMemory()
        {
            if (memory != String.Empty)
                txtMemory.Text = "Memory: " + memory;
            else
                txtMemory.Text = "Memory: [empty]";
        }
        private void CalcResults()
        {
            double result;
            if (operation == Operation.None)
                return;

            result = Calc(operation);
            Display = result.ToString();

            UpdateDisplay();
        }

        private void UpdateDisplay()
        {
            txtEntry.Text = Display == String.Empty ? "0" : Display;
        }

        private void AddToDisplay(char symbol)
        {
            if (symbol == '.')
            {
                if (Display.IndexOf('.', 0) >= 0)
                    return;

                Display = Display + symbol;
            }
            else
            {
                if (symbol >= '0' && symbol <= '9')
                {
                    Display = Display + symbol;
                }
                else
                {
                    if (symbol == '\b')
                    {
                        if (Display.Length <= 1)
                        {
                            Display = String.Empty;
                        }
                        else
                        {
                            int i = Display.Length;
                            Display = Display.Remove(i - 1, 1);
                        }
                    }
                }
            }

            UpdateDisplay();
        }

        private void DigitButton_OnClick(object sender, RoutedEventArgs e)
        {
            string content = ((Button)sender).Content.ToString();
            ProcessKey(content.ToCharArray()[0]);
        }

        private void OperationButton_OnClick(object sender, RoutedEventArgs e)
        {
            ProcessOperation(((Button)sender).Content.ToString());
        }
    }
}
