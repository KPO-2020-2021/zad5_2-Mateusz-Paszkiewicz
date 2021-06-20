#pragma once

#include "vector.hh"

class SceneObject{
private:
  char *ObjectName;
  char *FileName;
  Vector3 OccupiedPlane[4];
public:

};



class SpikyHill : SceneObject {
  double Height
};

class Plateau : SceneObject {
  Vector3 HeigherPlane[4];
};
