using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemOne
{
    public class Program
    {
        private static List<Product> products = new List<Product>()
        {
            new Product("Electric sander", Type.M, new List<int>() { 99, 82, 81, 79 }, 157.98M),
            new Product("Power saw", Type.M, new List<int>() { 99, 86, 90, 94  }, 99.99M),
            new Product("Sledge hammer", Type.F, new List<int>() { 93, 92, 80, 87 }, 21.50M),
            new Product("Hammer", Type.M, new List<int>() { 97, 89, 85, 82 }, 11.99M),
            new Product("Lawn mower", Type.F, new List<int>() { 35, 72, 91, 70 }, 139.50M),
            new Product("Screwdriver", Type.F, new List<int>() { 88, 94, 65, 91 }, 56.99M),
            new Product("Jig saw", Type.M, new List<int>() { 75, 84, 91, 39 }, 11.00M),
            new Product("Wrench", Type.F, new List<int>() { 97, 92, 81, 60 }, 17.50M),
            new Product("Sledge hammer", Type.M, new List<int>() { 75, 84, 91, 39 }, 21.50M),
            new Product("Hammer", Type.F, new List<int>() { 94, 92, 91, 91 }, 11.99M),
            new Product("Lawn mower", Type.M, new List<int>() { 96, 85, 91, 60 }, 179.50M),
            new Product("Screwdriver", Type.M, new List<int>() { 96, 85, 51, 30 }, 66.99M)
        };

        public static void WriteSubsection(string subsection)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("\n" + subsection);
            Console.ResetColor();
        }

        public static void GroupByCategoryCountDescending()
        {
            var groupByCategoryCountDescending = products
                .GroupBy(p => p.Category)
                .Select(group => new { Name = group.Key, Products = group.ToList() })
                .OrderByDescending(pair => pair.Products.Count())
                .ToList();

            foreach (var pair in groupByCategoryCountDescending)
            {
                Console.WriteLine($"Category group: {pair.Name}");
                Console.WriteLine(new string(' ', 16) + $"Number of products of Type {pair.Name} in this group: {pair.Products.Count}\n");
                //Console.WriteLine("{0,16}Number of products of Type {1} in this group: {2}", string.Empty, pair.Name, pair.Products.Count);
            }
        }

        public static void GroupByQtrAndProductPriceAvg()
        {
            var groupByQtrAndProductPriceAvg = products
                .GroupBy(p => p.Quarter)
                .Select(group => new { Name = group.Key, Products = group.ToList() })
                .OrderBy(pair => pair.Name)
                .ToList();

            foreach (var pair in groupByQtrAndProductPriceAvg)
            {
                Console.WriteLine($"Quarter group: {pair.Name}");
                Console.WriteLine(new string(' ', 8) + $"Average price per Quarter: ${pair.Products.Average(a => a.Price):F2}\n");
            }
        }

        public static void GroupByQtrCategoryWeeklySum()
        {
            var groupByQtrCategoryWeeklySum = products
                .GroupBy(p => p.Quarter)
                .Select(groupOne => new
                {
                    Name = groupOne.Key,
                    CategoryProductsGroup = groupOne
                    .GroupBy(p => p.Category)
                    .Select(groupTwo => new
                    {
                        Name = groupTwo.Key,
                        Tuples = groupTwo
                        .Select(p => (p.Description, p.WeeklyPurchases.Sum()))
                        .ToList()
                    })
                    .ToList()
                })
                .OrderBy(pair => pair.Name)
                .ToList();

            foreach (var pair in groupByQtrCategoryWeeklySum)
            {
                int theLongestWord = products
                    .Select(p => p.Description.Length)
                    .OrderByDescending(p => p)
                    .ToList()
                    .FirstOrDefault();

                Console.WriteLine($"Quarter group: {pair.Name}");

                foreach (var pairTwo in pair.CategoryProductsGroup)
                {
                    Console.WriteLine(new string(' ', 8) + $"Category group: {pairTwo.Name}");

                    foreach (var tuple in pairTwo.Tuples)
                    {
                        Console.WriteLine(new string(' ', 16) + $"({tuple.Description}" + new string(' ', theLongestWord - tuple.Description.Length) + $", {tuple.Item2})");
                    }
                }

                Console.WriteLine();
            }
        }

        // The description says that the sorting by categories regarding the second grouping should be in ascending order, 
        // but according to the given sample photo it is in descending order. I did it in descending order.
        public static void GroupByQtrCategoryAndProducts()
        {
            var groupByQtrCategoryAndProducts = products
                .GroupBy(p => p.Quarter)
                .Select(groupOne => new
                {
                    Name = groupOne.Key,
                    CategoryProductsGroup = groupOne
                        .GroupBy(p => p.Category)
                        .Select(groupTwo => new
                        {
                            Name = groupTwo.Key,
                            Products = groupTwo
                                .OrderBy(pair => pair.Category)
                                .ToList()
                        })
                        .OrderByDescending(pair => pair.Name)
                        .ToList()
                })
                .OrderBy(pair => pair.Name)
                .ToList();

            foreach (var pair in groupByQtrCategoryAndProducts)
            {
                Console.WriteLine($"Quarter group: {pair.Name}");

                foreach (var pairTwo in pair.CategoryProductsGroup)
                {
                    Console.WriteLine(new string(' ', 8) + $"Category group: {pairTwo.Name}");

                    foreach (var product in pairTwo.Products)
                    {
                        Console.WriteLine(new string(' ', 16) + product);
                    }
                }

                Console.WriteLine();
            }
        }

        public static void GroupByQtrMinMaxPrice()
        {
            var groupByQtrMinMaxPrice = products
                .GroupBy(p => p.Quarter)
                .Select(group => new { Name = group.Key, Products = group.ToList() })
                .OrderBy(pair => pair.Name)
                .ToList();

            foreach (var pair in groupByQtrMinMaxPrice)
            {
                Console.WriteLine($"Quarter group: {pair.Name}");
                Console.WriteLine(new string(' ', 16) + $"Min price per Quarter: ${pair.Products.Min(p => p.Price)}");
                Console.WriteLine(new string(' ', 16) + $"Max price per Quarter: ${pair.Products.Max(p => p.Price)}\n");
            }
        }

        public static void Main(string[] args)
        {
            WriteSubsection("GroupByCategoryCountDescending");
            GroupByCategoryCountDescending();

            WriteSubsection("\nGroupByQtrAndProductPriceAvg");
            GroupByQtrAndProductPriceAvg();

            WriteSubsection("\nGroupByQtrCategoryWeeklySum");
            GroupByQtrCategoryWeeklySum();

            WriteSubsection("\nGroupByQtrCategoryAndProducts");
            GroupByQtrCategoryAndProducts();

            WriteSubsection("\nGroupByQtrMinMaxPrice");
            GroupByQtrMinMaxPrice();
        }
    }
}
