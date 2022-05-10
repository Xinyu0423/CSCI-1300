//
//  planet.hpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/4.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#ifndef planet_h
#define planet_h

#include <stdio.h>
#include <iostream>
using namespace std;
class planet{
public:
    planet();
    ~planet();
    planet(string, float);
    void setName(string);
    string getName();
    void setRadius(float);
    float getRadius();
private:
    string name;
    float radius;
};
#endif /* planet_hpp */
