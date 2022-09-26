# 3D-cube

This project aims to present a 3D scene composed of a cube and of a sphere, on a 2D screen. The technique implemented here is the rasteristation which consisted in creating a 3D world and projecting it on the screen using
conventional projection formulas.


Objects will be represented by facets, which will be projected onto a plane which will represent the screen. To build the scene in 3D, each object will be conceived as a set of quadrilaterals (composed in fact of two
triangles whose vertices are oriented counterclockwise), which
will have a color.

To do this, we use the SDL library which will allow us to display a
scene image in a separate window.

![Capture-1](https://user-images.githubusercontent.com/114404196/192311758-1ac776a9-ac5e-47c8-a963-7a2cdf76ac2a.PNG)
![Capture-2](https://user-images.githubusercontent.com/114404196/192311783-ccdc47ce-a3e1-4c41-8ebf-d8371a1bbd49.PNG)
![Capture-3](https://user-images.githubusercontent.com/114404196/192311799-53446916-abcd-4181-952b-e2bc6bf29c72.PNG)
![Capture-4](https://user-images.githubusercontent.com/114404196/192311817-c2ec4a30-7d33-4b6a-89f4-e46374cfb689.PNG)



