#ifndef LABBA10_H
#define LABBA10_H

#include <QWidget>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class labba10; }
QT_END_NAMESPACE

class labba10 : public QWidget
{
    Q_OBJECT

public:
    labba10(QWidget *parent = nullptr);
    ~labba10();

protected:
    // Переопределенный метод для отрисовки часов (Задание 2)
    void paintEvent(QPaintEvent *event) override;

private slots:
    // Слот для кнопки генерации случайных чисел (Задание 1)
    void on_generateButton_clicked();

private:
    Ui::labba10 *ui;
    QTimer *timer; // Таймер для обновления стрелки часов
};

#endif