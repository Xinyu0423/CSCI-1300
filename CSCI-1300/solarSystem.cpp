/*
 *  Recation 10
 *  Author: Xinyu Jiang
 *  TA: Xiaozhe Zhang CSCI-1300
 *  11/05/2017
 */
#include "solarSystem.h"
#include <iostream>
#include <math.h>
#include "planet.h"
using namespace std;
solarSystem::solarSystem(string str){
    systemName=str;
    numPlanets=0;
}
solarSystem::~solarSystem(){
    
}
string solarSystem::getName(){
    return systemName;
}
int solarSystem::getNumPlanets(){
    return numPlanets;
}
bool solarSystem::addPlanet(string str, float x){
    if(numPlanets<maxNumPlanets){
        systemPlanets[numPlanets]=planet(str,x);
        numPlanets++;
        }
    return true;
}
planet solarSystem::getPlanet(int x){

        return systemPlanets[x];
}
float solarSystem::radiusDifference(planet x, planet y){
    float diff=fabs(x.getRadius()-y.getRadius());
    return diff;
}
