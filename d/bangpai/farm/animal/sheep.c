#include "animal.h"

mapping animal_info = ([
    "name" : "羊",
    "id" : "sheep",
    "time" : 5400+time(),
    "meat" : 5,
    "meat_name" : "yangrou",
]);

void create()
{
    create_animal(animal_info);
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
