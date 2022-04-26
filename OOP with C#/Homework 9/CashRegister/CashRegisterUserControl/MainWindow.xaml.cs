using System;
using System.Collections.Generic;
using System.Globalization;
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

namespace CashRegisterUserControl
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : UserControl
    {
        private decimal total;
        private decimal cashEntry;
        private bool totalIsClicked;
        private const int taxPercentage = 20;

        public MainWindow()
        {
            InitializeComponent();

            total = 0;
            cashEntry = 0;
        }

        private void DigitButton_OnClick(object sender, RoutedEventArgs e)
        {
            string valueOfButton = ((Button)e.Source).Content.ToString();
            txtEntry.AppendText(valueOfButton);
        }

        private void PointButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (txtEntry.Text.Length == 0)
            {
                txtEntry.Text += "0.";
                return;
            }

            if (!txtEntry.Text.Contains("."))
            {
                txtEntry.Text += ".";
            }
        }

        private decimal CashEntryToDecimal()
        {
            string value = txtEntry.Text;
            return decimal.Parse(txtEntry.Text);
        }

        private void UpdateData()
        {
            txtSubtotal.Text = total.ToString();
            txtTax.Text = (taxPercentage * total / 100).ToString();
        }

        private void ClearData()
        {
            total = 0;
            cashEntry = 0;
            totalIsClicked = false;

            txtEntry.Text = string.Empty;
            txtSubtotal.Text = string.Empty;
            txtTax.Text = string.Empty;
            txtTotal.Text = string.Empty;
        }

        private void EnterButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (totalIsClicked)
            {
                if (string.IsNullOrEmpty(txtEntry.Text))
                {
                    ClearData();
                    return;
                }

                decimal cashEntryAfterTotal = CashEntryToDecimal();
                ClearData();

                cashEntry = cashEntryAfterTotal;
                total += cashEntry;

                UpdateData();
                txtEntry.Text = string.Empty;

                return;
            }

            if (string.IsNullOrEmpty(txtEntry.Text))
            {
                return;
            }

            cashEntry = CashEntryToDecimal();
            total += cashEntry;

            UpdateData();
            txtEntry.Text = string.Empty;
        }

        private void TotalButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (!string.IsNullOrEmpty(txtEntry.Text))
            {
                cashEntry = CashEntryToDecimal();
                total += cashEntry;
                UpdateData();
                txtEntry.Text = string.Empty;
            }

            if (!totalIsClicked)
            {
                if (!string.IsNullOrEmpty(txtTax.Text))
                {
                    total += decimal.Parse(txtTax.Text);
                }
            }

            txtTotal.Text = total.ToString();
            totalIsClicked = true;
        }

        private void DeleteButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (totalIsClicked)
            {
                ClearData();
                return;
            }

            total -= cashEntry;
            cashEntry = 0;

            UpdateData();
        }

        private void ClearButton_OnClick(object sender, RoutedEventArgs e)
        {
            ClearData();
        }
    }
}
