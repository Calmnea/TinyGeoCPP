/*
 * This header file define some base data type and some constant of geometry.
 */

#ifndef TINYGEO_GEO_BASE_H
#define TINYGEO_GEO_BASE_H

#include <cmath>

namespace tinygeo
{
    const double _PI = 3.1415926535;

    // Coord represents a position on the coordinate system,
    // unlike Point which derived from Geometry class,
    // Coord does not contain any operation.
    struct Coord
    {
        double x;
        double y;
        Coord(double x_, double y_) : x(x_), y(y_) {}
    };

    // MBR define Minimum Bounding Rectangle of geometry,
    // every MBR only store Left Lower(ll) point and Right Upper(ru) point.
    class MBR
    {
    private:
        Coord _ll_;
        Coord _ru_;

    public:
        MBR(const Coord& ll_, const Coord& ru_) : _ll_(ll_), _ru_(ru_) {}
        ~MBR() {}

        Coord ll() const { return _ll_; }
        Coord ru() const { return _ru_; }
        void set_ll(const Coord& p) { _ll_ = p; }
        void set_ll(double x, double y) { _ll_.x = x; _ll_.y = y; }
        void set_ru(const Coord& p) { _ru_ = p; }
        void set_ru(const Coord& p) { _ru_.x = x; _ru_.y = y; }

        double area()
        {
            return abs((ru.y - ll.y) * (ru.x - ll.x));
        }

        // update ll and ru after add an other MBR object or Coord
        MBR& add(const MBR& rh)
        {
            if (rh.ll().x < _ll_.x) _ll_.x = rh.ll().x;
            if (rh.ll().y < _ll_.y) _ll_.y = rh.ll().y;
            if (rh.ru().x > _ru_.x) _ru_.x = rh.ru().x;
            if (rh.ru().y > _ru_.y) _ru_.y = rh.ru().y;
            return *this;
        }

        MBR& add(const Coord& p)
        {
            if (p.x < _ll_.x) _ll_.x = p.x;
            if (p.y < _ll_.y) _ll_.y = p.y;
            if (p.x > _ru_.x) _ru_.x = p.x;
            if (p.y > _ru_.y) _ru_.y = p.y;
            return *this;
        }

        // expand MBR`s width and height
        MBR& expand(double range)
        {
            // TODO: negative process
            _ll_.x -= range;
            _ll_.y -= range;
            _ru_.x += range;
            _ru_.y += range;
            return *this;
        }

        bool is_contain(const MBR& rh)
        {
            return ((_ll_.x < rh.ll().x) && (_ll_.y < rh.ll().y) &&
                    (_ru_.x > rh.ru().x) && (_ru_.y > rh.ru().y));
        }

        bool is_intersect(const MBR& rh)
        {
            // TODO
            return false;
        }

    };

} // namespace tinygeo




#endif //TINYGEO_GEO_BASE_H
