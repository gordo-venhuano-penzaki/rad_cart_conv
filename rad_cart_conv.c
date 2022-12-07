/*

    rad_cart_conv.c

    -tests are in int main(...)...

    -see compile instructions in in ./make.sh

    -see debug info for gdb in debug.conf

    - $ gdb -x debug.conf

    written by: gordo venhuano penzaki

*/

#include "utils.h"

int main(int argc, char ** argv) {
    /* tests */
    point_c * cart_point = (point_c *) malloc(sizeof(point_c));
    point_r * radial_point = (point_r *) malloc(sizeof(point_r));

    double testing_precision = 0.00001;

    double test = 0;
    
    cart_point->x = 1.0;
    cart_point->y = 1.0;

    radial_point = to_radial(cart_point, radial_point);

    test = (double) (1.0l/4.0l);
    if (fabs(radial_point->rot - test/*pi*/) > testing_precision) {
        printf("Failed conversion to radial 0001\n");
    }

    test = (double) sqrt(2.0l);
    if (fabs(radial_point->cs - test) > testing_precision) {
        printf("Failed conversion to radial 0002\n");
    }

    radial_point->cs = 1.0;
    radial_point->rot = 1.0;

    cart_point = to_cart(radial_point, cart_point);

    test = (double)(-1.0);
    if (fabs(cart_point->x - test) > testing_precision ) {
        printf("Failed conversion to cartesian 0001\n");
    }

    test = (double)(0.0);
    if (fabs(cart_point->y  - test) > testing_precision) {
        printf("Failed conversion to cartesian 0002\n");
    }

    cart_point->x = 0.0;
    cart_point->y = -1.0;

    radial_point = to_radial(cart_point, radial_point);

    test = (double)(3.0l/2.0l); /* x PI */
    if (fabs(radial_point->rot - test) > testing_precision) {
        printf("Failed conversion to radial 0003\n");
    }
    
    test = (double) (1.0l);
    if (fabs(radial_point->cs - test) > testing_precision) {
        printf("Failed conversion to radial 0004\n");
    }

    radial_point->cs = 2.0;
    radial_point->rot = 0.0;

    cart_point = to_cart(radial_point, cart_point);

    test = (double)(2.0);
    if (fabs(cart_point->x - test) > testing_precision ) {
        printf("Failed conversion to cartesian 0001\n");
    }

    test = (double)(0.0);
    if (fabs(cart_point->y  - test) > testing_precision) {
        printf("Failed conversion to cartesian 0002\n");
    }

    printf("Tests done!\n");
     
    free(cart_point);
    free(radial_point);
    return 0;    
}
