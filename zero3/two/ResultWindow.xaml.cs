using System.Windows;

namespace Questionnaire  // Пространство имён должно совпадать с основным окном
{
    public partial class ResultWindow : Window
    {
        public ResultWindow(string resultText)  // Конструктор с параметром
        {
            InitializeComponent();
            ResultTextBox.Text = resultText;
        }

        private void CloseButton_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}