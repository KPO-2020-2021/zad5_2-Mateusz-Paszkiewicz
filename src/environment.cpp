#include "../include/environment.hh"

int SceneObject::ObjCount=0;

/*!
 * Funckja czytajaca z plikow dane dla przeszkody i tworzaca plik(!) specjalnie dla tego objektu
*
*\param[in] StartPoint miejsce na ktore objekt wejdzie na mapie
*\param[in] const char* File_Names nazwa pliku struktury objektu
*\retval Objekt utworzony przez plik
*/
SpikyHill SpikyHill::CreateSpikyHill(const char *File_Name, Vector3 StartPoint , PzG::LaczeDoGNUPlota Lacze)
{
  ++this->ObjCount;

  std::string name="../datasets/dat/object";
  name += std::to_string(this->ObjCount);
  name+=".dat";
  const char *const_name=name.c_str();

  CoordsReadFromFile(File_Name, this->Structure);

  double BottomArr[3]={this->Structure.GetPosition()[0] + (this->Structure(6,0)-this->Structure(0,0))/2,
                       this->Structure.GetPosition()[1] + (this->Structure(6,1)-this->Structure(0,1))/2,
                       this->Structure.GetPosition()[2] + (this->Structure(6,2)-this->Structure(0,2))/2,};
  Vector3 Tmp = Vector3(BottomArr);

  this->Bottom=Tmp;

  (*this)=(*this)-Tmp+StartPoint;

  SaveCoordsToFile(const_name, this->Structure);

  Lacze.DodajNazwePliku(const_name);
  Lacze.Rysuj();

  return (*this);
}

/*!
* Przeciazenie operatora dodawania dla SpikyHill
*
*\param[in] tmp - wektor ktory przesunie objekt
*\retval objekt spikyhill przesuniety o wektor tmp
*/
SpikyHill SpikyHill:: operator + (Vector3 &tmp)
{
  this->Structure = this->Structure + tmp;
  this->Bottom = this->Bottom + tmp;

  return (*this);
}

/*!
* Przeciazenie operatora odejmowania dla SpikyHill
*
*\param[in] tmp - wektor odwrotny do wektora ktory przesunie objekt
*\retval objekt spikyhill przesuniety o wektor -tmp
*/
SpikyHill SpikyHill:: operator - (Vector3 &tmp)
{
  this->Structure = this->Structure - tmp;
  this->Bottom = this->Bottom - tmp;

  return (*this);
}

/*!
* Obliczenie promienia zajmowanego przez objekt sceny okregu w ktory nic nie powinno wejsc
*
*\retval dlugosc promienia
*/
double SpikyHill::GetRadius()
{
  double RadiusArr[3] ={(this->Structure(6,0)-this->Structure(5,0))/2,
                        (this->Structure(6,1)-this->Structure(5,1))/2,
                        (this->Structure(6,2)-this->Structure(5,2))/2};

  Vector3 Radius = Vector3(RadiusArr);

  return Radius.Length();
}

/*!
 * Funckja czytajaca z plikow dane dla przeszkody i tworzaca plik(!) specjalnie dla tego objektu
*
*\param[in] StartPoint miejsce na ktore objekt wejdzie na mapie
*\param[in] const char* File_Names nazwa pliku struktury objektu
*\retval Objekt utworzony przez plik
*/
Plateau Plateau::CreatePlateau(const char *File_Name, Vector3 StartPoint , PzG::LaczeDoGNUPlota Lacze)
{
  ++this->ObjCount;

  std::string name="../datasets/dat/object";
  name += std::to_string(this->ObjCount);
  name +=".dat";
  const char *const_name=name.c_str();


  CoordsReadFromFile(File_Name, this->Structure);

  double BottomArr[3]={this->Structure.GetPosition()[0] + (this->Structure(6,0)-this->Structure(0,0))/2,
                       this->Structure.GetPosition()[1] + (this->Structure(6,1)-this->Structure(0,1))/2,
                       this->Structure.GetPosition()[2] + (this->Structure(6,2)-this->Structure(0,2))/2};
  Vector3 Tmp = Vector3(BottomArr);

  this->Bottom=Tmp;

  (*this)=(*this)-Tmp+StartPoint;

  SaveCoordsToFile(const_name, this->Structure);

  Lacze.DodajNazwePliku(const_name);
  Lacze.Rysuj();

  return (*this);
}

/*!
* Obliczenie promienia zajmowanego przez objekt sceny okregu w ktory nic nie powinno wejsc
*
*\retval dlugosc promienia
*/
double Plateau::GetRadius()
{
  double RadiusArr[3] ={(this->Structure(6,0)-this->Structure(5,0))/2,
                        (this->Structure(6,1)-this->Structure(5,1))/2,
                        (this->Structure(6,2)-this->Structure(5,2))/2};

  Vector3 Radius = Vector3(RadiusArr);

  return Radius.Length();
}

/*!
* Przeciazenie operatora dodawania dla Plateau
*
*\param[in] tmp - wektor ktory przesunie objekt
*\retval objekt Plateau przesuniety o wektor tmp
*/
Plateau Plateau:: operator + (Vector3 &tmp)
{
  this->Structure = this->Structure + tmp;
  this->Bottom = this->Bottom + tmp;

  return (*this);
}

/*!
* Przeciazenie operatora odejmowania dla Plateau
*
*\param[in] tmp - wektor odwrotny do wektora ktory przesunie objekt
*\retval objekt plateau przesuniety o wektor -tmp
*/
Plateau Plateau:: operator - (Vector3 &tmp)
{
  this->Structure = this->Structure - tmp;
  this->Bottom = this->Bottom - tmp;

  return (*this);
}

/*!
 * Funckja czytajaca z plikow dane dla przeszkody i tworzaca plik(!) specjalnie dla tego objektu
*
*\param[in] StartPoint miejsce na ktore objekt wejdzie na mapie
*\param[in] const char* File_Names nazwa pliku struktury objektu
*\retval Objekt utworzony przez plik
*/
Ridge Ridge::CreateRidge(const char *File_Name, Vector3 StartPoint , PzG::LaczeDoGNUPlota Lacze)
{
  ++this->ObjCount;

  std::string name="../datasets/dat/object";
  name += std::to_string(this->ObjCount);
  name +=".dat";
  const char *const_name=name.c_str();


  CoordsReadFromFile(File_Name, this->Structure);

  double BottomArr[3]={this->Structure.GetPosition()[0] + (this->Structure(6,0)-this->Structure(0,0))/2,
                       this->Structure.GetPosition()[1] + (this->Structure(6,1)-this->Structure(0,1))/2,
                       this->Structure.GetPosition()[2] + (this->Structure(6,2)-this->Structure(0,2))/2};
  Vector3 Tmp = Vector3(BottomArr);

  this->Bottom=Tmp;

  (*this)=(*this)-Tmp+StartPoint;

  SaveCoordsToFile(const_name, this->Structure);

  Lacze.DodajNazwePliku(const_name);
  Lacze.Rysuj();

  return (*this);
}

/*!
* Obliczenie promienia zajmowanego przez objekt sceny okregu w ktory nic nie powinno wejsc
*
*\retval dlugosc promienia
*/
double Ridge::GetRadius()
{
  double RadiusArr[3] ={(this->Structure(6,0)-this->Structure(5,0))/2,
                        (this->Structure(6,1)-this->Structure(5,1))/2,
                        (this->Structure(6,2)-this->Structure(5,2))/2};

  Vector3 Radius = Vector3(RadiusArr);

  return Radius.Length();
}

/*!
* Przeciazenie operatora dodawania dla ridge
*
*\param[in] tmp - wektor ktory przesunie objekt
*\retval objekt ridge przesuniety o wektor tmp
*/
Ridge Ridge:: operator + (Vector3 &tmp)
{
  this->Structure = this->Structure + tmp;
  this->Bottom = this->Bottom + tmp;

  return (*this);
}

/*!
* Przeciazenie operatora odejmowania dla ridge
*
*\param[in] tmp - wektor odwrotny do wektora ktory przesunie objekt
*\retval objekt ridge przesuniety o wektor -tmp
*/
Ridge Ridge:: operator - (Vector3 &tmp)
{
  this->Structure = this->Structure - tmp;
  this->Bottom = this->Bottom - tmp;

  return (*this);
}
