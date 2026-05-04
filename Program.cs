//1
using System;

class Task1
{
    static void Main()
    {
        int[] arr = { 1, 0, 2, 0, 3, 0, 4, 5, 0 };
        Console.WriteLine("Исходный массив: " + string.Join(", ", arr));

        int nonZeroIndex = 0;


        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] != 0)
            {
                arr[nonZeroIndex] = arr[i];
                nonZeroIndex++;
            }
        }


        for (int i = nonZeroIndex; i < arr.Length; i++)
        {
            arr[i] = -1;
        }

        Console.WriteLine("Сжатый массив:   " + string.Join(", ", arr));
    }
}

//2
class Task2
{
    static void Main()
    {
        int[] arr = { 5, -3, 0, 8, -1, -4, 2, 0 };
        Console.WriteLine("Исходный массив:       " + string.Join(", ", arr));

        int[] transformed = new int[arr.Length];
        int index = 0;


        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] < 0)
            {
                transformed[index++] = arr[i];
            }
        }


        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] >= 0)
            {
                transformed[index++] = arr[i];
            }
        }

        Console.WriteLine("Преобразованный массив: " + string.Join(", ", transformed));
    }
}

//3
class Task3
{
    static void Main()
    {
        int[] arr = { 1, 5, 3, 5, 8, 5, 2, 9 };
        Console.WriteLine("Массив: " + string.Join(", ", arr));

        Console.Write("Введите число для поиска: ");
        if (int.TryParse(Console.ReadLine(), out int searchNum))
        {
            int count = 0;

            foreach (int num in arr)
            {
                if (num == searchNum)
                {
                    count++;
                }
            }
            Console.WriteLine($"Число {searchNum} встречается в массиве {count} раз(а).");
        }
        else
        {
            Console.WriteLine("Ошибка: Введено некорректное число.");
        }
    }
}

//4
class Task4
{
    static void Main()
    {

        int[,] arr = {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 }
        };

        int M = arr.GetLength(0);
        int N = arr.GetLength(1);

        Console.WriteLine("Исходный двумерный массив:");
        PrintArray(arr);


        int col1 = 0;
        int col2 = 3;

        if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N)
        {

            for (int i = 0; i < M; i++)
            {
                int temp = arr[i, col1];
                arr[i, col1] = arr[i, col2];
                arr[i, col2] = temp;
            }

            Console.WriteLine($"\nМассив после обмена {col1}-го и {col2}-го столбцов:");
            PrintArray(arr);
        }
        else
        {
            Console.WriteLine("Указаны неверные индексы столбцов!");
        }
    }


    static void PrintArray(int[,] arr)
    {
        for (int i = 0; i < arr.GetLength(0); i++)
        {
            for (int j = 0; j < arr.GetLength(1); j++)
            {
                Console.Write(arr[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}