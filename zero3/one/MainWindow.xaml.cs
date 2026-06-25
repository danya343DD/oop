using System;
using System.IO;
using System.Threading.Tasks;
using System.Windows;

namespace FileReaderProgress
{
    public partial class MainWindow : Window
    {
        private string selectedFilePath = "";
        private bool isReading = false;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void BrowseButton_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.OpenFileDialog
            {
                Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*",
                Title = "Выберите текстовый файл"
            };

            if (dialog.ShowDialog() == true)
            {
                selectedFilePath = dialog.FileName;
                FileNameText.Text = System.IO.Path.GetFileName(selectedFilePath);

                // Получаем информацию о файле
                FileInfo fileInfo = new FileInfo(selectedFilePath);
                TotalCharsText.Text = fileInfo.Length.ToString();

                // Считаем строки
                int totalLines = File.ReadAllLines(selectedFilePath).Length;
                TotalLinesText.Text = totalLines.ToString();

                ReadButton.IsEnabled = true;

                // Сброс прогресса
                ReadProgressBar.Value = 0;
                PercentText.Text = "0%";
                ReadCharsText.Text = "0";
                ReadLinesText.Text = "0";
            }
        }

        private async void ReadButton_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(selectedFilePath) || isReading)
                return;

            isReading = true;
            BrowseButton.IsEnabled = false;
            ReadButton.IsEnabled = false;

            try
            {
                await ReadFileAsync(selectedFilePath);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка при чтении файла: {ex.Message}",
                               "Ошибка", MessageBoxButton.OK,
                               MessageBoxImage.Error);
            }
            finally
            {
                isReading = false;
                BrowseButton.IsEnabled = true;
                ReadButton.IsEnabled = true;
            }
        }

        private async Task ReadFileAsync(string filePath)
        {
            FileInfo fileInfo = new FileInfo(filePath);
            long totalBytes = fileInfo.Length;
            long readBytes = 0;
            int readLines = 0;

            using (StreamReader reader = new StreamReader(filePath))
            {
                string line;
                while ((line = await reader.ReadLineAsync()) != null)
                {
                    // Имитируем задержку для наглядности прогресса
                    await Task.Delay(10);

                    readBytes += System.Text.Encoding.UTF8.GetByteCount(line) +
                                 Environment.NewLine.Length;
                    readLines++;

                    // Обновляем прогресс в UI-потоке
                    await Dispatcher.InvokeAsync(() =>
                    {
                        double progress = (double)readBytes / totalBytes * 100;
                        if (progress > 100) progress = 100;

                        ReadProgressBar.Value = progress;
                        PercentText.Text = $"{progress:F0}%";
                        ReadCharsText.Text = readBytes.ToString();
                        ReadLinesText.Text = readLines.ToString();
                    });
                }
            }

            // Финальное обновление
            await Dispatcher.InvokeAsync(() =>
            {
                ReadProgressBar.Value = 100;
                PercentText.Text = "100%";
                ReadCharsText.Text = totalBytes.ToString();
                ReadLinesText.Text = readLines.ToString();

                MessageBox.Show("Чтение файла завершено!", "Готово",
                              MessageBoxButton.OK,
                              MessageBoxImage.Information);
            });
        }
    }
}