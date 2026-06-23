#include "labba10.h"
#include "ui_labba10.h"
#include <QPainter>
#include <QVector>
#include <QString>
#include <algorithm>
#include <random>
#include <chrono>

labba10::labba10(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::labba10)
{
    ui->setupUi(this);

    // Инициализируем таймер для секундной стрелки (срабатывание раз в 1 сек)
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QWidget::update));
    timer->start(1000);
}

labba10::~labba10()
{
    delete ui;
}

// ЗАДАНИЕ 1: Генерация чисел от 1 до 20 без повторений
void labba10::on_generateButton_clicked()
{
    QVector<int> numbers;

    // Заполняем вектор последовательными числами
    for(int i = 1; i <= 20; ++i) {
        numbers.append(i);
    }

    // Перемешиваем числа случайным образом с использованием временного зерна
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    std::shuffle(numbers.begin(), numbers.end(), engine);

    // Выводим результат через запятую
    QString result;
    for(int i = 0; i < numbers.size(); ++i) {
        result += QString::number(numbers[i]);
        if (i != numbers.size() - 1) {
            result += ", ";
        }
    }

    // Установите на форме QLabel с именем labelResult
    ui->labelResult->setText(result);
}

// ЗАДАНИЕ 2: Имитация работы секундной стрелки аналоговых часов
void labba10::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // Сглаживание линий

    int side = qMin(width(), height());

    // Переносим центр координат в центр виджета
    painter.translate(width() / 2, height() / 2);
    // Масштабируем, чтобы часы корректно растягивались при изменении окна
    painter.scale(side / 200.0, side / 200.0);

    QTime time = QTime::currentTime();

    // 1. Отрисовка делений циферблата
    painter.save();
    QPen penB(Qt::black);
    penB.setWidth(2);
    painter.setPen(penB);

    for (int i = 0; i < 60; ++i) {
        if ((i % 5) != 0) {
            painter.drawLine(92, 0, 96, 0);
        } else {
            painter.drawLine(86, 0, 96, 0);
        }
        painter.rotate(6.0);
    }
    painter.restore();

    // 2. Отрисовка секундной стрелки
    painter.save();
    QPen penR(Qt::red);
    penR.setWidth(2);
    painter.setPen(penR);

    // Поворачиваем холст на угол, соответствующий текущей секунде
    painter.rotate(6.0 * time.second());

    // Рисуем вертикальную стрелку (от оси вниз на 10px, вверх на 90px)
    painter.drawLine(0, 10, 0, -90);
    painter.restore();

    // Маленький красный кружок по центру (крепление стрелки)
    painter.setBrush(Qt::red);
    painter.drawEllipse(-3, -3, 6, 6);
}