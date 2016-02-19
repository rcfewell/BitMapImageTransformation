#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include <iostream>
using namespace std;

void CheckerBoard (BMP & Output);

int main (int argc, char * argv [])
{
  BMP Board;
  Board.SetSize (256, 256);
  CheckerBoard (Board);
  Board.WriteToFile (argv [1]);
  return 0;
}

void CheckerBoard (BMP & Output)
{
  int picWidth = Output.TellWidth();
  int picHeight = Output.TellHeight();
  for (int i = 0; i < picWidth; ++i)
    {
      for (int j = 0; j < picHeight; ++j)
	{
	  if ((i % 64 < 32 && j % 64 < 32) || (i % 64 >= 32 && j % 64 >= 32))
	    {
	      Output(i, j) -> Red = 255;
	      Output(i, j) -> Green = 0;
	      Output(i, j) -> Blue = 0;
	    }
	  else
	    {
	      Output(i, j) -> Red = 0;
	      Output(i, j) -> Green = 0;
	      Output(i, j) -> Blue = 0;
	    }
	}
    }
}




  
	
