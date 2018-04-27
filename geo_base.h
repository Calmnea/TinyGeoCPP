/*
 * This header file define some base data type and some constant of geometry.
 */

#ifndef TINYGEO_GEO_BASE_H
#define TINYGEO_GEO_BASE_H

#include <vector>

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
    typedef std::vector<Coord> Coords;

    // For simplicity, we abstract the geometric shapes into 3 types.
    // Some libraries define other types of geometry such as
    // multi-point, multi-line or multi-polygon, etc. These types
    // will be represented as a collection of primitive types in TinyGeo.
    enum GeoType
    {
        POINT_TYPE = 0,
        SEGMENT_TYPE,
        POLYGON_TYPE
    };


    class Geometry
    {
    public:
        Geometry();
        virtual ~Geometry() = 0;

    protected:
        GeoType _type_;

    // TODO: common operation

    };

    class Point : public Geometry
    {
    public:
        explicit Point(const Coord& coord_) : p(coord_) {}
        Point(double x, double y);

    private:
        Coord _p_;

    // TODO
    };

    class Segment : public Geometry
    {
    public:
        Segment(const Coord& p1_, const Coord& p2_) : _p1_(p1_), _p2_(p2_) {}

    private:
        Coord _p1_;
        Coord _p2_;

    public:
        double len() const;

    // TODO
    };

    class Polygon : public Geometry
    {
    public:
        explicit Polygon(const Coords& coords_);

    private:
        Coords _coords_;

    public:
        double area() const;

    // TODO
    };

} // namespace tinygeo




#endif //TINYGEO_GEO_BASE_H
