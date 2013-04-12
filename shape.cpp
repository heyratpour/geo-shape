/* 
 * File:   shape.cpp
 * Author: Pouyan Heyratpour
 * Email: P.Heyratpour@Gmail.Com
 * 
 * Created on January 28, 2013, 4:14 AM
 */

#include "shape.h"
#include <cmath>
#define PI 3.141592654
#define MIN_ERR 1E-4* Author: Marziye

#include <stdio.h>

using namespace std;

/**
 * ******************************
 *                              *
 *            SHAPE             *
 *                              *
 * ******************************
 */
 
 shape::shape(){
	 return;
 }

/**
 * ******************************
 *                              *
 *             ELLIPSE          *
 *                              *
 * ******************************
 */

ellipse::ellipse(double minor, double major) : shape(){
    this->setMajor(major);
    this->setMinor(minor);
    
    return;
}

void ellipse::draw(){
}

double ellipse::area(){
    double result;
    
    result = PI*this->__minor*this->__major;
    
    return result;
}

double ellipse::perimeter(){
    double result;
    
    if(this->__minor == this->__major){
        result = 2*PI*this->__minor;
    }
    else{
        result = 0;
    }
    
    return result;
}

bool ellipse::setMinor(double minor){
    bool isValid = true;
    
    if(isValid){
        this->__minor = minor;
    }
    
    return isValid;
}

double ellipse::getMinor(){
    return this->__minor;
}

bool ellipse::setMajor(double major){
    bool isValid = true;
    
    if(isValid){
        this->__major = major;
    }
    
    return isValid;
}

double ellipse::getMajor(){
    return this->__major;
}

/**
 * ******************************
 *                              *
 *            Circle            *
 *                              *
 * ******************************
 */

circle::circle(double radius) : ellipse(radius, radius){
    return;
}
    
bool circle::setRadius(double radius){
    return this->setMajor(radius) && this->setMinor(radius);
}

double circle::getRadius(){
    return this->getMajor();
}

/**
 * ******************************
 *                              *
 *            TIRANGLE          *
 *                              *
 * ******************************
 */

triangle::triangle() : shape(){
	this->__sides = new double[3];
	this->__angles = new double[3];
	return;
}

triangle::triangle(double* sides, double* angles) : triangle(){
    this->setSidesAndAngles(sides, angles);
    
    return;
}

void triangle::draw(){
}

double triangle::area(){
    double result;
    
    result = 0.5*this->__height*this->__width;
    
    return result;
}

double triangle::perimeter(){
    double result=0;
    
    for(int i=0; i<3; i++){
        result += this->__sides[i];
    }
    
    return result;
}

bool triangle::setSidesAndAngles(double* sides, double* angles){
    bool isValid = (sides[0]+sides[1] > sides[2]) && (abs(angles[0]+angles[1]+angles[2] - PI) < MIN_ERR);
    
    if(isValid){
        for(int i=0; i<3; i++){
			this->__sides[i] = sides[i];
			this->__angles[i] = angles[i];
		}
        
        this->__calculateHeightAndWidth();
    }
    
    return isValid;
}

void triangle::getSides(double** sides){
    *sides = this->__sides;
    return;
}

void triangle::getAngles(double** angles){
    *angles = this->__angles;
    return;
}

double triangle::__getHeight(){
    return this->__height;
}

double triangle::__getWidth(){
    return this->__width;
}

void triangle::__calculateHeightAndWidth(){
    this->__width = this->__sides[1];
    this->__height = this->__sides[0]*sin(this->__angles[1]);
}

/**
 * ******************************
 *                              *
 *           ISOSCELES          *
 *                              *
 * ******************************
 */

isosceles::isosceles(double legsMagnitude, double headAngle) : triangle(){
    this->setLegsMagnitude(legsMagnitude);
    this->setHeadAngle(headAngle);
    
    return;
}
    
bool isosceles::setHeadAngle(double headAngle){
    bool isValid = (headAngle <= PI);
    
    if(isValid){
        double* angles;
        this->getAngles(&angles);
        
        double* sides;
        this->getSides(&sides);
        
        angles[0] = headAngle;
        angles[1] = (PI-headAngle)/2;
        angles[2] = (PI-headAngle)/2;
        sides[1] = 2*sides[0]*sin(headAngle/2);
        
        this->setSidesAndAngles(sides, angles);
    }
    
    return isValid;
}

double isosceles::getHeadAngle(){
    return this->__angles[0];
}

bool isosceles::setLegsMagnitude(double legsMagnitude){
    bool isValid = true;
    
    if(isValid){
        double* angles;
        this->getAngles(&angles);
        
        double* sides;
        this->getSides(&sides);
        
        sides[2] = legsMagnitude;
        sides[0] = legsMagnitude;
        angles[0] = 2*asin(sides[1]/(2*legsMagnitude));
        
        this->setSidesAndAngles(sides, angles);
    }
    
    return isValid;
}

double isosceles::getLegsMagnitude(){
    return this->__sides[0];
}

/**
 * ******************************
 *                              *
 *          EQUILATERAL         *
 *                              *
 * ******************************
 */

equilateral::equilateral(double sidesMagnitude) : isosceles(sidesMagnitude, PI/3){
    return;
}
    
bool equilateral::setSidesMagnitude(double sidesMagnitude){
	double sides[3] = {sidesMagnitude, sidesMagnitude, sidesMagnitude};
	double angles[3] = {PI/3, PI/3, PI/3};
    return this->setSidesAndAngles(sides, angles);
}

double equilateral::getSidesMagnitude(){
    return this->__sides[0];
}

/**
 * ******************************
 *                              *
 *            TRAPEZOID         *
 *                              *
 * ******************************
 */
 
trapezoid::trapezoid() : shape(){
	this->__sides = new double[4];
	this->__angles = new double[4];
	return;
}

trapezoid::trapezoid(double bottomSide, double* legs, double* legsAngles) : trapezoid(){
	double angles[4] = {PI-legsAngles[0], legsAngles[0], legsAngles[1], PI-legsAngles[1]};
	double sides[4] = {legs[0], bottomSide, legs[1], bottomSide-((legs[0]*cos(legsAngles[0]))+(legs[1]*cos(legsAngles[1])))};
	
    this->setSidesAndAngles(sides, angles);
    
    return;
}
    
void trapezoid::draw(){
}

double trapezoid::area(){
    double result;
    
    result = 0.5*this->__height*this->__width;
    
    return result;
}

double trapezoid::perimeter(){
    double result=0;
    
    for(int i=0; i<4; i++){
        result += this->__sides[i];
    }
    
    return result;
}

bool trapezoid::setSidesAndAngles(double* sides, double* angles){
    bool isValid = (abs(angles[0]+angles[1]+angles[2]+angles[3] - 2*PI) < MIN_ERR) && (abs(PI - angles[0] - angles[1]) < MIN_ERR) && (abs(PI - angles[2] - angles[3]) < MIN_ERR) && (abs(sides[3] - (sides[1] - ((sides[0]*cos(angles[1])) + (sides[2]*cos(angles[2]))))) < MIN_ERR) && (abs(sides[0]*sin(angles[1]) - sides[2]*sin(angles[2])) < MIN_ERR);
    
    if(isValid){
		for(int i=0; i<4; i++){
			this->__sides[i] = sides[i];
			this->__angles[i] = angles[i];
		}
        
        this->__calculateHeightAndWidth();
    }
    
    return isValid;
}

void trapezoid::getSides(double** sides){
    *sides = this->__sides;
    
    return;
}

void trapezoid::getAngles(double** angles){
    *angles = this->__angles;
    
    return;
}

void trapezoid::__calculateHeightAndWidth(){
    this->__width = this->__sides[1]+this->__sides[3];
    this->__height = this->__sides[0]*sin(this->__angles[1]);
}

/**
 * ******************************
 *                              *
 *          PARALLELOGRAM       *
 *                              *
 * ******************************
 */

parallelogram::parallelogram(double vSide, double hSide, double minorAngle) : trapezoid(){
	double sides[4] = {vSide, hSide, vSide, hSide};
	double angles[4] = {minorAngle, PI-minorAngle, minorAngle, PI-minorAngle};
	this->setSidesAndAngles(sides, angles);
    return;
}

parallelogram::parallelogram() : trapezoid(){
	return;
}
    
double parallelogram::area(){
    double result;
    
    result = this->__height*this->__width;
    
    return result;
}

void parallelogram::__calculateHeightAndWidth(){
    this->__width = this->__sides[1];
    this->__height = this->__sides[0]*sin(this->__angles[1]);
}

/**
 * ******************************
 *                              *
 *            RHOMBUS           *
 *                              *
 * ******************************
 */

rhombus::rhombus(double height, double width) : parallelogram(){
    this->setHeightAndWidth(height, width);
    
    return;
}
    
double rhombus::area(){
    double result;
    
    result = 0.5*this->__height*this->__width;
    
    return result;
}

bool rhombus::setHeightAndWidth(double height, double width){
    bool isValid = (height > 0) and (width > 0);
    
    if(isValid){
        this->__height = height;
        this->__width = width;
        
        this->__calculateSidesAndAngles();
    }
    
    return isValid;
}

double rhombus::getHeight(){
    return this->__height;
}

double rhombus::getWidth(){
    return this->__width;
}

void rhombus::__calculateHeightAndWidth(){
    this->__width = 2*this->__sides[0]*sin(this->__angles[0]/2);
    this->__height = 2*this->__sides[0]*sin(this->__angles[1]/2);
}

void rhombus::__calculateSidesAndAngles(){
    double side = sqrt(this->__height*this->__height + this->__width*this->__width)/2;
    double majorAngle = 2*(asin(this->__height/(2*side)));
    double minorAngle = 2*(asin(this->__width/(2*side)));
    
    double sides[4] = {side, side, side, side};
    double angles[4] = {minorAngle, majorAngle, minorAngle, majorAngle};
    
    for(int i=0; i<4; i++){
		this->__sides[i] = sides[i];
		this->__angles[i] = angles[i];
	}
}

/**
 * ******************************
 *                              *
 *          RECTANGLE           *
 *                              *
 * ******************************
 */

rectangle::rectangle(double height, double width) : parallelogram(height, width, PI/2){
    return;
}

/**
 * ******************************
 *                              *
 *            SQUARE            *
 *                              *
 * ******************************
 */

square::square(double side) : rectangle(side, side){
    return;
}
