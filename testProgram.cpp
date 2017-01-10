#include <iostream>
#include "Quaternion.cpp"
using namespace std;

int main()
{   float x = 1.0;
    float y = 0.0;
    float z = 0.0;
    cout << "Initial Vector" << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    Quaternion <float> q(x, y, z);
    float angle = 3.14;
    float xa = 0.0;
    float ya = 1.0;
    float za = 0.0;
    q.updateNewVector(angle,xa,ya,za);
    float xp;
    float yp;
    float zp;
    cout << "After 180deg rotation about y axis" << endl;
    xp = q.getX();
    yp = q.getY();
    zp = q.getZ();
    cout << xp<< endl;
    cout << yp<< endl;
    cout << zp<< endl;
    return 0;
}
