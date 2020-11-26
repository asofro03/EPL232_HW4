#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


BITMAPINFOHEADER tograyscale(BITMAPINFOHEADER *img)
{
    int x, y;
   BITMAPINFOHEADER *timg;
   double rc, gc, bc, l;
   unsigned int ofs;
 
   timg = alloc_grayimg(img->biWidth, img->biHeight);
 
   for(x=0; x < img->biWidth; x++)
   {
      for(y=0; y < img->biHeight; y++)
      {
        ofs = (y * img->biWidth) + x;
        rc = (double) img->buf[ofs][y];
        gc = (double) img->buf[ofs][y+1];
        bc = (double) img->buf[ofs][y+2];
        (int) l = 0.299*rc + 0.587*gc + 0.114*bc;
        timg->buf[ofs][0] = (luminance) (l+0.5);
      }
   }
   return timg;
}
