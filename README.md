# TinyGeo
*A light-weight C++ library for Geometry.*

### Basic Geometric Type
*For simplicity, we abstract the geometric shapes into three types: **`Point`**, **`Line`** and **`Polygon`**. They are derived class of abstract class **`Geometry`**. Some libraries define other types of geometry such as multi-point, multi-line or multi-polygon, etc. These types will be represented as a collection of primitive types in TinyGeo.*

*In TinyGeo, **`Coord`** represents a position on the coordinate system, unlike `Point` which derived from `Geometry` class, `Coord` does not contain any operation.*

- **Point**
- **Line**
- **Polygon**
