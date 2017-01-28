#include "HSLtoRGB.h"
// alg from http://easyrgb.com/index.php?X=MATH&H=19#text19

double Hue_2_RGB( double v1, double v2, double vH );

RGB_point HSL_2_RGB( HSL_point point )
{
   double H, S, L, var_1, var_2;
   RGB_point rgb;

   H = point.h / H_MAX;
   S = point.s / S_MAX;
   L = point.l / L_MAX;

   if ( S == 0 )                       //HSL from 0 to 1
   {
      rgb.r = L * 255;                      //RGB results from 0 to 255
      rgb.g = L * 255;
      rgb.b = L * 255;
   }
   else
   {
      if ( L < 0.5 ) var_2 = L * ( 1 + S );
      else           var_2 = ( L + S ) - ( S * L );

      var_1 = 2 * L - var_2;

      rgb.r = 255 * Hue_2_RGB( var_1, var_2, H + ( 1.0 / 3 ) );
      rgb.g = 255 * Hue_2_RGB( var_1, var_2, H );
      rgb.b = 255 * Hue_2_RGB( var_1, var_2, H - ( 1.0 / 3 ) );
   }
   return rgb;
}

double Hue_2_RGB( double v1, double v2, double vH )             //Function Hue_2_RGB
{
   if ( vH < 0 ) vH += 1;
   if ( vH > 1 ) vH -= 1;
   if ( ( 6 * vH ) < 1 ) return ( v1 + ( v2 - v1 ) * 6 * vH );
   if ( ( 2 * vH ) < 1 ) return ( v2 );
   if ( ( 3 * vH ) < 2 ) return ( v1 + ( v2 - v1 ) * ( ( 2.0 / 3 ) - vH ) * 6 );
   return  v1;
}