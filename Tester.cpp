//
// Created by Mariciuc Andrei on 5/24/2021.
//


#include <iostream>
#include "headers/Vector2D.h"
#include "headers/Tester.h"
#include "headers/Matrix3.h"
#include "headers/Matrix4.h"
#include "headers/transformation.h"

int testVec2Implementation() {
    int nrOfErrors = 0;

    std::cout << "Testing Vector2D class" << std::endl;

    Vector2D v1, v2, v3, v4;

    v1.x = 1.0f;
    v2.y = 1.0f;

    v3 = v1 + v2;
    if (v3 == Vector2D(1.0f, 1.0f))
        std::cout << "\tCorrect + operation" << std::endl;
    else {
        std::cout << "\tIncorrect + operation" << std::endl;
        nrOfErrors++;
    }

    v3 += v1;
    if (v3 == Vector2D(2.0f, 1.0f))
        std::cout << "\tCorrect += operation" << std::endl;
    else {
        std::cout << "\tIncorrect += operation" << std::endl;
        nrOfErrors++;
    }

    v3 = Vector2D(2.0f, 1.0f) - v1;
    if (v3 == Vector2D(1.0f, 1.0f))
        std::cout << "\tCorrect - operation" << std::endl;
    else {
        std::cout << "\tIncorrect - operation" << std::endl;
        nrOfErrors++;
    }

    v3 -= v1;
    if (v3 == Vector2D(0.0f, 1.0f))
        std::cout << "\tCorrect -= operation" << std::endl;
    else {
        std::cout << "\tIncorrect -= operation" << std::endl;
        nrOfErrors++;
    }

    v3 = Vector2D(3.0f, 4.0f);
    if (v3.length() == 5.0f)
        std::cout << "\tCorrect length operation" << std::endl;
    else {
        std::cout << "\tIncorrect length operation" << std::endl;
        nrOfErrors++;
    }

    v4 = v3.normalize();
    if (v4 == Vector2D(0.6f, 0.8f))
        std::cout << "\tCorrect normalize operation" << std::endl;
    else {
        std::cout << "\tIncorrect normalize operation" << std::endl;
        nrOfErrors++;
    }

    if (dotProduct(v1, v2) == 0.0f)
        std::cout << "\tCorrect dot product operation" << std::endl;
    else {
        std::cout << "\tIncorrect dot product operation" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}

int testVec3Implementation() {
    int nrOfErrors = 0;

    std::cout << "Testing Vector3D class" << std::endl;

    Vector3D v1, v2, v3, v4;

    v1.x = 1.0f;
    v2.y = 1.0f;

    v3 = v1 + v2;
    if (v3 == Vector3D(1.0f, 1.0f, 0.0f))
        std::cout << "\tCorrect + operation" << std::endl;
    else {
        std::cout << "\tIncorrect + operation" << std::endl;
        nrOfErrors++;
    }

    v3 += v1;
    if (v3 == Vector3D(2.0f, 1.0f, 0.0f))
        std::cout << "\tCorrect += operation" << std::endl;
    else {
        std::cout << "\tIncorrect += operation" << std::endl;
        nrOfErrors++;
    }

    v3 = Vector3D(2.0f, 1.0f, 0.0f) - v1;
    if (v3 == Vector3D(1.0f, 1.0f, 0.0f))
        std::cout << "\tCorrect - operation" << std::endl;
    else {
        std::cout << "\tIncorrect - operation" << std::endl;
        nrOfErrors++;
    }

    v3 -= v1;
    if (v3 == Vector3D(0.0f, 1.0f, 0.0f))
        std::cout << "\tCorrect -= operation" << std::endl;
    else {
        std::cout << "\tIncorrect -= operation" << std::endl;
        nrOfErrors++;
    }

    v3 = Vector3D(2.0f, 4.0f, 4.0f);
    if (v3.length() == 6.0f)
        std::cout << "\tCorrect length operation" << std::endl;
    else {
        std::cout << "\tIncorrect length operation" << std::endl;
        nrOfErrors++;
    }

    v4 = v3.normalize();
    if (v4 == Vector3D(2.0f / 6.0f, 4.0f / 6.0f, 4.0f / 6.0f))
        std::cout << "\tCorrect normalize operation" << std::endl;
    else {
        std::cout << "\tIncorrect normalize operation" << std::endl;
        nrOfErrors++;
    }

    if (dotProduct(v1, v2) == 0.0f)
        std::cout << "\tCorrect dot product operation" << std::endl;
    else {
        std::cout << "\tIncorrect dot product operation" << std::endl;
        nrOfErrors++;
    }

    v4 = crossProduct(v1, v2);
    if (v4 == Vector3D(0.0f, 0.0f, 1.0f))
        std::cout << "\tCorrect cross product operation" << std::endl;
    else {
        std::cout << "\tIncorrect cross product operation" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}

//
int testVec4Implementation() {
    int nrOfErrors = 0;

    std::cout << "Testing Vector4D class" << std::endl;

    Vector4D v1, v2, v3, v4;

    v1.x = 1.0f;
    v2.y = 1.0f;

    v3 = v1 + v2;
    if (v3 == Vector4D(1.0f, 1.0f, 0.0f, 0.0f))
        std::cout << "\tCorrect + operation" << std::endl;
    else {
        std::cout << "\tIncorrect + operation" << std::endl;
        nrOfErrors++;
    }

    v3 += v1;
    if (v3 == Vector4D(2.0f, 1.0f, 0.0f, 0.0f))
        std::cout << "\tCorrect += operation" << std::endl;
    else {
        std::cout << "\tIncorrect += operation" << std::endl;
        nrOfErrors++;
    }

    v3 = Vector4D(2.0f, 1.0f, 0.0f, 0.0f) - v1;
    if (v3 == Vector4D(1.0f, 1.0f, 0.0f, 0.0f))
        std::cout << "\tCorrect - operation" << std::endl;
    else {
        std::cout << "\tIncorrect - operation" << std::endl;
        nrOfErrors++;
    }

    v3 -= v1;
    if (v3 == Vector4D(0.0f, 1.0f, 0.0f, 0.0f))
        std::cout << "\tCorrect -= operation" << std::endl;
    else {
        std::cout << "\tIncorrect -= operation" << std::endl;
        nrOfErrors++;
    }

    v3 = Vector4D(2.0f, 4.0f, 4.0f, 0.0f);
    if (v3.length() == 6.0f)
        std::cout << "\tCorrect length operation" << std::endl;
    else {
        std::cout << "\tIncorrect length operation" << std::endl;
        nrOfErrors++;
    }

    v4 = v3.normalize();
    if (v4 == Vector4D(2.0f / 6.0f, 4.0f / 6.0f, 4.0f / 6.0f, 0.0f))
        std::cout << "\tCorrect normalize operation" << std::endl;
    else {
        std::cout << "\tIncorrect normalize operation" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}

void runVectorTestes() {
    int nrOfErrors = 0;
    std::cout << "\n\nVector testes:\n";
    nrOfErrors += testVec2Implementation();
    nrOfErrors += testVec3Implementation();
    nrOfErrors += testVec4Implementation();

    std::cout << "Number of errors: " << nrOfErrors << std::endl;
}


int testMat3Implementation() {
    int nrOfErrors = 0;

    std::cout << "Testing Matrix3 class" << std::endl;

    float a1[] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f};
    float a2[] = {3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    float a3[] = {4.0f, 0.0f, 0.0f, 0.0f, 4.0f, 0.0f, 1.0f, 1.0f, 2.0f};

    Matrix3 m1(a1), m2(a2), m3(a3), m4;

    m4 = m1 + m2;
    if (m4 == m3)
        std::cout << "\tCorrect + operation" << std::endl;
    else {
        std::cout << "\tIncorrect + operation" << std::endl;
        nrOfErrors++;
    }

    float a5[] = {3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 3.0f, 3.0f, 3.0f};
    Matrix3 m5(a5);

    m4 = m1 * 3.0f;
    if (m4 == m5)
        std::cout << "\tCorrect * (with scalar value) operation" << std::endl;
    else {
        std::cout << "\tIncorrect * (with scalar value) operation" << std::endl;
        nrOfErrors++;
    }

    float a6[] = {3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 1.0f, 1.0f};
    Matrix3 m6(a6);

    m4 = m1 * m2;
    if (m4 == m6)
        std::cout << "\tCorrect * (with another matrix) operation" << std::endl;
    else {
        std::cout << "\tIncorrect * (with another matrix) operation" << std::endl;
        nrOfErrors++;
    }

    Vector3D v1(1.0f, 1.0f, 1.0f);
    Vector3D v2(4.0f, 4.0f, 1.0f);
    Vector3D v3;

    v3 = m4 * v1;
    if (v3 == v2)
        std::cout << "\tCorrect * (with a Vector3D) operation" << std::endl;
    else {
        std::cout << "\tIncorrect * (with a Vector3D) operation" << std::endl;
        nrOfErrors++;
    }

    float a7[] = {-4.0f, 0.0f, 1.0f, -3.0f, 2.0f, 4.0f, 3.0f, -2.0f, -1.0f};
    Matrix3 m7(a7);

    if (std::abs(m7.determinant() + 24.0f) < std::numeric_limits<float>::epsilon())
        std::cout << "\tCorrect determinant operation" << std::endl;
    else {
        std::cout << "\tIncorrect determinant operation" << std::endl;
        nrOfErrors++;
    }

    float a8[] = {-4.0f, -3.0f, 3.0f, 0.0f, 2.0f, -2.0f, 1.0f, 4.0f, -1.0f};
    Matrix3 m8(a8);

    if (m7.transpose() == m8)
        std::cout << "\tCorrect transpose operation" << std::endl;
    else {
        std::cout << "\tIncorrect transpose operation" << std::endl;
        nrOfErrors++;
    }

    float a9[] = {-1.0f / 4.0f, 1.0f / 12.0f, 1.0f / 12.0f, -3.0f / 8.0f, -1.0f / 24.0f, -13.00f / 24.0f, 0.0f,
                  1.0f / 3.0f, 1.0f / 3.0f};
    Matrix3 m9(a9);

    if (m7.inverse() == m9)
        std::cout << "\tCorrect inverse operation" << std::endl;
    else {
        std::cout << "\tIncorrect inverse operation" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}

int testMat4Implementation() {
    int nrOfErrors = 0;

    std::cout << "Testing mat4 class" << std::endl;

    float a1[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    float a2[] = {3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    float a3[] = {4.0f, 0.0f, 0.0f, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f, 0.0f, 0.0f, 4.0f, 0.0f, 1.0f, 1.0f, 1.0f, 2.0f};

    Matrix4 m1(a1), m2(a2), m3(a3), m4;

    m4 = m1 + m2;
    if (m4 == m3)
        std::cout << "\tCorrect + operation" << std::endl;
    else {
        std::cout << "\tIncorrect + operation" << std::endl;
        nrOfErrors++;
    }

    float a5[] = {3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 3.0f, 3.0f, 3.0f, 3.0f};
    Matrix4 m5(a5);

    m4 = m1 * 3.0f;
    if (m4 == m5)
        std::cout << "\tCorrect * (with scalar value) operation" << std::endl;
    else {
        std::cout << "\tIncorrect * (with scalar value) operation" << std::endl;
        nrOfErrors++;
    }

    float a6[] = {3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    Matrix4 m6(a6);

    m4 = m1 * m2;
    if (m4 == m6)
        std::cout << "\tCorrect * (with another matrix) operation" << std::endl;
    else {
        std::cout << "\tIncorrect * (with another matrix) operation" << std::endl;
        nrOfErrors++;
    }

    Vector4D v1(1.0f, 1.0f, 1.0f, 1.0f);
    Vector4D v2(4.0f, 4.0f, 4.0f, 1.0f);
    Vector4D v3;

    v3 = m4 * v1;
    if (v3 == v2)
        std::cout << "\tCorrect * (with a Vector4D) operation" << std::endl;
    else {
        std::cout << "\tIncorrect * (with a Vector4D) operation" << std::endl;
        nrOfErrors++;
    }


    float a7[] = {3.0f, 4.0f, 3.0f, 9.0f, 2.0f, 0.0f, 0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 1.0f, 1.0f};
    Matrix4 m7(a7);

    if (std::abs(m7.determinant() - 24.0f) < std::numeric_limits<float>::epsilon())
        std::cout << "\tCorrect determinant operation" << std::endl;
    else {
        std::cout << "\tIncorrect determinant operation" << std::endl;
        nrOfErrors++;
    }

    float a8[] = {3.0f, 2.0f, 0.0f, 1.0f, 4.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 2.0f, 1.0f, 9.0f, 2.0f, 3.0f, 1.0f};
    Matrix4 m8(a8);

    if (m7.transpose() == m8)
        std::cout << "\tCorrect transpose operation" << std::endl;
    else {
        std::cout << "\tIncorrect transpose operation" << std::endl;
        nrOfErrors++;
    }

    float a9[] = {-1.0f / 4.0f, 2.0f / 3.0f, 1.0f / 6.0f, 5.0f / 12.0f, 1.0f / 4.0f, -1.0f / 2.0f, -1.0 / 2.0f,
                  1.0f / 4.0f, -1.0f / 2.0f, 1.0f / 2.0f, 1.0f, 1.0f / 2.0f, 1.0f / 4.0f, -1.0f / 6.0f, -1.0 / 6.0f,
                  -5.0f / 12.0f};
    Matrix4 m9(a9);

    if (m7.inverse() == m9)
        std::cout << "\tCorrect inverse operation" << std::endl;
    else {
        std::cout << "\tIncorrect inverse operation" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}


void runMatrixTestes() {
    int nrOfErrors = 0;
    std::cout << "\n\nMatrix testes:\n";
    nrOfErrors += testMat3Implementation();
    nrOfErrors += testMat4Implementation();

    std::cout << "Number of errors: " << nrOfErrors << std::endl;
}


int test2DTransformImplementation()
{
    int nrOfErrors = 0;

    std::cout << "Testing 2D Tranformations" << std::endl;

    float a2[] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 3.0f, 1.0f};

    Matrix3 m1, m2(a2);

    m1 = translate(Vector2D(2.0f, 3.0f));
    if(m1 == m2)
        std::cout << "\tCorrect translate matrix (by vec2)" << std::endl;
    else
    {
        std::cout << "\tIncorrect translate matrix (by vec2)" << std::endl;
        nrOfErrors++;
    }

    m1 = translate(2.0f, 3.0f);
    if(m1 == m2)
        std::cout << "\tCorrect translate matrix (by values)" << std::endl;
    else
    {
        std::cout << "\tIncorrect translate matrix (by values)" << std::endl;
        nrOfErrors++;
    }

    float a3[] = {3.0f, 0.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Matrix3 m3(a3);

    m1 = scale(Vector2D(3.0f, 2.0f));
    if(m1 == m3)
        std::cout << "\tCorrect scale matrix (by vec2)" << std::endl;
    else
    {
        std::cout << "\tIncorrect scale matrix (by vec2)" << std::endl;
        nrOfErrors++;
    }

    m1 = scale(3.0f, 2.0f);
    if(m1 == m3)
        std::cout << "\tCorrect scale matrix (by values)" << std::endl;
    else
    {
        std::cout << "\tIncorrect scale matrix (by values)" << std::endl;
        nrOfErrors++;
    }

    float a4[] = {0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Matrix3 m4(a4);

    m1 = rotate(90.0f);
    if(m1 == m4)
        std::cout << "\tCorrect rotate matrix" << std::endl;
    else
    {
        std::cout << "\tIncorrect rotate matrix" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}

int test3DTransformImplementation()
{
    int nrOfErrors = 0;

    std::cout << "Testing 3D Tranformations" << std::endl;

    float a2[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 3.0f, 3.0f, 1.0f};

    Matrix4 m1, m2(a2);

    m1 = translate(Vector3D(2.0f, 3.0f, 3.0f));
    if(m1 == m2)
        std::cout << "\tCorrect translate matrix (by vec3)" << std::endl;
    else
    {
        std::cout << "\tIncorrect translate matrix (by vec3)" << std::endl;
        nrOfErrors++;
    }

    m1 = translate(2.0f, 3.0f, 3.0f);
    if(m1 == m2)
        std::cout << "\tCorrect translate matrix (by values)" << std::endl;
    else
    {
        std::cout << "\tIncorrect translate matrix (by values)" << std::endl;
        nrOfErrors++;
    }

    float a3[] = {3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Matrix4 m3(a3);

    m1 = scale(Vector3D(3.0f, 2.0f, 3.0f));
    if(m1 == m3)
        std::cout << "\tCorrect scale matrix (by vec3)" << std::endl;
    else
    {
        std::cout << "\tIncorrect scale matrix (by vec3)" << std::endl;
        nrOfErrors++;
    }

    m1 = scale(3.0f, 2.0f, 3.0f);
    if(m1 == m3)
        std::cout << "\tCorrect scale matrix (by values)" << std::endl;
    else
    {
        std::cout << "\tIncorrect scale matrix (by values)" << std::endl;
        nrOfErrors++;
    }

    float a4[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Matrix4 m4(a4);

    m1 = rotateX(90.0f);
    if(m1 == m4)
        std::cout << "\tCorrect rotate matrix around X" << std::endl;
    else
    {
        std::cout << "\tIncorrect rotate matrix around X" << std::endl;
        nrOfErrors++;
    }

    float a5[] = {0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Matrix4 m5(a5);

    m1 = rotateY(90.0f);
    if(m1 == m5)
        std::cout << "\tCorrect rotate matrix around Y" << std::endl;
    else
    {
        std::cout << "\tIncorrect rotate matrix around Y" << std::endl;
        nrOfErrors++;
    }

    float a6[] = {0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Matrix4 m6(a6);

    m1 = rotateZ(90.0f);
    if(m1 == m6)
        std::cout << "\tCorrect rotate matrix around Z" << std::endl;
    else
    {
        std::cout << "\tIncorrect rotate matrix around Z" << std::endl;
        nrOfErrors++;
    }

    return nrOfErrors;
}

void runTransformationTestes() {
    int nrOfErrors = 0;
    std::cout << "\n\nTransformation testes:\n";
    nrOfErrors += test2DTransformImplementation();
    nrOfErrors += test3DTransformImplementation();

    std::cout << "Number of errors: " << nrOfErrors << std::endl;
}

