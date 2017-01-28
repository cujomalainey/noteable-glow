#include "HSLtoRGB.h"
// alg from http://easyrgb.com/index.php?X=MATH&H=19#text19

double Hue_2_RGB( double v1, double v2, double vH ) ;


if ( S == 0 )                       //HSL from 0 to 1
{
   R = L * 255                      //RGB results from 0 to 255
   G = L * 255
   B = L * 255
}
else
{
   if ( L < 0.5 ) var_2 = L * ( 1 + S )
   else           var_2 = ( L + S ) - ( S * L )

   var_1 = 2 * L - var_2

   R = 255 * Hue_2_RGB( var_1, var_2, H + ( 1 / 3 ) )
   G = 255 * Hue_2_RGB( var_1, var_2, H )
   B = 255 * Hue_2_RGB( var_1, var_2, H - ( 1 / 3 ) )
}

double Hue_2_RGB( double v1, double v2, double vH )             //Function Hue_2_RGB
{
   if ( vH < 0 ) vH += 1
   if ( vH > 1 ) vH -= 1
   if ( ( 6 * vH ) < 1 ) return ( v1 + ( v2 - v1 ) * 6 * vH )
   if ( ( 2 * vH ) < 1 ) return ( v2 )
   if ( ( 3 * vH ) < 2 ) return ( v1 + ( v2 - v1 ) * ( ( 2 / 3 ) - vH ) * 6 )
   return  v1;
}