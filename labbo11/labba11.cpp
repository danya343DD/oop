#include "labba11.h"
#include <cmath>

labba11::labba11(QWidget *parent) : QGLWidget(parent) [cite: 366, 367]
{
    // Начальные параметры физической модели
    ballX = 0.0f;
    ballY = 0.0f;
    speedX = 1.8f;
    speedY = 1.3f;
    radius = 7.0f;
    boxSize = 85.0f; // Стенки контура будут находиться на координатах -85 и +85

    // Настройка таймера анимации (интервал 16 мс обеспечивает ~60 кадров в секунду)
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &labba11::updatePhysics);
    timer->start(16);
}

labba11::~labba11()
{
    delete timer;
}

void labba11::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); [cite: 372, 564]
}

void labba11::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h); [cite: 412, 568]

        glMatrixMode(GL_PROJECTION); [cite: 373, 565]
        glLoadIdentity(); [cite: 374, 567]

        // Задаем ортографическую (плоскую) проекцию от -100 до 100 по X и Y
        glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW); [cite: 376]
        glLoadIdentity(); [cite: 377]
}

void labba11::paintGL()
{
    // Очищаем буфер кадра [cite: 381, 569]
    glClear(GL_COLOR_BUFFER_BIT); [cite: 381, 569]
        glLoadIdentity();

    // 1. ОТРИСОВКА ЗАМКНУТОГО КОНТУРА (Белый квадрат)
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(-boxSize, -boxSize);
    glVertex2f(boxSize, -boxSize);
    glVertex2f(boxSize, boxSize);
    glVertex2f(-boxSize, boxSize);
    glEnd();

    // 2. ОТРИСОВКА ШАРИКА (Желтый круг)
    glColor3f(1.0f, 1.0f, 0.0f);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
    {
        // Переводим градусы в радианы для функций cos и sin
        float angle = i * M_PI / 180.0f;
        // Вычисляем координаты точек окружности вокруг центра (ballX, ballY)
        float x = ballX + cos(angle) * radius;
        float y = ballY + sin(angle) * radius;
        glVertex2f(x, y);
    }
    glEnd(); // [cite: 396, 406, 576]
}

void labba11::updatePhysics()
{
    // Сдвигаем шарик на вектор скорости
    ballX += speedX;
    ballY += speedY;

    if (ballX + radius >= boxSize) {
        ballX = boxSize - radius;
        speedX = -speedX;
    }
    else if (ballX - radius <= -boxSize) {
        ballX = -boxSize + radius;
        speedX = -speedX;
    }

    // Проверка коллизий с верхней и нижней стенками
    if (ballY + radius >= boxSize) {
        ballY = boxSize - radius;
        speedY = -speedY;
    }
    else if (ballY - radius <= -boxSize) {
        ballY = -boxSize + radius;
        speedY = -speedY;
    }

    // Запрашиваем перерисовку окна OpenGL (вызовется paintGL)
    updateGL(); [cite: 349, 354, 359, 364, 559]
}