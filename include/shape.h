/* 
 * File:   shape.h
 * Author: Pouyan Heyratpour
 * Email: P.Heyratpour@Gmail.Com
 *
 * Created on January 28, 2013, 4:14 AM
 */

#ifndef SHAPE_H
#define	SHAPE_H

#define PI 3.141592654
#define MIN_ERR 1E-4

class shape{
public:
	shape();
	
    void draw();
    double area();
    double perimeter();
};

/**
 * ******************************
 *                              *
 *             ELLIPSE          *
 *                              *
 * ******************************
 */

class ellipse: public shape{
public:
    ellipse(double, double);

    void draw();
    double area();
    double perimeter();
    
    bool setMinor(double);
    double getMinor();
    
    bool setMajor(double);
    double getMajor();
protected:
    double __minor;
    double __major;
};

/**
 * ******************************
 *                              *
 *           CIRCLE             *
 *                              *
 * ******************************
 */

class circle: public ellipse{
public:
    circle(double);
    
    bool setRadius(double);
    double getRadius();
};

//class polygon: public shape{
//public:
//    triangle(double*, double*);
//
//    virtual void draw();
//    virtual double area();
//    virtual double perimeter();
//    
//protected:
//    double* sides;
//    double* angles;
//};

/**
 * ******************************
 *                              *
 *            TIRANGLE          *
 *                              *
 * ******************************
 */

class triangle: public shape{
public:
	triangle();
    triangle(double*, double*);

    void draw();
    double area();
    double perimeter();
    
    void getSides(double**);
    void getAngles(double**);
    
    bool setSidesAndAngles(double*, double*);
    
protected:
    double* __sides;
    double* __angles;
    
    double __height;
    double __width;
    
    double __getHeight();
    double __getWidth();
    
    void __calculateHeightAndWidth();
};

/**
 * ******************************
 *                              *
 *           ISOSCELES          *
 *                              *
 * ******************************
 */

class isosceles: public triangle{
public:
    isosceles(double, double);
    
    bool setHeadAngle(double);
    double getHeadAngle();
    
    bool setLegsMagnitude(double);
    double getLegsMagnitude();
};

/**
 * ******************************
 *                              *
 *          EQUILATERAL         *
 *                              *
 * ******************************
 */

class equilateral: public isosceles{
public:
    equilateral(double);
    
    bool setSidesMagnitude(double);
    double getSidesMagnitude();
};

/**
 * ******************************
 *                              *
 *          QUADRILATERAL       *
 *            TRAPEZOID         *
 *                              *
 * ******************************
 */

class trapezoid: public shape{
public:
	trapezoid();
    trapezoid(double, double*, double*);
    
    void draw();
    double area();
    double perimeter();
    
    bool setSidesAndAngles(double*, double*);
    
    void getSides(double**);
    void getAngles(double**);
    
protected:
    double* __sides;
    double* __angles;
    
    double __height;
    double __width;
    
    virtual void __calculateHeightAndWidth();
};

/**
 * ******************************
 *                              *
 *          PARALLELOGRAM       *
 *                              *
 * ******************************
 */

class parallelogram: public trapezoid{
public:
    parallelogram(double, double, double);
    parallelogram();
    
    double area();
    
protected:
    void __calculateHeightAndWidth();
};

/**
 * ******************************
 *                              *
 *            RHOMBUS           *
 *                              *
 * ******************************
 */

class rhombus: public parallelogram{
public:
    rhombus(double, double);
    
    bool setHeightAndWidth(double, double);
    
    double getHeight();
    double getWidth();
    
    double area();
    
protected:
    void __calculateHeightAndWidth();
    void __calculateSidesAndAngles();
};

/**
 * ******************************
 *                              *
 *          RECTANGLE           *
 *                              *
 * ******************************
 */

class rectangle: public parallelogram{
public:
    rectangle(double, double);
};

/**
 * ******************************
 *                              *
 *            SQUARE            *
 *                              *
 * ******************************
 */

class square: public rectangle{
public:
    square(double);
};

#endif	/* SHAPE_H */
