#pragma once

#include "vector.hh"

class SceneObject{
private:
  char *ObjectName;
  char *FileName;
  Vector3 OccupiedPlane[4];
public:
  SceneObject AddBasePlane(Vector3[4]);
};



class SpikyHill : SceneObject {
  double Height;
public:

  SpikyHill AddParameters(double, Vector3[4]);
};


class Plateau : SceneObject {
  Vector3 HeigherPlane[4];
public:

  Plateau AddParameters(double, Vector3[4], Vector3[4]);
};
