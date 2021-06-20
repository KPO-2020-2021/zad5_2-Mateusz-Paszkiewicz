#include "../include/environment.hh"

SceneObject SceneObject::AddBasePlane(Vector3 Base[4])
{
  for(int i=0; i<4; ++i)
    this->OccupiedPlane[i]=Base[i];

  return (*this);
}

SpikyHill SpikyHill::AddParameters(double Height, Vector3 Base[4])
{
  this->AddBasePlane(Base);
  this->Height=Height;

  return (*this);
}

/*bool SpikyHill::DrawSpikyHill()
{

}*/
