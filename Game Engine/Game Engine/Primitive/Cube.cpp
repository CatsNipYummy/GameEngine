//
//  Cube.cpp
//  Game Engine
//
//  Created by Anil Unnikrishnan on 19/07/16.
//  Copyright © 2016 Anil Unnikrishnan. All rights reserved.
//

#include "Cube.hpp"

const float CUBE_SIZE = 0.5f;

Cube::Cube() {
    glGenVertexArrays(1, &mVertexArrayID);
    glBindVertexArray(mVertexArrayID);
    
    // Create and compile shaders
    mProgramId = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
    
    
    static const GLfloat gVertexBufferData[] = {
        -CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        
        CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        
        -CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        
        -CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        
        CUBE_SIZE,-CUBE_SIZE,-CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        
        CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE,-CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        -CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
        CUBE_SIZE,-CUBE_SIZE, CUBE_SIZE
    };
    
    glGenBuffers(1, &mVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData), gVertexBufferData, GL_STATIC_DRAW);
}

Cube::~Cube() {
    
}

void Cube::draw() {
    glUseProgram(mProgramId);
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glVertexAttribPointer(
                          0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (void*)0
                          );
    
    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 12);
    
    glDisableVertexAttribArray(0);
}

void Cube::remove() {
    // Cleanup VBO
    glDeleteBuffers(1, &mVertexBuffer);
    glDeleteVertexArrays(1, &mVertexArrayID);
    glDeleteProgram(mProgramId);
}