
#include "../include/Renderer.h"
#include "vertexConf.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int SCR_WIDTH =  960;
const unsigned int SCR_HEIGHT = 540;

int main() {
    my::Shape triangle(SCR_WIDTH,SCR_HEIGHT);
    triangle.trianglePositionVertex(3,4,5);
    for(int i=0;i<9;i++) {
        std::cout << triangle.posVertices[i] << std::endl;
    }
    return 0;
}

int main2() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Eggomination", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glew initialization
    if( glewInit() != GLEW_OK ) {
        std::cout << "error" << std::endl;
        return -1;
    }

    // opengl configurations for making transparent objects    
    GCE glEnable(GL_BLEND); GCE
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); GCE

    Shader shader(SHADER_DIR "vertex.shader", SHADER_DIR "fragment.shader");

    float vertices[] = {
        0.0f, 0.5f,0.0f,
        0.5f,-0.5f,0.0f,
       -0.5f,-0.5f,0.0f,
    };

   
    unsigned int indices[] = {
        0,1,2
    };

    unsigned int vao,vbo,ebo;

    glCreateVertexArrays(1,&vao);
    glCreateBuffers(1,&vbo);
    glCreateBuffers(1,&ebo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {

        if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window,true);
        }

        GCE glClearColor(0.1,0.3,0.3,1.0); GCE
        GCE glClear(GL_COLOR_BUFFER_BIT); GCE

        shader.use();
        glBindVertexArray(vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
        glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window); 
        glfwPollEvents();
    }
    glDeleteVertexArrays(1,&vao);
    glDeleteBuffers(1,&vbo);
    glDeleteBuffers(1,&ebo);

    shader.deleteShader();
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
