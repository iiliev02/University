using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Geometry
{
    public class Rectangle
    {
        #region Fields
        private Point[] corners;
        #endregion

        #region Properties
        public Point[] Corners
        {
            get
            {
                return new Point[] { corners[0], corners[1] };
            }
            set
            {
                if (value != null && value.Length == 2)
                {
                    corners = new Point[] { value[0], value[1] };
                }
                else
                {
                    corners = new Point[2];
                }
            }
        }
        #endregion

        #region Constructors
        public Rectangle() : this(new[] { new Point(new int[] { -1, 1 }), new Point() })
        {

        }

        public Rectangle(Point[] corners)
        {
            Corners = corners;
        }

        public Rectangle(Rectangle rectangle) : this(rectangle.corners)
        {

        }
        #endregion

        #region Methods
        public double Perimeter()
        {
            // The coordinates of the points are integers and the perimeter will always be an integer 
            // => an integer can be returned as a result instead of double.

            double length = Math.Abs(corners[0].Coordinates[0] - corners[1].Coordinates[0]);
            double width = Math.Abs(corners[0].Coordinates[1] - corners[1].Coordinates[1]);

            double perimeter = 2 * (length + width);
            return perimeter;
        }
        #endregion

        public override string ToString()
        {
            return string.Format($"Upper left corner: {corners[0]}\nLower right corner: {corners[1]}");
        }
    }
}
