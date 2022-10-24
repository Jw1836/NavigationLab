// *******************************************************************************
//
//  You don't need to look at or modify any of this code.
//  If you are getting hung up trying to figure out what this code does, STOP.
//    Do not worry about this code unless you are trying to understand something
//    outside of the lab.
//
// *******************************************************************************


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

#define DIMX    500
#define DIMY    500

#define MARGIN  40

struct Punto {
    int x, y;
};

int zero[9][7] = {{0,0,0,0,0,0,0},
                    {0,0,1,1,1,0,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,0,1,1,1,0,0},
                    {0,0,0,0,0,0,0}};

int one[9][7] = {{0,0,0,0,0,0,0},
                    {0,0,1,1,1,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,0,0,0,0,0,0}};

int two[9][7] = {{0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,1,0,0,0,0,0},
                    {0,1,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0}};

int three[9][7] = {{0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0},
                    {0,0,1,1,1,0,0},
                    {0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0}};

int four[9][7] = {{0,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0},
                    {0,1,1,1,1,1,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,0,0,0,0,0}};

int five[9][7] = {{0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,1,0,0,0,0,0},
                    {0,1,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0}};

int six[9][7] = {{0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,1,0,0,0,0,0},
                    {0,1,0,0,0,0,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0}};

int seven[9][7] = {{0,0,0,0,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0}};

int eight[9][7] = {{0,0,0,0,0,0,0},
                    {0,0,1,1,1,0,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,0,1,1,1,0,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,0,1,1,1,0,0},
                    {0,0,0,0,0,0,0}};

int nine[9][7] = {{0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0},
                    {0,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0}};

// These are the functions implemented this file
void writeImage2File(queue<int> thePath, string _mapName);
void drawPath(double*** theImage, queue<int> thePath);
void drawConnections(double*** theImage);
void drawNodes(double*** theImage);
void drawSquare(double*** theImage, int x, int y, int w, double r, double g, double b);
void drawSegment(double*** theImage, int x1, int y1, int x2, int y2, int w, double r, double g, double b);
void readMap(string _mapName);
void writeBMPFile(double*** theImage);

void writeCost(int num, double*** theImage, int x1, int y1, int x2, int y2);
void drawNumber(int num, int x, int y, double scale, double*** theImage);
void drawDigit(int num, int x, int y, double scale, double*** theImage);
void copyDigit(int digit[9][7], int num[9][7]);


// Some global variables :-)
vector<Punto> theCoords;
vector< vector<int> > theCosts;


void writeImage2File(queue<int> thePath, string _mapName) {
    readMap(_mapName);

    double ***theImage = new double**[DIMX];

    // give the image background
    for (int i = 0; i < DIMX; i++) {
        theImage[i] = new double*[DIMY];
        for (int j = 0; j < DIMX; j++) {
            theImage[i][j] = new double[3];
            theImage[i][j][0] = 0.95;
            theImage[i][j][1] = 0.95;
            theImage[i][j][2] = 0.95;
        }
    }


    drawPath(theImage, thePath);
    drawConnections(theImage);
    drawNodes(theImage);

    writeBMPFile(theImage);

    for (int i = 0; i < DIMX; i++) {
        for (int j = 0; j < DIMX; j++) {
            delete[] theImage[i][j];
        }
        delete[] theImage[i];
    }
    delete[] theImage;
}

void drawPath(double*** theImage, queue<int> thePath) {
    int xmin = 99999, xmax = -99999, ymin = 99999, ymax = -99999;

    for (int i = 0; i < theCoords.size(); i++) {
        if (theCoords[i].x > xmax)
            xmax = theCoords[i].x;
        if (theCoords[i].x < xmin)
            xmin = theCoords[i].x;
        if (theCoords[i].y > ymax)
            ymax = theCoords[i].y;
        if (theCoords[i].y < ymin)
            ymin = theCoords[i].y;
    }

    if (thePath.empty())
        return;

    int nuevo, cur;
    cur = thePath.front();
    thePath.pop();
    while (!thePath.empty()) {
        nuevo = thePath.front();
        thePath.pop();
        double c1x = ((double)(theCoords[cur].x - xmin) / (double)(xmax - xmin)) * (DIMX - MARGIN*2) + MARGIN;
        double c1y = DIMY - (((double)(theCoords[cur].y - ymin) / (double)(ymax - ymin)) * (DIMY - MARGIN*2) + MARGIN);
        double c2x = ((double)(theCoords[nuevo].x - xmin) / (double)(xmax - xmin)) * (DIMX - MARGIN*2) + MARGIN;
        double c2y = DIMY - (((double)(theCoords[nuevo].y - ymin) / (double)(ymax - ymin)) * (DIMY - MARGIN*2) + MARGIN);

        drawSegment(theImage, c1x, c1y, c2x, c2y, 7, 0.2, 1.0, 0.2);

        cur = nuevo;
    }

}

void drawConnections(double*** theImage) {
    int xmin = 99999, xmax = -99999, ymin = 99999, ymax = -99999;

    for (int i = 0; i < theCoords.size(); i++) {
        if (theCoords[i].x > xmax)
            xmax = theCoords[i].x;
        if (theCoords[i].x < xmin)
            xmin = theCoords[i].x;
        if (theCoords[i].y > ymax)
            ymax = theCoords[i].y;
        if (theCoords[i].y < ymin)
            ymin = theCoords[i].y;
    }

    int cmax = 0, cmin = 99999;
    for (int i = 0; i < theCoords.size(); i++) {
        for (int j = 0; j < theCoords.size(); j++) {
            if (theCosts[i][j] >= 0) {
                if (cmin > theCosts[i][j])
                    cmin = theCosts[i][j];
                if (cmax < theCosts[i][j])
                    cmax = theCosts[i][j];
            }
        }
    }

    double c;
    double base = 0.3;
    for (int i = 0; i < theCoords.size(); i++) {
        for (int j = 0; j < theCoords.size(); j++) {
            if (theCosts[i][j] >= 0) {
                double c1x = ((double)(theCoords[i].x - xmin) / (double)(xmax - xmin)) * (DIMX - MARGIN*2) + MARGIN;
                double c1y = DIMY - (((double)(theCoords[i].y - ymin) / (double)(ymax - ymin)) * (DIMY - MARGIN*2) + MARGIN);
                double c2x = ((double)(theCoords[j].x - xmin) / (double)(xmax - xmin)) * (DIMX - MARGIN*2) + MARGIN;
                double c2y = DIMY - (((double)(theCoords[j].y - ymin) / (double)(ymax - ymin)) * (DIMY - MARGIN*2) + MARGIN);

                if (cmax == cmin)
                    c = 0.0;
                else
                    c = (double)(theCosts[i][j] - cmin) / (double)(cmax - cmin);

                double r = 0.0; //1.0 * c + base * (1-c);
                double g = 0.0; //base;
                double b = 0.0; //base * c + 1.0 * (1-c);

                drawSegment(theImage, c1x, c1y, c2x, c2y, 1, r, g, b);

                if (i < j)
                    writeCost(theCosts[i][j], theImage, c1x, c1y, c2x, c2y);
            }
        }
    }
}

void drawNodes(double*** theImage) {
    int xmin = 99999, xmax = -99999, ymin = 99999, ymax = -99999;

    for (int i = 0; i < theCoords.size(); i++) {
        if (theCoords[i].x > xmax)
            xmax = theCoords[i].x;
        if (theCoords[i].x < xmin)
            xmin = theCoords[i].x;
        if (theCoords[i].y > ymax)
            ymax = theCoords[i].y;
        if (theCoords[i].y < ymin)
            ymin = theCoords[i].y;
    }

    // cout << "xmax: " << xmax << endl;
    // cout << "ymax: " << xmin << endl;
    // cout << "xmin: " << ymax << endl;
    // cout << "ymin: " << ymin << endl;

    for (int i = 0; i < theCoords.size(); i++) {
        double cx = ((double)(theCoords[i].x - xmin) / (double)(xmax - xmin)) * (DIMX - MARGIN*2) + MARGIN;
        double cy = DIMY - (((double)(theCoords[i].y - ymin) / (double)(ymax - ymin)) * (DIMY - MARGIN*2) + MARGIN);

        //theImage[(int)cx][(int)cy][0] = 0.0;
        //theImage[(int)cx][(int)cy][1] = 0.0;
        //theImage[(int)cx][(int)cy][2] = 0.0;
        drawSquare(theImage, (int)cx, (int)cy, 3, 0.0, 0.0, 0.0);
    }

}

void drawSquare(double*** theImage, int x, int y, int w, double r, double g, double b) {
    for (int i = x - (w+1)/2; i <= x + (w+1)/2; i++) {
        for (int j = y - (w+1)/2; j <= y + (w+1)/2; j++) {
            theImage[i][j][0] = r;
            theImage[i][j][1] = g;
            theImage[i][j][2] = b;
        }
    }
}

void drawSegment(double*** theImage, int x1, int y1, int x2, int y2, int w, double r, double g, double b) {
    double inc = 0.001;
    double x, y, cx, cy;
    for (double t = 0.0; t <= 1.0; t += inc) {
        x = t * x1 + (1.0 - t) * x2;
        y = t * y1 + (1.0 - t) * y2;
        cx = (int)(x + 0.5);
        cy = (int)(y + 0.5);
        drawSquare(theImage, cx, cy, w, r, g, b);
    }
}

// reads the file and stores the data in the global variables theCoords and theCosts
void readMap(string _mapName) {
    // string filename = "../Maps/" + _mapName + ".txt";
    // ifstream input(filename);
    ifstream input(_mapName);

    if (input.fail()) {
        cout << "file " << _mapName << " does not exist" << endl;
        exit(1);
    }

    int numNodes;
    input >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        vector<int> myRow;
        for (int j = 0; j < numNodes; j++) {
            int val;
            input >> val;
            myRow.push_back(val);
        }
        theCosts.push_back(myRow);
    }

    for (int i = 0; i < numNodes; i++) {
        Punto p;
        input >> p.x;
        input >> p.y;
        theCoords.push_back(p);
    }

    input.close();
}


// this function was modifed from code obtained at this website (obtained 8/12/2021):
//      https://newbedev.com/writing-bmp-image-in-pure-c-c-without-other-libraries
void writeBMPFile(double*** theImage) {
    int w = DIMX;
    int h = DIMY;
    int x, y;
    unsigned char r, g, b;

    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int

    img = (unsigned char *)malloc(3*w*h);
    memset(img,0,3*w*h);

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            x = i;
            y = (h - 1) - j;
            r = (unsigned char)(theImage[i][j][0]*255);
            g = (unsigned char)(theImage[i][j][1]*255);
            b = (unsigned char)(theImage[i][j][2]*255);
            if (r > 255)
                r = 255;
            if (g > 255)
                g = 255;
            if (b > 255)
                b = 255;
            img[(x+y*w)*3+2] = (unsigned char)(r);
            img[(x+y*w)*3+1] = (unsigned char)(g);
            img[(x+y*w)*3+0] = (unsigned char)(b);
        }
    }

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    bmpinfoheader[ 4] = (unsigned char)(       w    );
    bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
    bmpinfoheader[ 6] = (unsigned char)(       w>>16);
    bmpinfoheader[ 7] = (unsigned char)(       w>>24);
    bmpinfoheader[ 8] = (unsigned char)(       h    );
    bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
    bmpinfoheader[10] = (unsigned char)(       h>>16);
    bmpinfoheader[11] = (unsigned char)(       h>>24);

    f = fopen("Map.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i = 0; i < h; i++) {
        fwrite(img+(w*(h-i-1)*3),3,w,f);
        fwrite(bmppad,1,(4-(w*3)%4)%4,f);
    }

    free(img);
    fclose(f);
}

void writeCost(int num, double*** theImage, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        drawNumber(num, x1 - 20, (y1+y2)/2-9, 2.0, theImage);
    }
    else {
        drawNumber(num, (x1+x2)/2, (y1+y2)/2 + 6, 2.0, theImage);
    }
}

void drawNumber(int num, int x, int y, double scale, double*** theImage) {
    // determine sx
    int sx = x;
    double inc = 7.0 * scale;
    int digits[3] = {0,0,0};
    if (num > 99) {
        sx = x - (int)((inc * 3) / 2.0 + 0.5);
        digits[0] = num / 100;
        digits[1] = (num - (digits[0] * 100)) / 10;
        digits[2] = (num - (digits[0] * 100)) % 10;
        drawDigit(digits[0], sx, y, scale, theImage);
        drawDigit(digits[1], sx+inc, y, scale, theImage);
        drawDigit(digits[2], sx+2*inc, y, scale, theImage);
    }
    else if (num > 9) {
        sx = x - (int)((inc * 2) / 2.0 + 0.5);
        digits[1] = num / 10;
        digits[2] = num % 10;
        drawDigit(digits[1], sx, y, scale, theImage);
        drawDigit(digits[2], sx+inc, y, scale, theImage);
    }
    else {
        sx = x - (int)((inc * 1) / 2.0 + 0.5);
        digits[2] = num;
        drawDigit(digits[2], sx, y, scale, theImage);
    }
}

void drawDigit(int num, int x, int y, double scale, double*** theImage) {
    int digit[9][7];

    switch (num) {
        case 0: copyDigit(digit, zero); break;
        case 1: copyDigit(digit, one); break;
        case 2: copyDigit(digit, two); break;
        case 3: copyDigit(digit, three); break;
        case 4: copyDigit(digit, four); break;
        case 5: copyDigit(digit, five); break;
        case 6: copyDigit(digit, six); break;
        case 7: copyDigit(digit, seven); break;
        case 8: copyDigit(digit, eight); break;
        case 9: copyDigit(digit, nine); break;
    }

    int width = (int)(7 * scale + 0.5);
    int height = (int)(9 * scale + 0.5);
    int indx, indy;

    for (int cx = x; cx < x+width; cx++) {
        for (int cy = y; cy < y+height; cy++) {
            indx = (int)((cx - x) / scale);
            indy = (int)((cy - y) / scale);

            if (digit[indy][indx] == 1) {
                theImage[cx][cy][0] = 0;
                theImage[cx][cy][1] = 0;
                theImage[cx][cy][2] = 0.8;
            }
            else {
                theImage[cx][cy][0] = 1.0;
                theImage[cx][cy][1] = 1.0;
                theImage[cx][cy][2] = 1.0;
            }
        }
    }
}

void copyDigit(int digit[9][7], int num[9][7]) {
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 9; y++) {
            digit[y][x] = num[y][x];
        }
    }
}
