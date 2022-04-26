using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkSeven
{
    public class Employee : EventArgs
    {
        private string name;
        private Store worksAt;

        public string Name { get; set; }
        public Store WorksAt { get; set; }

        public Employee(string name)
        {
            Name = name;
        }

        public void ManageQty(Product p, int qty)
        {
            int indexOfProduct = worksAt.ListOfProducts.IndexOf(p);

            if (indexOfProduct != -1)
            {
                worksAt.OnUpdateQuantity(indexOfProduct, qty);
            }
            else
            {
                Console.WriteLine("The product you want to change has not been found!");
                Environment.Exit(0);
            }
        }

        internal void ManageListOfProducts(object sender, PropertyChangedEventArgs args)
        {
            Console.WriteLine($"StoreManagement.{GetType().Name}");
            Console.WriteLine($"{args.PropertyName} list changed!");
        }

        public virtual void GetAppointed(object sender, EventArgs args)
        {
            worksAt = (Store)sender;
            Console.WriteLine($"{GetType().Name} in {worksAt.STORE_NAME}");
        }

        public override string ToString()
        {
            return $"Employee name: {name} | Store: {worksAt.STORE_NAME}";
        }
    }
}
