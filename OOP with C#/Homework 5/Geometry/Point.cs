using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Geometry
{
    public class Point
    {
        #region Fields
        private int[] coordinates;
        #endregion

        #region Properties
        public int[] Coordinates
        {
            get
            {
                return new int[] { coordinates[0], coordinates[1] };
            }
            set
            {
                if (value != null && value.Length == 2)
                {
                    coordinates = new int[] { value[0], value[1] };
                }
                else
                {
                    coordinates = new int[2];
                }
            }
        }
        #endregion

        #region Constructors
        public Point() : this(new[] { 0, 0 })
        {

        }

        public Point(int[] coordinates)
        {
            Coordinates = coordinates;
        }

        public Point(Point point) : this(point.coordinates)
        {

        }
        #endregion

        public override string ToString()
        {
            return string.Format($"({string.Join(", ", coordinates)})");
        }
    }
}
