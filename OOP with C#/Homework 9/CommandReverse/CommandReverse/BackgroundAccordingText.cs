using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Windows.Data;
using System.Windows.Media;

namespace CommandReverse
{
    [ValueConversion(typeof(string), typeof(Brush))]
    public class BackgroundAccordingText : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            string text = (string)value;
            int length = text.Length;

            if (length == 0)
            {
                return Brushes.White;
            }

            if (length < 8)
            {
                return Brushes.Red;
            }

            return Brushes.Green;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
