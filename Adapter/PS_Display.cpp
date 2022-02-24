
#include "PS_Display.h"

using namespace std;

void PS_Display::start()// starts at (0,0) then makes a 10x10 square and fills it in
{
    adaptee.moveto(0,0);
    adaptee.lineto(10,0);
    adaptee.lineto(10,10);
    adaptee.lineto(0,10);
    adaptee.lineto(0,0);
    adaptee.setrgbcolor(0.8,0.8,0.8);
    adaptee.fill();
}

void PS_Display::color(Color col)// sets psColour to col then calls setrgbcolour() accordingly
{
    psColour = col;
    if (psColour == RED){
        adaptee.setrgbcolor(1,0,0);
    }
    else if (psColour == GREEN){
        adaptee.setrgbcolor(0,1,0);
    }

    else if (psColour == BLUE){
        adaptee.setrgbcolor(0,0,1);
    }

    else if (psColour == CYAN){ // mix of green and blue
        adaptee.setrgbcolor(0,1,1);
    }

    else if (psColour == MAGENTA){ // red and blue
        adaptee.setrgbcolor(1,0,1);
    }

    else if (psColour == YELLOW){ // red and green
        adaptee.setrgbcolor(1,1,0);
    }

    else if (psColour == WHITE){
        adaptee.setrgbcolor(1,1,1);
    }

    else if (psColour== BLACK){
        adaptee.setrgbcolor(0,0,0);
    }    
    
}

void PS_Display::shape(Shape s)	// all vertices after this are this shape
{
    psShape = s;
}

void PS_Display::width(int w)// all edges after this are this width; all vertices bounding box is twice this width
{
    adaptee.setlinewidth(0.03*w); // calls setlinewidth() with 0.03w as per assignment instructions
    psWidth = 0.03*w; //updates psWidth

}

void PS_Display::edge(double x1, double y1, double x2, double y2)// draws an edge from (x1, y1) to (x2, y2)
{
    // x and y multiplied by 10 as per assignment instructions
    adaptee.newpath();
    adaptee.moveto(10*x1,10*y1);
    adaptee.lineto(10*x2,10*y2);
    adaptee.stroke();
    adaptee.closepath();

}

void PS_Display::vertex(double x, double y)	// draws a vertex centered at 10x, 10y
{

    if (psShape == CIRCLE){ //arc centered at (x,y), radius of 2w, circle is from 0 - 360 degrees
        adaptee.arc(x*10,y*10, 2*psWidth,0,360); 
        adaptee.fill();
        adaptee.closepath();

    }

    else if (psShape==TRIANGLE){
        /*
            Triangle centered at (x,y). Triangle shares bottom edge with square, therefore base = 4w.
            Bottom left corner relative to center (2w,2w) is (-2w,-2w). Top is 2w above center, height is 4w.
            Coordinates of top corner is (x,(y+2w)). Line back to bottom left corner completes triangle.
        */
        adaptee.moveto(x*10,y*10);
        adaptee.rmoveto(-2*psWidth, -2*psWidth);
        adaptee.rlineto(4*psWidth, 0);
        adaptee.lineto(10*x, (10*y)+(2*psWidth));
        adaptee.lineto((10*x)-(2*psWidth), (10*y)-(2*psWidth));
        adaptee.fill();
        adaptee.closepath();

    }

    else if(psShape == SQUARE){ // draws 4w x 4w square
        adaptee.moveto(10*x,10*y);
        adaptee.rmoveto(-2*psWidth, -2*psWidth);
        adaptee.rlineto(4*psWidth, 0);
        adaptee.rlineto(0,4*psWidth);
        adaptee.rlineto(-4*psWidth, 0);
        adaptee.rlineto(0,-4*psWidth);
        adaptee.fill();
    }
}

void PS_Display::end() // call to end the drawing
{
    adaptee.showpage();
}			