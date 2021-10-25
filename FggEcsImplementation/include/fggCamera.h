#ifndef FGG_CAMERA_H
#define FGG_CAMERA_H

//#include "fggCglmImplementation.h"
#include "fggEcsImplementation.h"

typedef enum FggCameraSetupFlags {
	FGG_CAMERA_SETUP_FREE_FLIGHT_BIT	= 0x01,
	FGG_CAMERA_SETUP_STATIC_BIT			= 0x02,
} FggCameraSetupFlags;

typedef struct FggCamera {

	float	fov;
	float	nc;
	float	fc;
	float	projection[4][4];
	float	view[4][4];

	FggCameraSetupFlags flags;

} FggCamera;

FGG_ECS_MAKE_COMPONENT_DEFINITIONS(FggCamera, 3);


#endif