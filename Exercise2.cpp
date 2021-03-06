#include <cstdlib>
#include "EasyBMP.h"
#include "EasyBMP.cpp"
using namespace std;

BMP tile (BMP & I, BMP & O);

int main (int argc, char* argv [])
{
  BMP MyImage;
  MyImage.ReadFromFile(argv[1]);

  if (MyImage.TellHeight () != MyImage.TellWidth())
    {
      cout << "The image you entered was not a square!" << endl;
      exit (1);
    }
  if (MyImage.TellHeight () % 2 != 0 && MyImage.TellWidth () % 2 != 0)
    {
      cout << "The image's height and width is not a square of two" << endl;
      exit (2);
    }

  BMP NewMyImage = MyImage;
  tile (MyImage, NewMyImage);

  NewMyImage.WriteToFile(argv[2]);
  return 0;
}

BMP tile (BMP & I, BMP & O)
{
  O.SetSize( I.TellWidth (), I. TellHeight ());
  if (I.TellWidth () == 1)
    {
      RangedPixelToPixelCopy (I, 0, 1, 1, 0, O, 0, 0);
      return O;
    }

  BMP IMG1 (I);
  BMP IMG2;
  Rescale (IMG1, 'p', 50);
  RangedPixelToPixelCopy (IMG1, 0, IMG1.TellWidth (), IMG1.TellHeight (), 0, O, 0, O.TellHeight () / 2);
  tile (IMG1, IMG2);
  RangedPixelToPixelCopy (IMG2, 0, IMG2.TellWidth(), IMG2.TellHeight(), 0, O, O.TellWidth()/2, 0);
  RangedPixelToPixelCopy (IMG2, 0, IMG2.TellWidth(), IMG2.TellHeight(), IMG2.TellHeight()/2, O, O.TellWidth()/2, O.TellHeight ()/2); 
  RangedPixelToPixelCopy (IMG2, 0, IMG2.TellWidth(), IMG2.TellHeight(), IMG2.TellHeight()/2, O, O.TellWidth()/2, 3*O.TellHeight()/4);
  RangedPixelToPixelCopy (IMG2, 0, IMG2.TellWidth() / 2, IMG2.TellHeight (), 0, O, O.TellWidth () / 4, 0);
  RangedPixelToPixelCopy (IMG2, 0, IMG2.TellWidth () / 2, IMG2. TellHeight (), 0, O, 0, 0);

  return O;
}
