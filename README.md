# 3D-cube

This project aims to present a 3D scene composed of a cube and of a sphere, on a 2D screen. The technique implemented here is the rasteristation which consisted in creating a 3D world and projecting it on the screen using
conventional projection formulas.


Objects will be represented by facets, which will be projected onto a plane which will represent the screen. To build the scene in 3D, each object will be conceived as a set of quadrilaterals (composed in fact of two
triangles whose vertices are oriented counterclockwise), which
will have a color.

To do this, we use the SDL library which will allow us to display a
scene image in a separate window.
