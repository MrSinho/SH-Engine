#ifndef SH_DESCRIPTOR_HANDLE_H
#define SH_DESCRIPTOR_HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <sys/types.h>
#include <sys/stat.h>

#ifdef _UNIX
#define stat _stat
#include <unistd.h>
#endif // _UNIX

#ifdef _WIN32
#define stat _stat
#endif // _WIN32

#include <stdio.h>
#include <stdint.h>

typedef struct stat ShFileStats;

typedef struct ShFd {
	const char* path;
	ShFileStats stats0;
	ShFileStats stats1;
} ShFd;


typedef struct ShScene ShScene;
typedef struct ShMaterialHost ShMaterialHost;
typedef struct ShPhysicsHost ShPhysicsHost;
typedef struct ShVkCore ShVkCore;

extern uint8_t shListenFd(ShFd* descriptor_handle);

extern void shGetFileStats(const char* path, ShFileStats* stats);

extern void shInitDescriptor(ShFd* descriptor_handle);

extern void shLoadMaterials(ShVkCore* p_core, const char* path, uint32_t* p_material_count, ShMaterialHost** pp_materials);

extern void shMaterialsRelease(ShVkCore* p_core, uint32_t* p_mat_info_count, ShMaterialHost** pp_materials);

extern void shLoadScene(const char* path, ShMaterialHost** pp_materials, ShScene* p_scene);

extern void shLoadPhysicsWorld(const char* path, ShPhysicsHost* p_host);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//SH_DESCRIPTOR_HANDLE_H