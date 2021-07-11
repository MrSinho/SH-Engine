#ifndef FGG_ECS_IMPLEMENTATION_H
#define FGG_ECS_IMPLEMENTATION_H

#define EZ_ECS_MAX_ENTITIES		4
#define EZ_ECS_MAX_COMPONENTS	5



#include <EZ_ECS.h>

#include "fggVkCore.h"



typedef struct FggVkFixedStates FggVkFixedStates;

typedef struct FggProjection FggProjection;



extern void fggSceneInit(const FggVkCore core, const FggVkFixedStates fixedStates, ezecsScene scene);

extern void fggSceneUpdate(const FggVkCore core, const FggProjection projection, const ezecsScene scene);


#endif