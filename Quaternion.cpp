///Takes input of a vector and a rotation in radians in a particular axis.

///Outputs resultant vector
#include "Quaternion.h"

template<class T>
Quaternion<T>::Quaternion(T x, T y, T z){
	//Set the initial Point
	setInitialQuat(x,y,z);
	return;
};

template<class T>
void Quaternion<T>::setInitialQuat(T x, T y, T z){
	this->xpp.w = 0.0;
	this->xpp.x = x;
	this->xpp.y = y;
	this->xpp.z = z;



};

template<class T>
void Quaternion <T>::updateNewVector(T angle, T ax, T ay, T az){
	setRotation(angle);
	setAxis(ax, ay, az);
	rotToQuat();
	calcResultant();
	calcConj();
    calcNewPoint();
	return;
};

template<class T>
void Quaternion <T>::setRotation(T angle){
	this->angle=angle;
	return;
};

template<class T>
void Quaternion <T>::setAxis(T ax, T ay, T az){
	this->axis.x = ax;
	this->axis.y = ay;
	this->axis.z = az;
	return;
};

template<class T>
void Quaternion <T>::rotToQuat(){
	this->qr.w = cos((angle/2.0));

	this->qr.x = sin((angle/2.0));
	this->qr.x *= this->axis.x;

	this->qr.y = sin((angle/2.0));
	this->qr.y *= this->axis.y;

	this->qr.z = sin((angle/2.0));
	this->qr.z *= this->axis.z;
	return;
};
template<class T>
void Quaternion <T>::calcResultant(){
	//Step1)Populate Matrix Here
	//Use inital point on left and qr as up
    T aleft = 0.0;
	T bleft = this->xpp.x;
	T cleft = this->xpp.y;
	T dleft = this->xpp.z;

	T aup = this->qr.w;
	T bup = this->qr.x;
	T cup = this->qr.y;
	T dup = this->qr.z;

	popMatrix(aleft,bleft,cleft,dleft,aup,bup,cup,dup);
	//calcQuat Here to get resultant;
	//set the dummy output to qres
	calcQuat();
	//set the dummy output to qres
	this->qres.w = this->holder.w;
	this->qres.x = this->holder.x;
	this->qres.y = this->holder.y;
	this->qres.z = this->holder.z;
	return;
};
template<class T>
void Quaternion <T>::popMatrix(T aleft, T bleft, T cleft, T dleft, T aup, T bup, T cup, T dup){
	T up[4] = {aup,bup,cup,dup};
	T side[4] = {aleft,bleft,cleft,dleft};
	for(int i=0; i<4; i=i+1){
		for(int j=0; j<4; j=j+1){
			this->qMatrix[i][j] = side[i]*up[j];
		};
	};
	return;
};

template<class T>
void Quaternion <T>::calcQuat(){
	this->holder.w = this->qMatrix[0][0] - this->qMatrix[1][1] - this->qMatrix[2][2] - this->qMatrix[3][3];
	this->holder.x = this->qMatrix[1][0] + this->qMatrix[0][1] - this->qMatrix[3][2] + this->qMatrix[2][3];
	this->holder.y = this->qMatrix[0][2] - this->qMatrix[1][3] + this->qMatrix[2][0] + this->qMatrix[3][1];
	this->holder.z = this->qMatrix[0][3] + this->qMatrix[1][2] - this->qMatrix[2][1] + this->qMatrix[3][0];
	return;
};

template<class T>
void Quaternion <T>::calcConj(){
	this->_qr.w = this->qr.w;
	this->_qr.x = this->qr.x * -1;
	this->_qr.y = this->qr.y * -1;
	this->_qr.z = this->qr.z * -1;
	return;
};

template<class T>
void Quaternion <T>::calcNewPoint(){
    T aleft = this->_qr.w;
	T bleft = this->_qr.x;
	T cleft = this->_qr.y;
	T dleft = this->_qr.z;

	T aup = this->qres.w;
	T bup = this->qres.x;
	T cup = this->qres.y;
	T dup = this->qres.z;

	popMatrix(aleft, bleft, cleft, dleft, aup, bup, cup, dup);
	//calcQuat Here to get resultant;
	//set the dummy output to qres
	calcQuat();
	//set the dummy output to qres
	this->xp.w = this->holder.w;
	this->xp.x = this->holder.x;
	this->xp.y = this->holder.y;
	this->xp.z = this->holder.z;
	return;
};
template<class T>
T Quaternion <T>::getX(){
	return this->xp.x;
};
template<class T>
T Quaternion <T>::getY(){
	return this->xp.y;
};
template<class T>
T Quaternion <T>::getZ(){
	return this->xp.z;
};
