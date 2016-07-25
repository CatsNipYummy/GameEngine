//
//  Cube.hpp
//  Game Engine
//
//  Created by Anil Unnikrishnan on 19/07/16.
//  Copyright © 2016 Anil Unnikrishnan. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "Primitive.hpp"

#endif /* Cube_hpp */

class Cube : public Primitive {
private:
    
public:
    Cube();
    ~Cube();
    void draw();
    void remove();
};
