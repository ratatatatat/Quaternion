#include <math.h>


#ifndef _Quaternion_h_
#define _Quaternion_h_

template<class T>
class Quaternion{

	public:
            Quaternion(T x, T y, T z); //Initialize the quaternion with a vector/point, no output update local vector vairables and normalize
			void updateNewVector(T angle, T x, T y, T z);//Takes input and updates local states for X,Y,Z
			T getX();// Returns X component in type T
			T getY();//Returns Y component of vector in type T
			T getZ();//Returns Z component of vector in type T

	private:

			// Struct for Vector
			// {
			// 	T x;
			// 	T y;
			// 	T z;
			// };
			// vector initialpoint;
			// vector finalpoint;
			// vector axis;
			T angle; //Store Last Angle Translation


			//Struct for the quaternions: 1) qr, xpp, qr*, qres, xp
			struct quat{
				T w;
				T x;
				T y;
				T z;
			};
			quat axis; //Null a value always
			quat qr;//rotation quat
			quat xpp;//initial point quat
			quat _qr;//conjugate of rotation quat
			quat qres;//resultant quat
			quat xp; //new point quat
			quat holder;//dummy quat used to store output of calcquat()
			T qMatrix[4][4];

			void popMatrix(T aleft, T bleft, T cleft, T dleft, T aup, T bup, T cup, T dup);// populates the matrix, left is the side vector and up is the top vector

			void calcQuat();//Calculates the quat based on the current Matrix state and stores output in dummy quat.

			void setInitialQuat( T x, T y, T z); //Called in constructor to update vector components
			void setRotation(T angle); //Set the local angle of rotation, and the Axis
			void setAxis(T ax,T ay,T az); //Set the axis.
			void rotToQuat();//Convert Rotation to Quaternion, store output in qr
			void calcResultant();
			void calcConj();//Calculate the conjugate of qr and store in _qr
			void calcNewPoint();//Function to perform calcultion


};
#endif
