#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <shsharedhost/shSharedHost.h>
#include <shfd/shFile.h>

#include <string.h>

#include <json.h>

#ifdef _MSC_VER
#pragma warning (disable: 4996)
#endif//_MSC_VER

void shLoadSimulation(const char* path, ShEngine* p_engine, ShSimulationHandle* p_simulation) {
    assert(path != NULL && p_engine != NULL && p_simulation != NULL);

    char* buffer = (char*)shReadText(path, NULL);
    assert(buffer != NULL);

    json_object* parser = json_tokener_parse(buffer);
    assert(parser != NULL);

    json_object* json_run = json_object_object_get(parser, "run");
    json_object* json_name = json_object_object_get(parser, "name");
    json_object* json_start = json_object_object_get(parser, "start");
    json_object* json_update = json_object_object_get(parser, "update");

    assert(json_run != NULL && json_name != NULL && json_start != NULL && json_update != NULL);

    const char* shared_name = json_object_get_string(json_name);
    p_simulation->run = (uint8_t)json_object_get_int(json_run);
    p_simulation->s_start = (char*)json_object_get_string(json_start);
    p_simulation->s_update = (char*)json_object_get_string(json_update);

    free(buffer);

    char shared_path[256];
    strcpy(shared_path, shared_name);
#ifdef _WIN32
    strcat(shared_path, ".dll");
#else
    strcat(shared_path, ".so");
#endif//_WIN32

    p_simulation->shared = shLoadShared(shared_path);
    if (p_simulation->run) {
        assert(p_simulation->shared != NULL);
    }
}

#ifdef __cplusplus
}
#endif//__cplusplus