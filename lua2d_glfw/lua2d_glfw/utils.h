/*
 Copyright (c) 2015 chenbingfeng (iichenbf#gmail.com)

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#ifndef __Lua2d__utils__
#define __Lua2d__utils__

#include <iostream>
#include "cppgl/cppgl.h"

#ifdef __APPLE__
#include <GLFW/glfw3.h>
#endif

#ifdef _WIN32
#pragma comment(lib, "opengl32.lib")
#define GLEW_STATIC
#include "cppgl\glew\glew.h"
#include "GLFW/glfw3.h"
#pragma comment(lib,"glfw3.lib")
#endif

#define LOG(...) Log(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

inline void LogRecursive(std::ostream& os){}

template<typename T, typename... Args>
void LogRecursive(std::ostream& os, T first, const Args&... rest)
{
    os << first << " ";
    LogRecursive(os, rest...);
}

template<typename... Args>
void Log(const char* file, const char* func, int line, const Args&... args)
{
    //std::cout << file <<":"<< "(" << line << ")"<< func<<": ";
    std::cout << func << "/" << line << ": ";
    LogRecursive(std::cout, args...);
    std::cout << std::endl;
}

#define NS_L2D_BEGIN  namespace l2d{
#define NS_L2D_END    }

inline void printMat4(const glm::mat4& m)
{
    for (int i = 0; i < 16;  i++) {
        std::cout << (glm::value_ptr(m))[i] <<" ";
    }
    std::cout << std::endl;
}

#endif /* defined(__Lua2d__utils__) */
