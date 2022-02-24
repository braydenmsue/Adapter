#pragma once
#include <iostream>
#include "Display.h"
#include "PS_Adaptee.h"

class PS_Display: public Display {
	public:
		PS_Display(std::ostream& p):adaptee(p){// Passes ostream& to PS_adaptee adaptee
			psWidth = 1; //intialize default width to 1
			psShape = SQUARE; // default shape is square
			psColour = BLACK; // default colour is black
		}; 
		void start();			// call to start a drawing
		void color(Color col);	// all edges and vertices after this are this color
		void shape(Shape s);	// all vertices after this are this shape
		void width(int w);		// all edges after this are this width; all vertices bounding box is twice this width
		void edge(double x1, double y1, double x2, double y2);		// draws an edge from (x1, y1) to (x2, y2)
		void vertex(double x, double y);		// draws a vertex centered at x, y
		void end();			// call to end the drawing

	private:
		PS_adaptee adaptee;
		double psWidth;
		Shape psShape;
		Color psColour;

};
