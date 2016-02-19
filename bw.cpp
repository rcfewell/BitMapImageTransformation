#include "EasyBMP.h"
#include "EasyBMP.cpp"
using namespace std;

void colorToGray (BMP & Output);

int main (int argc, char* argv [])
{
  BMP myImage;
  myImage.ReadFromFile (argv[1]);
  colorToGray(myImage);
  myImage.WriteToFile(argv[2]);
  return 0;
}

void colorToGray (BMP & Output)
{
  int picWidth = Output.TellWidth();
  int picHeight = Output.TellHeight ();
  Output.SetBitDepth (1);
  for (int i = 0; i < picWidth-1; ++i)
    {
      for (int j = 0; j < picHeight-1; ++j)
	{
	  int col = 0.1* Output (i, j)->Blue + 0.6*Output (i, j) ->Green
	    + 0.3* Output (i, j)->Red;
	  if (col > 127)
	    {
	      Output (i, j)->Red = 255;
	      Output (i, j) ->Blue = 255;
	      Output (i, j)->Green = 255;
	    }
	}
    }    
}
