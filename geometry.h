//
// This header define gemoetry types.
//
// For simplicity, we abstract the geometric shapes into 3 types.
// Some libraries define other types of geometry such as
// multi-point, multi-line or multi-polygon, etc. These types
// will be represented as a collection of primitive types in TinyGeo.
//



#ifndef TINYGEO_GEOMETRY_H
#define TINYGEO_GEOMETRY_H

#include "geo_base.h"
#include <vector>

namespace tinygeo
{

    enum GeoType { POINT_TYPE = 0, LINE_TYPE, POLYGON_TYPE };

    class Geometry
    {
    public:
        virtual ~Geometry() = 0;

    protected:
        GeoType type_;

    };

    class Point : public Geometry
    {
    public:
        Point();
        Point(const Point& p_);
        Point(const Coord& coord_);
        Point(double x, double y);
    };

    // Points type is ordered collection of Point object
    typedef std::vector<Point> Points;

    class Line : public Geometry
    {
    public:
        Line();
        Line(const Line& line_);
        explicit Line(const Points& points_);
    };
    typedef std::vector<Line> Lines;

    class Polygon : public Geometry
    {
    public:
        Polygon();
        Polygon(const Polygon& polygon_);
        explicit (const Points& points_);
    };
    typedef std::vector<Polygon> Polygons;

} // namespace tinygeo

#endif //TINYGEO_GEOMETRY_H
