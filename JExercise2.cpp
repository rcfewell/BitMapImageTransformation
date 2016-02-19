#include <cstdlib>
#include "EasyBMP.h"
#include "EasyBMP.cpp"
using namespace std;

BMP tile (BMP & input, BMP & output);

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

BMP tile (BMP & input, BMP & output)
{
  output.SetSize( input.TellWidth (), input.TellHeight ());
  if (input.TellWidth () == 1)
    {
      RangedPixelToPixelCopy (input, 0, 1, 1, 0, output, 0, 0);
      return output;
    }


  BMP temp;
  BMP temp2;
  //output.SetSize(input.TellWidth(),input.TellHeight());
  temp.SetSize(input.TellWidth(),input.TellHeight());
  temp2.SetSize(input.TellWidth(),input.TellHeight());
  RangedPixelToPixelCopy(input,0,input.TellWidth(),input.TellHeight(),0,temp,0,0);

  Rescale(temp,'p',50);

  RangedPixelToPixelCopy(temp,0,temp.TellWidth(),temp.TellHeight(),0,output,0, output.TellHeight()/2);
  RangedPixelToPixelCopy(output,0,output.TellWidth(),output.TellHeight(),0,temp2,0,0);

  tile(temp,temp2);

  RangedPixelToPixelCopy(temp2,0,temp2.TellWidth(),temp2.TellHeight(),0,output,((output.TellWidth())/2),0);
  RangedPixelToPixelCopy(output,((output.TellWidth())/2),(3*(output.TellWidth())/4),((output.TellHeight())/2),0,output,0,0);
  RangedPixelToPixelCopy(output,((output.TellWidth())/2),(3*(output.TellWidth())/4),((output.TellHeight())/2),0,output,(output.TellWidth())/4,0);
  RangedPixelToPixelCopy(output,((output.TellWidth())/2),output.TellWidth(),((output.TellHeight())/2),((output.TellHeight())/4),output,(output.TellWidth())/2,(output.TellHeight())/2);
  RangedPixelToPixelCopy(output,((output.TellWidth())/2),output.TellWidth(),((output.TellHeight())/2),((output.TellHeight())/4),output,(output.TellWidth())/2,3*(output.TellHeight())/4);

  return output;
}


