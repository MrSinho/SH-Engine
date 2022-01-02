#ifndef SH_PHYSICS_INFO_H
#define SH_PHYSICS_INFO_H

#include "shEcsImplementation.h"

typedef enum ShPhysicsClient {
    SH_PHYSICS_CLIENT_DYNAMICS        = 0b001,
    SH_PHYSICS_CLIENT_THERMODYNAMICS  = 0b010,
    SH_PHYSICS_CLIENT_ELECTROSTATICS  = 0b100
} ShPhysicsClient;

SH_ECS_MAKE_COMPONENT_DEFINITIONS(ShPhysicsClient, 8)

typedef struct ShElectricalCharge {
    float position[3];
    float intensity[1];
} ShElectricalCharge;

SH_ECS_MAKE_COMPONENT_DEFINITIONS(ShElectricalCharge, 9)

typedef struct ShElectrostaticWorld {
    ShElectricalCharge charges[32];
} ShElectrostaticWorld;

typedef struct ShPhysicsHost {
    ShElectrostaticWorld electrostaticWorld;
} ShPhysicsHost;

static void ShPhysicsHostRelease(ShPhysicsHost* p_host) {
    ShElectricalCharge charge = { 0 };
    for (uint32_t i = 0; i < 32; i++) {
        p_host->electrostaticWorld.charges[i] = charge;
    }
}

#endif//SH_PHYSICS_INFO_H
