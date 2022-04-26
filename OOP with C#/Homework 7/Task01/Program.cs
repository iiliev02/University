using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkSeven
{
    public class Program
    {
        public static void Main(string[] args)
        {
            List<Product> productsOne = new List<Product>() { new Product("Desktop computer", 1) };
            Store storeOne = new Store(productsOne);
            FirstStoreInitialization(storeOne);

            Console.WriteLine("Test appointment: ");
            Manager manager = new Manager("Ivan");
            Employee worker = new Employee("Dahlia");
            storeOne.OnAppointment(worker);
            storeOne.OnAppointment(manager);

            Console.WriteLine("\nTest change in product list: ");
            storeOne.ListOfProducts = new List<Product>() { new Product("Desktop computer", 3) };

            Console.WriteLine($"\nShow products in {storeOne.STORE_NAME}: ");
            storeOne.ShowProducts();

            Console.WriteLine("Test Quantity updates: ");
            worker.ManageQty(storeOne.ListOfProducts[0], 10);
            worker.ManageQty(storeOne.ListOfProducts[0], 100);

            Console.WriteLine("\nCreate a second store: ");
            List<Product> productsTwo = new List<Product>() { new Product("Christmas tree", 2) };
            Store storeTwo = new Store(productsTwo);
            FirstStoreInitialization(storeTwo);
        }

        private static void FirstStoreInitialization(Store store)
        {
            Console.WriteLine($"{store.STORE_NAME}: New list of products assigned to store.");
            store.ShowProducts();
        }
    }
}
