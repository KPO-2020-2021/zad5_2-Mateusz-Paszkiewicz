#pragma once

#include <string>
#include <charconv>

#include "vector.hh"
#include "cuboid.hh"
#include "handling.hh"
#include "lacze_do_gnuplota.hh"


/*    SpikyHill OBJECT :
             *
           /  \ \
         /|    \   \
       / *------\----*
     //          \ /
    *------------*
*/

/*    Ridge OBJECT :

             / *
           *    \
         | |\    \
        | |  \    \
       | |    \    \
      | *------\----*
     |/         \  /
    *------------*
*/

/*    Plateau OBJECT :
        *------------*
      / |          / |
    *------------*   |
    |   *--------|---*
    | /          | /
    *------------*
*/


/*!
*\brief Klasa SceneObject definiuje ogolnie pojety objekt
* na scenie za pomoca zestawu danych w postaci Cuboid.
*
*
* Klasa ta uzywa klasy cuboid z zapetlonymi punktami
* aby odwzorowac konkretna przeszkode na scenie.
*
*/
class SceneObject{
private:
  Cuboid Structure;
  char *ObjectName;
  char *FileName;

  static int ObjCount;
public:
  friend class SpikyHill;
  friend class Plateau;
  friend class Ridge;
};


/*!
*\brief SpikyHill przedstawia gore z ostrym szczytem
*
*/
class SpikyHill : public SceneObject {
  Vector3 Bottom;
public:

  SpikyHill CreateSpikyHill(const char *, Vector3 StartPoint ,PzG::LaczeDoGNUPlota);

  SpikyHill operator + (Vector3 &tmp);

  SpikyHill operator - (Vector3 &tmp);

  double GetRadius();
};

/*!
*\brief Plateau przedstawia plaskowyz
*
*/
class Plateau : public SceneObject {
  Vector3 Bottom;
  Vector3 HeigherPlane[4];
public:
  Plateau CreatePlateau(const char *, Vector3 StartPoint , PzG::LaczeDoGNUPlota);

  Plateau operator + (Vector3 &tmp);

  Plateau operator - (Vector3 &tmp);

  double GetRadius();
};

/*!
*\brief Plateau przedstawia gran
*
*/
class Ridge : public SceneObject {
  Vector3 Bottom;
public:
  Ridge CreateRidge(const char *, Vector3 StartPoint , PzG::LaczeDoGNUPlota);

  Ridge operator + (Vector3 &tmp);

  Ridge operator - (Vector3 &tmp);

  double GetRadius();
};
