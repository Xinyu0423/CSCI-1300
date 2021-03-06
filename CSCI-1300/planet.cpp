/*
 *  Recation 10
 *  Author: Xinyu Jiang
 *  TA: Xiaozhe Zhang CSCI-1300
 *  11/05/2017
 */
#include "planet.h"

planet::planet(){
}

planet::planet(string planetName, float planetRadius){
    name = planetName;
    radius = planetRadius;
}

planet::~planet(){
    //letting compiler handle deconstruction of the class
}

void planet::setName(string planetName){
    name = planetName;
}

string planet::getName(){
    return name;
}

void planet::setRadius(float planetRadius){
    radius = planetRadius;
}

float planet::getRadius(){
    return radius;
}

