using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeworkSeven
{
    public class Product
    {
        private string description;
        private int quantity;
        
        public string Description
        {
            get => description;
            set => description = string.IsNullOrEmpty(value) ? "UNKNOWN" : value;
        }
        public int Quantity
        {
            get => quantity;
            set => quantity = value < 0 ? 0 : value;
        }

        public Product() : this("Christmas tree", 10) { }

        public Product(string description, int quantity)
        {
            Description = description;
            Quantity = quantity;
        }

        public Product(Product product) : this(product.Description, product.Quantity) { }

        public override string ToString()
        {
            return $"Product: {description}, Quantity: {quantity}";
        }
    }    
}
