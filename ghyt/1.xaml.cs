using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Diagnostics;

namespace KeyboardTrainer
{
    public partial class MainWindow : Window
    {
        private Dictionary<string, Button> keyButtons = new Dictionary<string, Button>();
        private string targetString = "";
        private int currentPosition = 0;
        private int errorCount = 0;
        private Stopwatch timer = new Stopwatch();
        private bool isTraining = false;
        private bool shiftPressed = false;
        private bool capsLockOn = false;

        // Раскладки для разных состояний
        private string[][] normalKeys = new string[][]
        {
            new[] { "`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "←" },
            new[] { "Tab", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\" },
            new[] { "Caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "Enter" },
            new[] { "Shift", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "Shift" },
            new[] { "Space" }
        };

        private string[][] shiftKeys = new string[][]
        {
            new[] { "~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "←" },
            new[] { "Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|" },
            new[] { "Caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "Enter" },
            new[] { "Shift", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "Shift" },
            new[] { "Space" }
        };

        public MainWindow()
        {
            InitializeComponent();
            CreateKeyboard();

            // Привязка события ползунка
            ComplexitySlider.ValueChanged += (s, e) =>
                ComplexityValue.Text = ((int)ComplexitySlider.Value).ToString();
        }

        private void CreateKeyboard()
        {
            KeyboardPanel.Children.Clear();
            keyButtons.Clear();

            string[][] keys = GetCurrentLayout();

            foreach (string[] row in keys)
            {
                StackPanel rowPanel = new StackPanel
                {
                    Orientation = Orientation.Horizontal,
                    HorizontalAlignment = HorizontalAlignment.Center,
                    Margin = new Thickness(0, 2, 0, 2)
                };

                foreach (string key in row)
                {
                    Button btn = new Button
                    {
                        Content = key,
                        Width = key == "Space" ? 300 : (key.Length > 1 ? 55 : 45),
                        Height = 45,
                        Margin = new Thickness(2),
                        Background = new SolidColorBrush(Colors.White),
                        Foreground = new SolidColorBrush(Colors.Black),
                        FontSize = key.Length > 1 ? 10 : 14,
                        IsEnabled = false  // Неинтерактивные клавиши
                    };

                    // Особые клавиши
                    if (key == "Space")
                        btn.Content = "";
                    if (key == "←")
                        btn.Content = "Backspace";

                    string keyCode = GetKeyCode(key);
                    if (!keyButtons.ContainsKey(keyCode))
                        keyButtons[keyCode] = btn;

                    rowPanel.Children.Add(btn);
                }

                KeyboardPanel.Children.Add(rowPanel);
            }
        }

        private string[][] GetCurrentLayout()
        {
            // Выбор раскладки в зависимости от Shift и Caps Lock
            if (shiftPressed ^ capsLockOn)
                return shiftKeys;
            return normalKeys;
        }

        private string GetKeyCode(string displayText)
        {
            // Преобразование отображаемого символа в код клавиши
            switch (displayText.ToLower())
            {
                case "tab": return "Tab";
                case "caps": return "CapsLock";
                case "enter": return "Enter";
                case "shift": return "Shift";
                case "space": return "Space";
                case "←": return "Back";
                default: return displayText;
            }
        }

        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            if (!isTraining) return;

            // Сначала обрабатываем модификаторы
            if (e.Key == Key.LeftShift || e.Key == Key.RightShift)
            {
                shiftPressed = true;
                UpdateKeyboardLayout();
                return;
            }

            if (e.Key == Key.CapsLock)
            {
                capsLockOn = !capsLockOn;
                UpdateKeyboardLayout();
                return;
            }

            // Подсветка клавиши
            string keyCode = GetKeyCodeFromEventArgs(e);
            HighlightKey(keyCode, true);

            // Игнорируем специальные клавиши
            if (e.Key == Key.Back)
            {
                if (currentPosition > 0)
                {
                    currentPosition--;
                    UpdateUserInputDisplay();
                    ResetErrorHighlight();
                }
                return;
            }

            // Игнорируем Tab, Enter и другие управляющие клавиши
            if (e.Key == Key.Tab || e.Key == Key.Enter ||
                e.Key == Key.Escape || e.Key == Key.LeftCtrl ||
                e.Key == Key.RightCtrl || e.Key == Key.LeftAlt ||
                e.Key == Key.RightAlt || e.Key == Key.LWin || e.Key == Key.RWin)
                return;

            // Получаем ожидаемый символ
            if (currentPosition >= targetString.Length) return;
            string expectedChar = targetString[currentPosition].ToString();

            // Получаем введённый символ (с учётом Shift и CapsLock)
            string inputChar = GetCharFromKey(e.Key, shiftPressed, capsLockOn);

            // Если символ не определён - пропускаем
            if (string.IsNullOrEmpty(inputChar)) return;

            // Сравниваем
            if (inputChar == expectedChar)
            {
                currentPosition++;
                UpdateUserInputDisplay();
                ResetErrorHighlight();

                // Проверка на завершение
                if (currentPosition >= targetString.Length)
                {
                    StopTraining();
                    MessageBox.Show("Отлично! Вы завершили упражнение!",
                                  "Успех", MessageBoxButton.OK,
                                  MessageBoxImage.Information);
                }
            }
            else
            {
                errorCount++;
                ErrorsText.Text = errorCount.ToString();
                HighlightError();
            }

            UpdateSpeed();
        }

        // Вспомогательный метод для получения кода клавиши
        private string GetKeyCodeFromEventArgs(KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.LeftShift:
                case Key.RightShift:
                    return "Shift";
                case Key.CapsLock:
                    return "CapsLock";
                case Key.Back:
                    return "Back";
                case Key.Space:
                    return "Space";
                case Key.Tab:
                    return "Tab";
                case Key.Enter:
                    return "Enter";
                default:
                    return e.Key.ToString();
            }
        }

        // Сброс подсветки ошибки
        private void ResetErrorHighlight()
        {
            // Восстанавливаем обычное отображение
            TargetText.Text = targetString;
        }

        // Улучшенный метод подсветки ошибки
        private void HighlightError()
        {
            if (currentPosition < targetString.Length)
            {
                string before = targetString.Substring(0, currentPosition);
                string error = targetString[currentPosition].ToString();
                string after = targetString.Substring(currentPosition + 1);

                TargetText.Text = before + "[" + error + "]" + after;
            }
        }

        private void Window_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.LeftShift || e.Key == Key.RightShift)
            {
                shiftPressed = false;
                UpdateKeyboardLayout();
            }

            string releasedKey = e.Key.ToString();
            HighlightKey(releasedKey, false);
        }

        private void HighlightKey(string keyCode, bool highlight)
        {
            if (keyButtons.ContainsKey(keyCode))
            {
                keyButtons[keyCode].Background = highlight ?
                    new SolidColorBrush(Colors.Yellow) :
                    new SolidColorBrush(Colors.White);
            }
        }


        private string GetCharFromKey(Key key, bool shift, bool capsLock)
        {
            // Буквы A-Z
            if (key >= Key.A && key <= Key.Z)
            {
                char c = (char)('A' + (key - Key.A));
                bool upperCase = shift ^ capsLock; // XOR: если shift или capsLock (но не оба)
                return upperCase ? c.ToString() : c.ToString().ToLower();
            }

            // Цифры и символы над ними
            if (key >= Key.D0 && key <= Key.D9)
            {
                string[] numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
                string[] symbols = { ")", "!", "@", "#", "$", "%", "^", "&", "*", "(" };

                int index = key - Key.D0;
                return shift ? symbols[index] : numbers[index];
            }

            // NumPad цифры
            if (key >= Key.NumPad0 && key <= Key.NumPad9)
                return (key - Key.NumPad0).ToString();

            // Специальные клавиши
            switch (key)
            {
                case Key.OemSemicolon:    // ; и :
                    return shift ? ":" : ";";
                case Key.OemQuotes:       // ' и "
                    return shift ? "\"" : "'";
                case Key.OemComma:        // , и <
                    return shift ? "<" : ",";
                case Key.OemPeriod:       // . и >
                    return shift ? ">" : ".";
                case Key.OemMinus:        // - и _
                    return shift ? "_" : "-";
                case Key.OemPlus:         // = и +
                    return shift ? "+" : "=";
                case Key.OemOpenBrackets: // [ и {
                    return shift ? "{" : "[";
                case Key.OemCloseBrackets:// ] и }
                    return shift ? "}" : "]";
                case Key.OemPipe:         // \ и |
                    return shift ? "|" : "\\";
                case Key.OemTilde:        // ` и ~
                    return shift ? "~" : "`";
                case Key.OemQuestion:     // / и ?
                    return shift ? "?" : "/";
                case Key.Space:
                    return " ";
                default:
                    return ""; // Неизвестная клавиша
            }
        }

        private void UpdateKeyboardLayout()
        {
            // Обновление всех кнопок клавиатуры
            string[][] keys = GetCurrentLayout();

            // Перебор всех рядов и кнопок для обновления контента
            int rowIndex = 0;
            foreach (object child in KeyboardPanel.Children)
            {
                if (child is StackPanel rowPanel && rowIndex < keys.Length)
                {
                    int colIndex = 0;
                    foreach (object btn in rowPanel.Children)
                    {
                        if (btn is Button button && colIndex < keys[rowIndex].Length)
                        {
                            button.Content = keys[rowIndex][colIndex];
                            colIndex++;
                        }
                    }
                    rowIndex++;
                }
            }
        }

        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            // Генерация строки
            int length = (int)ComplexitySlider.Value;
            bool caseSensitive = CaseSensitive.IsEnabled;

            targetString = GenerateRandomString(length, caseSensitive);
            TargetText.Text = targetString;

            currentPosition = 0;
            errorCount = 0;
            ErrorsText.Text = "0";
            UserInputText.Text = "";

            timer.Restart();
            isTraining = true;

            StartButton.IsEnabled = false;
            StopButton.IsEnabled = true;
            ComplexitySlider.IsEnabled = false;
            CaseSensitive.IsEnabled = false;
        }

        private void StopButton_Click(object sender, RoutedEventArgs e)
        {
            StopTraining();
        }

        private void StopTraining()
        {
            timer.Stop();
            isTraining = false;

            StartButton.IsEnabled = true;
            StopButton.IsEnabled = false;
            ComplexitySlider.IsEnabled = true;
            CaseSensitive.IsEnabled = true;
        }

        private string GenerateRandomString(int length, bool caseSensitive)
        {
            string chars = "abcdefghijklmnopqrstuvwxyz0123456789,./;'[]\\-=";
            if (caseSensitive)
                chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+{}|:<>?";

            Random rand = new Random();
            char[] result = new char[length];

            for (int i = 0; i < length; i++)
                result[i] = chars[rand.Next(chars.Length)];

            return new string(result);
        }

        private void UpdateUserInputDisplay()
        {
            if (currentPosition <= targetString.Length)
            {
                UserInputText.Text = targetString.Substring(0, currentPosition);
            }
        }

        private void UpdateSpeed()
        {
            if (timer.Elapsed.TotalMinutes > 0)
            {
                double speed = currentPosition / timer.Elapsed.TotalMinutes;
                SpeedText.Text = $"{speed:F0} зн/мин";
            }
        }
    }
}