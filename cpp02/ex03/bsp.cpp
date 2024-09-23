#include "Point.hpp"

// Función auxiliar para calcular el área de un triángulo usando sus vértices
static Fixed area(Point const& p1, Point const& p2, Point const& p3) 
{
    // Obtener las coordenadas de los puntos
    float x1 = p1.get_x().toFloat();
    float y1 = p1.get_y().toFloat();
    float x2 = p2.get_x().toFloat();
    float y2 = p2.get_y().toFloat();
    float x3 = p3.get_x().toFloat();
    float y3 = p3.get_y().toFloat();

    // Calcular cada término de la fórmula del área
    float term1 = x1 * (y2 - y3);
    float term2 = x2 * (y3 - y1);
    float term3 = x3 * (y1 - y2);

    // Sumar los términos
    float area_value = (term1 + term2 + term3) / 2.0f;
    
    if (area_value < 0)
        area_value = -area_value;
    return (Fixed(area_value));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed total_area = area(a, b, c);
    
    // Área de los triángulos formados por el punto y los vértices del triángulo
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);

    //chequeo si esta en un borde 
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return (false);
    
    // Si la suma de las áreas de los triángulos es igual al área original, el punto está dentro
    if (area1 + area2 + area3 != total_area)
        return (false);
    return (true);
}
