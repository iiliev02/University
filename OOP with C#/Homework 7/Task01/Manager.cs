using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkSeven
{
    public class Manager : Employee
    {
        internal void ManageProductQuantity(object sender, PropertyChangedEventArgs args)
        {
            Console.WriteLine("StoreManagement.Manager");
            Console.WriteLine($"Product {args.PropertyName} quantity changed!");
        }

        public Manager(string name) : base(name) { }

        public override void GetAppointed(object sender, EventArgs args)
        {
            base.GetAppointed(sender, args);
        }

        public override string ToString()
        {
            return $"Manager name: {Name} | Store: {WorksAt.STORE_NAME}";
        }
    }
}
