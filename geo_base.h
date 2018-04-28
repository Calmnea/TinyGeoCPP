/*
 * This header file define some base data type and some constant of geometry.
 */

#ifndef TINYGEO_GEO_BASE_H
#define TINYGEO_GEO_BASE_H


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
        void set_ll(double x, double y) { _ll_.x = x ; _ll_.y = y; }
        void set_ru(const Coord& p) { _ru_ = p; }
        void set_ru(const Coord& p) { _ru_.x = x; _ru_.y = y; }

        double area()
        {
            // TODO
        }

        // update ll and ru after add an other MBR object or Coord
        MBR& add(const MBR& rh)
        {
            // TODO
            return *this;
        }

        MBR& add(const Coord& p)
        {
            // TODO
            return *this;
        }

        MBR& expand(double range)
        {
            // TODO
            return *this;
        }

        bool is_contain(const MBR& rh)
        {
            // TODO
            return false;
        }

        bool is_intersect(const MBR& rh)
        {
            // TODO
            return false;
        }

    };

} // namespace tinygeo




#endif //TINYGEO_GEO_BASE_H
