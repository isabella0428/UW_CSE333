#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Point3d{
    int32_t x, y, z;
}Point3d, *Point3dPtr;

Point3dPtr AllocatePoint3d(int32_t x, int32_t y, int32_t z){
    Point3dPtr p = (Point3dPtr)malloc(sizeof(Point3d));
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

int main(int argc, char **argv){
    int x = 1;
    int y = 2;
    int z = 3;
    Point3dPtr p = AllocatePoint3d(x, y, z);
    printf("x : %d y : %d z : %d\n", p->x, p->y, p->z);
    free(p);
}