#include <cmath> // Не забудьте подключить математическую библиотеку [cite: 192]

float GLWidget::func(float x, float y)
{
    // Вычисляем расстояние от центра координат до текущей точки (радиус)
    float r = sqrt(x * x + y * y);

    if (r == 0) return curvature;
    return sin(r * 0.05f) * curvature;
}
