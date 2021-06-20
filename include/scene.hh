#pragma once

#include <memory>
#include <list>

#include "drone.hh"
#include "environment.hh"


class Scene {
  std::list<std::shared_ptr<SceneObject>>  _SceneObjectList;
  std::listt<std::shared_ptr<Drone>>       _DroneList;
public:

  const  std::list<std::shared_ptr<SceneObject>> &GetSceneObjList() const
  {
    return _SceneObjectList;
  }

  void AddSpikyHill( double Middle, double height )
   {
     std::shared_ptr Ptr_Mountain = std::make_shared<SpikyHill>();
     _ListaObScn.push_back(Ptr_Mountiain);
   }

  void AddDrone( /* Tu jakies parametry */ )
  {
    std::shared_ptr  Ptr_Drone = std::make_shared<Drone>();
    _SceneObjectList.push_back(Ptr_Drone);
    _DroneList.push_back(Ptr_Drone);
  }
};

bool Dron::IsLandingPossible( const Scene &Current_Scene ) const
{
  for (const std::shared_ptr<ObiektSceny> &Ptr_SceneObjects : Current_Scene.GetSceneObjList()  ) {
    if (&Ptr_SceneObjects == this) continue;
    if (Ptr_SceneObjects.CzyNakladajaSieNaSiebie(GetPosition(),WezPromienObrysu())) {
      if (!Ptr_SceneObjects.IsLandingPossible()) return true;
    }
  }
  return true;
}
