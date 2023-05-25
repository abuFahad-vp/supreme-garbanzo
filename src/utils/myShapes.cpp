
#include "../../include/Renderer.h"

my::Shape::Shape(unsigned int screenWidth, unsigned int screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

void my::Shape::trianglePositionVertex(float a, float b, float c) {

    // x1 y1
    float x1 = (my::Shape::screenWidth)/2 + (a/2);
    float x2 = (my::Shape::screenWidth)/2 - (a/2);
    this->posVertices.push_back(x1);
    this->posVertices.push_back(0.0f);
    this->posVertices.push_back(0.0f);

    // x2 y2
    this->posVertices.push_back(x2);
    this->posVertices.push_back(0.0f);
    this->posVertices.push_back(0.0f);

    //x3 y3
    float x3 = (b*b-c*c+x1*x1-x2*x2) / (2*x1-2*x2);
    this->posVertices.push_back(x3);
    float y3 = sqrt(((x1-x3)*(x1-x3) - c*c)*(-1));
    this->posVertices.push_back(y3);
    this->posVertices.push_back(0.0f);
}