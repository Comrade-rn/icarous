//
// Created by research133 on 3/27/18.
//

#ifndef BSPLINES_H
#define BSPLINES_H

#include "kdtree.h"
#include "Poly3D.h"
#include <list>
#include "CDPolycarp.h"

//#define OBS_THRESH 3.0

class Bsplines {
private:
    double *tVec;
    double *KntVec;
    int order;
    int lenT;
    int lenK;
    int ndim;
    double obsloc[3];
    double dx;
    double dy;
    double OBS_THRESH;
    double obsWeight;
    larcfm::CDPolycarp polycarp;
    std::list<larcfm::Poly3D> obslist;

public:
    double *ctrlPt0;
    std::list<KDTREE*> kdtreeList;
    std::list<KDTREE*>::iterator it;
    Bsplines(){};
    //Bsplines(int ndim,int lent,double* tVec,int lenk,double* KntVec,int order);
    void SetSplineProperties(int ndim,int lent,double* tVec,int lenk,double* KntVec,int order);
    void SetObstacleProperties(double dx,double dy,double threshold,double obsWeight);
    void SetInitControlPts(double* ctrlPt);
    void SetObstacles(larcfm::Poly3D& obs);
    void GetPoint(double t,double *x,double *output);
    double Beta(double x);
    double HingeLoss(double x);
    double HingeLossGrad(double x);
    double Nfac(double t,int i,int k);
    double dist2D(double x1,double y1,double x2,double y2);
    double Objective2D(const double *x);
    void Gradient2D(const double* x0,double *grad);

};


#endif //BSPLINES_BSPLINES_H
