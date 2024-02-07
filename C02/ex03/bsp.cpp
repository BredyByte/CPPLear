#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed v0x = c.getX() - a.getX();
    Fixed v0y = c.getY() - a.getY();
    Fixed v1x = b.getX() - a.getX();
    Fixed v1y = b.getY() - a.getY();
    Fixed v2x = point.getX() - a.getX();
    Fixed v2y = point.getY() - a.getY();

	Fixed dot00 = v0x * v0x + v0y * v0y;
    Fixed dot01 = v0x * v1x + v0y * v1y;
    Fixed dot02 = v0x * v2x + v0y * v2y;
    Fixed dot11 = v1x * v1x + v1y * v1y;
    Fixed dot12 = v1x * v2x + v1y * v2y;

	Fixed invDenom = dot00 * dot11 - dot01 * dot01;
    Fixed u = (dot11 * dot02 - dot01 * dot12) / invDenom;
    Fixed v = (dot00 * dot12 - dot01 * dot02) / invDenom;

	return (u >= 0 && v >= 0 && u + v <= 1);
}
