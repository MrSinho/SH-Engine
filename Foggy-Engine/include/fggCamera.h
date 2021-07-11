#ifndef FGG_DEFAULT_CAMERA_H
#define FGG_DEFAULT_CAMERA_H

#include <cglm/cglm.h>

#include "fggEcsImplementation.h"

typedef struct FggCamera {

	mat4 view;

} FggCamera;

EZ_ECS_MAKE_COMPONENT_DEFINITIONS(FggCamera, 2)

#endif