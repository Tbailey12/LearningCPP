#ifndef FORWARDDEC_H
#define FORWARDDEC_H
double initHeight;
double startHeight();
double calcHeight(double height, double time);
void drop(double height);
int userSelect();
bool selection(int selection, double height);
void wait();
double calcTime(double height);
double calcVelocity(double height, double time);
#endif
