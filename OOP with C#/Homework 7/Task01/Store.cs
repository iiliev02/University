using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkSeven
{
    public class Store : INotifyPropertyChanged
    {
        private static int counter = 1;
        private List<Product> listOfProducts;
        private Manager manager;
        private Employee worker;
        public readonly string STORE_NAME;

        public event EventHandler Appoint;
        public event PropertyChangedEventHandler PropertyChanged;

        public List<Product> ListOfProducts
        {
            get => listOfProducts;
            set
            {
                listOfProducts = value.Select(product => new Product(product)).ToList();
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ListOfProducts")); 
                PropertyChanged = null;
            }
        }

        public Employee Worker
        {
            get => worker;
            set => worker = value ?? new Employee("Emma");
        }

        public void OnAppointment(Employee employee)
        {
            if (employee is Manager castManager)
            {
                manager = castManager;
                Appoint += manager.GetAppointed;
                PropertyChanged += manager.ManageListOfProducts;
            }
            else
            {
                Worker = employee;
                Appoint += worker.GetAppointed;
                PropertyChanged += worker.ManageListOfProducts;
            }

            Appoint?.Invoke(this, employee);
            Appoint -= employee.GetAppointed;
        }

        public void OnUpdateQuantity(int index, int newQty)
        {
            PropertyChanged += manager.ManageProductQuantity;

            Console.WriteLine("Quantity changed...");
            Console.Write($"{listOfProducts[index].Description}: Old quantity: {listOfProducts[index].Quantity} | ");
            listOfProducts[index].Quantity = newQty;
            Console.WriteLine($"New quantity: {listOfProducts[index].Quantity}");

            PropertyChanged?.Invoke(worker, new PropertyChangedEventArgs("ProductQuantity"));
            PropertyChanged -= manager.ManageProductQuantity;
        }

        public Store(List<Product> listOfProducts)
        {
            STORE_NAME = $"Store {counter++}";
            ListOfProducts = listOfProducts;
        }

        public void ShowProducts()
        {
            Console.WriteLine(string.Join("\n", listOfProducts));
            Console.WriteLine();
        }

        public override string ToString()
        {
            return $"Name: {STORE_NAME} | Manager: {manager.Name}";
        }
    }
}
