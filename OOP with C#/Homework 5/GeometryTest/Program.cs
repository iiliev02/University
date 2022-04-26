using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Geometry;

namespace GeometryTest
{
    public class Program
    {
        private static double CircleArea(Rectangle rectangle)
        {
            double length = Math.Abs(rectangle.Corners[0].Coordinates[0] - rectangle.Corners[1].Coordinates[0]);
            double width = Math.Abs(rectangle.Corners[0].Coordinates[1] - rectangle.Corners[1].Coordinates[1]);

            // (2r)^2 = length^2 + width^2 => 2r = Sqrt(length^2 + width^2) => r = Sqrt(length^2 + width^2) / 2;
            double r = Math.Sqrt(Math.Pow(length, 2) + Math.Pow(width, 2)) / 2;
            double area = Math.PI * Math.Pow(r, 2);

            return area;
        }

        public static void Main(string[] args)
        {
            Point firstPoint = new Point();
            Point secondPoint = new Point(new int[] { -5, -3 });

            Rectangle rectangle = new Rectangle(new Point[] {firstPoint, secondPoint});

            Console.WriteLine(rectangle);
            Console.WriteLine($"Perimeter: {rectangle.Perimeter()}");
            Console.WriteLine($"Area of the circle around the rectangle: {CircleArea(rectangle):F2}");
        }
    }
}
