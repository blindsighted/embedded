#pragma once
#include "PID.h"
#include "PiecewiseFit.h"
#include "Printable.h"

enum class ControlMode {
    none,
    force,
    position,
    hybrid,
    pressure,
    dutycycle
};

class ControlModule {
    ControlMode mode;
    printable* print;
    float alpha;
    PiecewiseFit* forceff;
    PiecewiseFit* positionff;
    PiecewiseFit* pressureff;

    PID* forcepid;
    PID* positionpid;
    PID* pressurepid;

    float desiredf;
    float desiredp;
    float desiredpre;
    float desireddc;
public:
    ControlModule(printable* print);
    ~ControlModule();
    float compute(float actualf, float actualp, float actualpre, float time);
    void setMaximumForce(float force);
    void setDesiredPosition(float position);
    void setDesiredPressure(float pressure);
    void setDesiredDC(float dutycycle);
    void setControlMode(ControlMode mode);
private:
    float computeForceTerm(float actualf, float actualp, float time);
    float computePositionTerm(float actualp, float time);
    float computeDutycycle(float desiredpre, float actualpre, float time);
};