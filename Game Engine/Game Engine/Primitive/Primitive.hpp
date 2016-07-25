//
//  Primitive.hpp
//  Game Engine
//
//  Created by Anil Unnikrishnan on 19/07/16.
//  Copyright © 2016 Anil Unnikrishnan. All rights reserved.
//

#ifndef Primitive_hpp
#define Primitive_hpp

#include <stdio.h>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include "../common/shader.hpp"

#endif /* Primitive_hpp */

class Primitive {
protected:
    GLuint mVertexArrayID;
    GLuint mVertexBuffer;
    GLuint mProgramId;
    
public:
    Primitive();
    virtual void draw() {};
    virtual void remove() {};
};
