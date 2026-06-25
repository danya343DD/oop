using System;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Questionnaire
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void AgeBox_PreviewTextInput(object sender,
                                             TextCompositionEventArgs e)
        {
            // только цифры
            if (!char.IsDigit(e.Text, e.Text.Length - 1))
            {
                e.Handled = true;
            }
        }

        private void ShowResultButton_Click(object sender, RoutedEventArgs e)
        {
            // Проверка ФИО
            if (string.IsNullOrWhiteSpace(FullNameBox.Text))
            {
                MessageBox.Show("Введите ФИО!", "Ошибка",
                              MessageBoxButton.OK,
                              MessageBoxImage.Warning);
                FullNameBox.Focus();
                return;
            }

            // Проверка возраста
            if (string.IsNullOrWhiteSpace(AgeBox.Text))
            {
                MessageBox.Show("Введите возраст!", "Ошибка",
                              MessageBoxButton.OK,
                              MessageBoxImage.Warning);
                AgeBox.Focus();
                return;
            }

            // результат
            StringBuilder result = new StringBuilder();

            result.AppendLine("═══════════════════════════");
            result.AppendLine("       РЕЗУЛЬТАТ АНКЕТЫ");
            result.AppendLine("═══════════════════════════");
            result.AppendLine();

            // ФИО
            result.AppendLine($"ФИО: {FullNameBox.Text.Trim()}");

            // Возраст
            result.AppendLine($"Возраст: {AgeBox.Text.Trim()} лет");

            // Пол
            string gender = "Не указан";
            if (MaleRadio.IsChecked == true)
                gender = "Мужской";
            else if (FemaleRadio.IsChecked == true)
                gender = "Женский";
            result.AppendLine($"Пол: {gender}");

            // Образование
            string education = "Не выбрано";
            if (EducationCombo.SelectedItem is ComboBoxItem selectedItem)
                education = selectedItem.Content.ToString();
            result.AppendLine($"Образование: {education}");

            // Хобби
            result.AppendLine();
            result.AppendLine("Хобби:");

            bool hasHobbies = false;

            if (SportCheck.IsChecked == true)
            {
                result.AppendLine("  • Спорт");
                hasHobbies = true;
            }
            if (MusicCheck.IsChecked == true)
            {
                result.AppendLine("  • Музыка");
                hasHobbies = true;
            }
            if (ReadingCheck.IsChecked == true)
            {
                result.AppendLine("  • Чтение");
                hasHobbies = true;
            }
            if (TravelCheck.IsChecked == true)
            {
                result.AppendLine("  • Путешествия");
                hasHobbies = true;
            }
            if (ProgrammingCheck.IsChecked == true)
            {
                result.AppendLine("  • Программирование");
                hasHobbies = true;
            }

            if (!hasHobbies)
                result.AppendLine("  • Не указаны");

            result.AppendLine();
            result.AppendLine("═══════════════════════════");
            result.AppendLine($"Дата: {DateTime.Now:dd.MM.yyyy HH:mm}");

            // результат в отдельном окне сообщения
            MessageBox.Show(result.ToString(), "Результат анкеты",
                          MessageBoxButton.OK,
                          MessageBoxImage.Information);
        }
    }
}