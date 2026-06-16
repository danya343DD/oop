using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace practice
{
    class Program
    {
        [DllImport("user32.dll")]
        private static extern IntPtr GetDC(IntPtr hwnd);

        [DllImport("user32.dll")]
        private static extern int ReleaseDC(IntPtr hwnd, IntPtr hdc);

        [DllImport("gdi32.dll")]
        private static extern int GetDeviceCaps(IntPtr hdc, int nIndex);

        private const int HORZSIZE = 4;
        private const int VERTSIZE = 6;

        static void Main()
        {
            Console.WriteLine("=== Определение размера диагонали монитора ===\n");

            try
            {
                // Получаем контекст устройства
                IntPtr hdc = GetDC(IntPtr.Zero);

                // Получаем размеры в миллиметрах
                int widthMM = GetDeviceCaps(hdc, HORZSIZE);
                int heightMM = GetDeviceCaps(hdc, VERTSIZE);

                ReleaseDC(IntPtr.Zero, hdc);

                // Вычисляем диагональ
                double diagonalMM = Math.Sqrt(widthMM * widthMM + heightMM * heightMM);
                double diagonalInches = diagonalMM / 25.4;

                // Вывод результатов
                Console.WriteLine($"Ширина экрана: {widthMM} мм ({widthMM / 25.4:F1} дюймов)");
                Console.WriteLine($"Высота экрана: {heightMM} мм ({heightMM / 25.4:F1} дюймов)");
                Console.WriteLine($"\nДиагональ монитора: {diagonalInches:F1} дюймов");

                // Определение типа монитора
                string monitorType = GetMonitorType(diagonalInches);
                Console.WriteLine($"Тип монитора: {monitorType}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }

            Console.WriteLine("\nНажмите любую клавишу для выхода...");
            Console.ReadKey();
        }

        static string GetMonitorType(double inches)
        {
            if (inches < 15) return "Маленький монитор (менее 15\")";
            else if (inches < 19) return "Стандартный монитор (15-19\")";
            else if (inches < 24) return "Средний монитор (19-24\")";
            else if (inches < 30) return "Большой монитор (24-30\")";
            else return "Очень большой монитор (более 30\")";
        }
    }
}