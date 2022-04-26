using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace ProblemOne
{
    public class Product
    {
        #region Fields
        private static long cnt;
        private static readonly Random rnd = new Random();
        public readonly string ID;
        public List<int> WeeklyPurchases;
        #endregion

        #region Properties
        public Type Category { get; }
        public string Description { get; }
        public decimal Price { get; }
        public YearlyQuarter Quarter { get; }
        #endregion

        #region Constructors
        public Product(string description, Type category, List<int> weeklyPurchases, decimal price)
        {
            Description = description;
            Category = category;
            WeeklyPurchases = weeklyPurchases;
            Price = price;

            ID = $"{Category}{cnt++:000000}";
            Quarter = (YearlyQuarter)rnd.Next(4);
        }
        #endregion

        public override string ToString()
        {
            return $"{ID}: {string.Join(", ", WeeklyPurchases)}";
        }
    }
}
