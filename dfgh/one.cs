using System;
using System.Collections.Generic;
using System.Xml;
using System.IO;

namespace practice
{
    // Класс Товар
    public class Product
    {
        public string ProductCode { get; set; }        // код товара
        public string ProductName { get; set; }        // название товара
        public decimal Price { get; set; }             // цена за единицу
        public int Quantity { get; set; }              // количество
        public string Unit { get; set; }               // единица измерения

        public Product() { }

        public Product(string productCode, string productName,
                      decimal price, int quantity, string unit)
        {
            ProductCode = productCode;
            ProductName = productName;
            Price = price;
            Quantity = quantity;
            Unit = unit;
        }

        // Вычисление стоимости товара
        public decimal GetTotalCost()
        {
            return Price * Quantity;
        }

        // Вывод информации о товаре
        public void DisplayInfo()
        {
            Console.WriteLine($"  Код: {ProductCode}");
            Console.WriteLine($"  Название: {ProductName}");
            Console.WriteLine($"  Цена: {Price:C2} за {Unit}");
            Console.WriteLine($"  Количество: {Quantity} {Unit}");
            Console.WriteLine($"  Стоимость: {GetTotalCost():C2}");
        }
    }

    // Класс Заказ
    public class Order
    {
        public string OrderNumber { get; set; }        // номер заказа
        public string CustomerName { get; set; }       // имя заказчика
        public string CustomerPhone { get; set; }      // телефон заказчика
        public string CustomerAddress { get; set; }    // адрес заказчика
        public DateTime OrderDate { get; set; }        // дата заказа
        public string PaymentMethod { get; set; }      // способ оплаты
        public string Status { get; set; }             // статус заказа
        public List<Product> Products { get; set; }    // список товаров

        public Order()
        {
            Products = new List<Product>();
        }

        public Order(string orderNumber, string customerName, string customerPhone,
                    string customerAddress, DateTime orderDate, string paymentMethod,
                    string status)
        {
            OrderNumber = orderNumber;
            CustomerName = customerName;
            CustomerPhone = customerPhone;
            CustomerAddress = customerAddress;
            OrderDate = orderDate;
            PaymentMethod = paymentMethod;
            Status = status;
            Products = new List<Product>();
        }

        // Добавление товара в заказ
        public void AddProduct(Product product)
        {
            Products.Add(product);
        }

        // Вычисление общей суммы заказа
        public decimal GetTotalAmount()
        {
            decimal total = 0;
            foreach (Product product in Products)
            {
                total += product.GetTotalCost();
            }
            return total;
        }

        // Вывод информации о заказе
        public void DisplayInfo()
        {
            Console.WriteLine($"\n=== ЗАКАЗ №{OrderNumber} ===");
            Console.WriteLine($"Заказчик: {CustomerName}");
            Console.WriteLine($"Телефон: {CustomerPhone}");
            Console.WriteLine($"Адрес: {CustomerAddress}");
            Console.WriteLine($"Дата заказа: {OrderDate:dd.MM.yyyy}");
            Console.WriteLine($"Способ оплаты: {PaymentMethod}");
            Console.WriteLine($"Статус: {Status}");
            Console.WriteLine("\nТовары в заказе:");
            Console.WriteLine(new string('-', 50));

            foreach (Product product in Products)
            {
                product.DisplayInfo();
                Console.WriteLine(new string('-', 50));
            }

            Console.WriteLine($"\nИТОГО: {GetTotalAmount():C2}");
            Console.WriteLine("===================================");
        }
    }

    class task
    {
        static void Main()
        {
            Console.WriteLine("=== Работа с XML: заказы и товары ===\n");

            // Создание тестовых данных
            List<Order> orders = CreateTestOrders();

            // 1. Сохранение в XML с помощью XmlTextWriter
            string filePath = "orders.xml";
            SaveOrdersToXml(orders, filePath);
            Console.WriteLine($"\nДанные сохранены в файл: {filePath}");

            // 2. Чтение из XML с помощью XmlTextReader
            Console.WriteLine("\n=== ЧТЕНИЕ ДАННЫХ С ПОМОЩЬЮ XmlTextReader ===");
            List<Order> loadedOrders1 = ReadOrdersWithXmlTextReader(filePath);
            Console.WriteLine($"Прочитано заказов: {loadedOrders1.Count}");
            foreach (Order order in loadedOrders1)
            {
                order.DisplayInfo();
            }

            // 3. Чтение из XML с помощью XmlDocument
            Console.WriteLine("\n=== ЧТЕНИЕ ДАННЫХ С ПОМОЩЬЮ XmlDocument ===");
            List<Order> loadedOrders2 = ReadOrdersWithXmlDocument(filePath);
            Console.WriteLine($"Прочитано заказов: {loadedOrders2.Count}");
            foreach (Order order in loadedOrders2)
            {
                order.DisplayInfo();
            }

            Console.WriteLine("\nНажмите любую клавишу для выхода...");
            Console.ReadKey();
        }

        // Создание тестовых данных
        static List<Order> CreateTestOrders()
        {
            List<Order> orders = new List<Order>();

            // Заказ 1
            Order order1 = new Order(
                "ORD-2024-001",
                "Иванов Иван Иванович",
                "+7 (999) 123-45-67",
                "г. Москва, ул. Примерная, д. 1, кв. 5",
                new DateTime(2024, 6, 15),
                "Наличные",
                "Выполнен"
            );
            order1.AddProduct(new Product("P001", "Ноутбук ASUS", 75000m, 1, "шт."));
            order1.AddProduct(new Product("P002", "Мышь беспроводная", 1500m, 2, "шт."));
            order1.AddProduct(new Product("P003", "Клавиатура", 3500m, 1, "шт."));
            orders.Add(order1);

            // Заказ 2
            Order order2 = new Order(
                "ORD-2024-002",
                "Петрова Мария Сергеевна",
                "+7 (999) 765-43-21",
                "г. Санкт-Петербург, ул. Тестовая, д. 10, кв. 15",
                new DateTime(2024, 6, 16),
                "Банковская карта",
                "В обработке"
            );
            order2.AddProduct(new Product("P004", "Монитор Samsung 27\"", 25000m, 2, "шт."));
            order2.AddProduct(new Product("P005", "Кабель HDMI", 500m, 2, "шт."));
            orders.Add(order2);

            // Заказ 3
            Order order3 = new Order(
                "ORD-2024-003",
                "Сидоров Алексей Дмитриевич",
                "+7 (999) 345-67-89",
                "г. Екатеринбург, ул. Главная, д. 20",
                new DateTime(2024, 6, 17),
                "Оплата при получении",
                "Новый"
            );
            order3.AddProduct(new Product("P006", "Смартфон iPhone", 120000m, 1, "шт."));
            order3.AddProduct(new Product("P007", "Чехол для телефона", 800m, 1, "шт."));
            order3.AddProduct(new Product("P008", "Защитное стекло", 500m, 2, "шт."));
            order3.AddProduct(new Product("P009", "Наушники Bluetooth", 4500m, 1, "шт."));
            orders.Add(order3);

            return orders;
        }

        // Метод сохранения заказов в XML с помощью XmlTextWriter
        static void SaveOrdersToXml(List<Order> orders, string filePath)
        {
            Console.WriteLine("=== СОХРАНЕНИЕ ДАННЫХ В XML (XmlTextWriter) ===");

            try
            {
                XmlTextWriter writer = new XmlTextWriter(filePath, System.Text.Encoding.UTF8);
                writer.Formatting = Formatting.Indented;     // форматирование с отступами
                writer.Indentation = 2;                      // размер отступа
                writer.IndentChar = ' ';                     // символ отступа

                // Начало документа
                writer.WriteStartDocument();

                // Корневой элемент
                writer.WriteStartElement("Orders");
                writer.WriteAttributeString("Created", DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
                writer.WriteAttributeString("Count", orders.Count.ToString());

                // Запись каждого заказа
                foreach (Order order in orders)
                {
                    // Начало элемента Order
                    writer.WriteStartElement("Order");

                    // Атрибуты заказа
                    writer.WriteAttributeString("Number", order.OrderNumber);
                    writer.WriteAttributeString("Date", order.OrderDate.ToString("yyyy-MM-dd"));
                    writer.WriteAttributeString("Status", order.Status);

                    // Информация о заказчике
                    writer.WriteStartElement("Customer");
                    writer.WriteElementString("Name", order.CustomerName);
                    writer.WriteElementString("Phone", order.CustomerPhone);
                    writer.WriteElementString("Address", order.CustomerAddress);
                    writer.WriteEndElement(); // Customer

                    // Информация об оплате
                    writer.WriteStartElement("Payment");
                    writer.WriteElementString("Method", order.PaymentMethod);
                    writer.WriteEndElement(); // Payment

                    // Список товаров
                    writer.WriteStartElement("Products");
                    writer.WriteAttributeString("Count", order.Products.Count.ToString());

                    foreach (Product product in order.Products)
                    {
                        writer.WriteStartElement("Product");

                        writer.WriteAttributeString("Code", product.ProductCode);
                        writer.WriteElementString("Name", product.ProductName);
                        writer.WriteElementString("Price", product.Price.ToString("F2"));
                        writer.WriteElementString("Quantity", product.Quantity.ToString());
                        writer.WriteElementString("Unit", product.Unit);
                        writer.WriteElementString("TotalCost", product.GetTotalCost().ToString("F2"));

                        writer.WriteEndElement(); // Product
                    }

                    writer.WriteEndElement(); // Products

                    // Общая сумма заказа
                    writer.WriteElementString("TotalAmount", order.GetTotalAmount().ToString("F2"));

                    writer.WriteEndElement(); // Order
                }

                writer.WriteEndElement(); // Orders
                writer.WriteEndDocument();
                writer.Close();

                Console.WriteLine($"Успешно сохранено {orders.Count} заказов!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при сохранении XML: {ex.Message}");
            }
        }

        // Метод чтения заказов из XML с помощью XmlTextReader
        static List<Order> ReadOrdersWithXmlTextReader(string filePath)
        {
            List<Order> orders = new List<Order>();
            Order currentOrder = null;
            Product currentProduct = null;
            string currentElement = "";

            try
            {
                XmlTextReader reader = new XmlTextReader(filePath);
                reader.WhitespaceHandling = WhitespaceHandling.None;

                while (reader.Read())
                {
                    switch (reader.NodeType)
                    {
                        case XmlNodeType.Element:
                            currentElement = reader.Name;

                            if (reader.Name == "Order")
                            {
                                currentOrder = new Order();
                                // Чтение атрибутов
                                while (reader.MoveToNextAttribute())
                                {
                                    if (reader.Name == "Number")
                                        currentOrder.OrderNumber = reader.Value;
                                    else if (reader.Name == "Date")
                                        currentOrder.OrderDate = DateTime.Parse(reader.Value);
                                    else if (reader.Name == "Status")
                                        currentOrder.Status = reader.Value;
                                }
                                reader.MoveToElement();
                            }
                            else if (reader.Name == "Product")
                            {
                                currentProduct = new Product();
                                // Чтение атрибутов товара
                                while (reader.MoveToNextAttribute())
                                {
                                    if (reader.Name == "Code")
                                        currentProduct.ProductCode = reader.Value;
                                }
                                reader.MoveToElement();
                            }
                            break;

                        case XmlNodeType.Text:
                            // Заполнение полей в зависимости от текущего элемента
                            if (currentOrder != null)
                            {
                                switch (currentElement)
                                {
                                    case "Name":
                                        if (currentProduct != null)
                                            currentProduct.ProductName = reader.Value;
                                        else
                                            currentOrder.CustomerName = reader.Value;
                                        break;
                                    case "Phone":
                                        currentOrder.CustomerPhone = reader.Value;
                                        break;
                                    case "Address":
                                        currentOrder.CustomerAddress = reader.Value;
                                        break;
                                    case "Method":
                                        currentOrder.PaymentMethod = reader.Value;
                                        break;
                                    case "Price":
                                        if (currentProduct != null)
                                            currentProduct.Price = decimal.Parse(reader.Value);
                                        break;
                                    case "Quantity":
                                        if (currentProduct != null)
                                            currentProduct.Quantity = int.Parse(reader.Value);
                                        break;
                                    case "Unit":
                                        if (currentProduct != null)
                                            currentProduct.Unit = reader.Value;
                                        break;
                                }
                            }
                            break;

                        case XmlNodeType.EndElement:
                            if (reader.Name == "Product" && currentOrder != null && currentProduct != null)
                            {
                                currentOrder.AddProduct(currentProduct);
                                currentProduct = null;
                            }
                            else if (reader.Name == "Order" && currentOrder != null)
                            {
                                orders.Add(currentOrder);
                                currentOrder = null;
                            }
                            currentElement = "";
                            break;
                    }
                }

                reader.Close();
                Console.WriteLine($"Прочитано {orders.Count} заказов с помощью XmlTextReader");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при чтении XML (XmlTextReader): {ex.Message}");
            }

            return orders;
        }

        // Метод чтения заказов из XML с помощью XmlDocument
        static List<Order> ReadOrdersWithXmlDocument(string filePath)
        {
            List<Order> orders = new List<Order>();

            try
            {
                XmlDocument doc = new XmlDocument();
                doc.Load(filePath);

                // Получение всех заказов
                XmlNodeList orderNodes = doc.SelectNodes("//Order");

                foreach (XmlNode orderNode in orderNodes)
                {
                    Order order = new Order
                    {
                        OrderNumber = orderNode.Attributes["Number"]?.Value,
                        OrderDate = DateTime.Parse(orderNode.Attributes["Date"]?.Value),
                        Status = orderNode.Attributes["Status"]?.Value,
                        CustomerName = orderNode.SelectSingleNode("Customer/Name")?.InnerText,
                        CustomerPhone = orderNode.SelectSingleNode("Customer/Phone")?.InnerText,
                        CustomerAddress = orderNode.SelectSingleNode("Customer/Address")?.InnerText,
                        PaymentMethod = orderNode.SelectSingleNode("Payment/Method")?.InnerText
                    };

                    // Получение товаров заказа
                    XmlNodeList productNodes = orderNode.SelectNodes("Products/Product");

                    foreach (XmlNode productNode in productNodes)
                    {
                        Product product = new Product
                        {
                            ProductCode = productNode.Attributes["Code"]?.Value,
                            ProductName = productNode.SelectSingleNode("Name")?.InnerText,
                            Price = decimal.Parse(productNode.SelectSingleNode("Price")?.InnerText ?? "0"),
                            Quantity = int.Parse(productNode.SelectSingleNode("Quantity")?.InnerText ?? "0"),
                            Unit = productNode.SelectSingleNode("Unit")?.InnerText
                        };

                        order.AddProduct(product);
                    }

                    orders.Add(order);
                }

                Console.WriteLine($"Прочитано {orders.Count} заказов с помощью XmlDocument");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при чтении XML (XmlDocument): {ex.Message}");
            }

            return orders;
        }
    }
}