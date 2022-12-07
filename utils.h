/*

    -- Utilities for rad_cart_conv.c  

    utils.h

    written by: gordo venhuano penzaki

*/

#ifndef __USE_MISC
#define __USE_MISC
#endif

#ifndef _UTILS_H_
#define _UTILS_H_

#define RELATIVE_ABS_ZERO 0.000001

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct point_c {
    double x;
    double y;
} point_c;

/*
typedef struct point_c {
    double *; // NULL terniminated array
    char * expand_type;
}
*/

typedef struct point_r {
    double cs; /* cartesian squared */
    double rot; /* as the fractional part (* pi) */
} point_r;

/*
typedef struct point_r {
    double cs;
    double * rot; // NULL terminated array 
}
*/

typedef struct needed {
    point_c * cImaginary;
    point_c * cQuadrature;
    
    point_r * rImaginary;
    point_r * rQuadrature;
} needed;

typedef struct needed * information; /* NULL terminated array */

typedef struct information_time_series {
    information info;
    int * time_series_values; /* time units */
    char * type; /* time units type */
} information_time_series;

/* TODO Implimentations */
/* probably multiple */


point_c * convert_cart_to_Q(point_c * source, point_c * dest);
point_r * convert_radial_to_Q(point_r * source, point_r * dest);

/* End TODO */

point_c * to_cart(point_r * source, point_c * dest) {
    double pi = (double) (M_PI);
    double rotation = source->cs * pi;

    dest->y = sin(rotation) * source->cs;
    dest->x = cos(rotation) * source->cs;
 
    return dest;
}

point_r * to_radial(point_c * source, point_r * dest) {
    double pi = (double) (M_PI);
    double rotation = dest->rot * pi;

    dest->cs = sqrt(pow(source->x,2) + pow(source->y,2));

    dest->rot = atan(source->y/source->x);

    if (fabs(dest->rot) > RELATIVE_ABS_ZERO && dest->rot < 0.0f) {
        dest->rot = (pi + dest->rot) + pi;
    }

    dest->rot = dest->rot / pi;

    return dest;
}

#endif /* _UTILS_H_ */
