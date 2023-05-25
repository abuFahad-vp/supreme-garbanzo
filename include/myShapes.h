#ifndef MY_SHAPES_H_
#define MY_SHAPES_H_

#include <vector>

namespace my {


    class Shape {

    public:

        std::vector<float> posVertices;
        unsigned int screenWidth;
        unsigned int screenHeight;

        Shape(unsigned int width, unsigned int height);
        void trianglePositionVertex(float a, float b, float c);
        float* rectangleVertex(float a, float b, float c);
    };
    
} // namespace my

#endif