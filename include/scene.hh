#pragma once

#include <memory>
#include <list>
#include <vector>

#include "drone.hh"
#include "environment.hh"

//this code is actually here too quick

class Scene {
  std::list<std::shared_ptr<SceneObject>>  _SceneObjectList;
  std::list<std::shared_ptr<Drone>>        _DroneList;
public:

  const  std::list<std::shared_ptr<SceneObject>> & GetSceneObjList() const
  {
    return _SceneObjectList;
  }

  void AddSpikyHill( SpikyHill &Arg )
  {
   std::shared_ptr Ptr_Mountain = std::make_shared<SceneObject>( Arg );
   _SceneObjectList.push_back(Ptr_Mountain);
  }

  void AddDrone(Drone &Arg)
  {
    std::shared_ptr  Ptr_Drone = std::make_shared<Drone>( Arg );
    _SceneObjectList.push_back(Ptr_Drone);
    _DroneList.push_back(Ptr_Drone);
  }

  void AddPlateau( Plateau &Arg )
  {
   std::shared_ptr Ptr_Mountain = std::make_shared<SceneObject>( Arg );
   _SceneObjectList.push_back(Ptr_Mountain);
  }

  void AddRidge( Ridge &Arg )
  {
   std::shared_ptr Ptr_Mountain = std::make_shared<SceneObject>( Arg );
   _SceneObjectList.push_back(Ptr_Mountain);
  }
};
