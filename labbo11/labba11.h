#ifndef LABBA11_H
#define LABBA11_H

#include <QGLWidget> [cite: 317]
#include <QTimer>

class labba11 : public QGLWidget [cite: 319]
{
    Q_OBJECT

public:
    labba11(QWidget *parent = nullptr);
    ~labba11();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private slots:
    void updatePhysics();

private:
    QTimer *timer;      // Таймер для анимации
    float ballX, ballY; // Текущие координаты центра шарика
    float speedX, speedY; // Скорость перемещения по осям
    float radius;       // Радиус шарика
    float boxSize;      // Половина размера квадратного контура
};

#endif // LABBA11_H
