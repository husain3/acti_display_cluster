#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QUdpSocket>

#pragma pack(1)

typedef struct acti_payload_t {
    uint32_t lapTime;
    uint32_t lastSectorTime;
    float performanceMeter;
    uint32_t status;
    uint32_t session;
    uint32_t sessionTimeLeft;
    uint32_t position;
    uint32_t flags;
    uint32_t penaltiesEnabled;
    float airDensity;
    float airTemp;
    float roadTemp;
    float surfaceGrip;
    float windSpeed;
    float windDirection;

    unsigned char _acVersion[28];
    unsigned char tyreCompound[64];

    float ballast;
    uint32_t gear;
    float driveTrainSpeed;
    float turboBoost;
    float fuel;
    uint32_t engineBrake;
    float Gas;
    float Brake;
    float tc;
    float abs;
    uint32_t ersRecoveryLevel;
    uint32_t ersPowerLevel;
    float RPM;
    float SpeedKMH;
    float Steer;
    uint32_t drsAvailable;
    uint32_t lapInvalidated;
    uint32_t numberOfTyresOut;

    float suspensionTravel0;
    float suspensionTravel1;
    float suspensionTravel2;
    float suspensionTravel3;

    float rideHeight0;
    float rideHeight1;

    float caster;

    float toeInDeg0;
    float toeInDeg1;
    float toeInDeg2;
    float toeInDeg3;

    float pitch;
    float roll;

    float localAngularVelocity0;
    float localAngularVelocity1;
    float localAngularVelocity2;

    float localVelocity0;
    float localVelocity1;
    float localVelocity2;

    float currentTyresCoreTemp0;
    float currentTyresCoreTemp1;
    float currentTyresCoreTemp2;
    float currentTyresCoreTemp3;

    float dynamicPressure0;
    float dynamicPressure1;
    float dynamicPressure2;
    float dynamicPressure3;

    float tyreWear0;
    float tyreWear1;
    float tyreWear2;
    float tyreWear3;

    float brakeTemp0;
    float brakeTemp1;
    float brakeTemp2;
    float brakeTemp3;

    float tyreTempI0;
    float tyreTempI1;
    float tyreTempI2;
    float tyreTempI3;

    float tyreTempM0;
    float tyreTempM1;
    float tyreTempM2;
    float tyreTempM3;

    float tyreTempO0;
    float tyreTempO1;
    float tyreTempO2;
    float tyreTempO3;

    float carDamage0;
    float carDamage1;
    float carDamage2;
    float carDamage3;
    float carDamage4;

    float maxTorque;
    float maxPower;
    float maxTurboBoost;
    float maxRpm;
    float maxFuel;

    float suspensionMaxTravel0;
    float suspensionMaxTravel1;
    float suspensionMaxTravel2;
    float suspensionMaxTravel3;

    float kersMaxJ;
    float ersMaxJ;

    float aero_CD;
    float aero_CL_Front;
    float aero_CL_Rear;

    uint32_t autoShifterOn;
    uint32_t idealLineOn;
    float aidFuelRate;
    float aidTireRate;
    float aidMechanicalDamage;
    uint32_t aidAllowTyreBlankets;
    float aidStability;
    uint32_t aidAutoClutch;
    uint32_t aidAutoBlip;
} acti_payload;

#pragma pack()

Q_DECLARE_METATYPE(acti_payload);

class Backend : public QObject
{
    Q_OBJECT

public:
    Backend();

    QString doElse();

signals:
    void someThing(QString smthing);

public slots:
    // that's our backend method
    QString doSome();
    void readyRead();

private:
    QUdpSocket *socket;

};

#endif // BACKEND_H
