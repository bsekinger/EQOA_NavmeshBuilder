#include <iostream>
#include "InputGeom.h"
#include "EQOA_TileMesh.h"
#include "EQOA_NavmeshBuilder.h"
#include "Settings.h"

rcContext contex;
BuildContext ctx;
InputGeom inputGeom;

int main()
{
    Settings& settingsInstance = Settings::getInstance();
    std::string basePath = settingsInstance.Path;

    for (int i = settingsInstance.minFile; i <= settingsInstance.maxFile; ++i)
    {
        std::string objFile = basePath + std::to_string(i) + ".obj";
        settingsInstance.meshFile = basePath + std::to_string(i) + ".bin";
    
        const char* meshPathCString = settingsInstance.meshFile.c_str();
        bool loaded = inputGeom.load(&contex, objFile);

        if (!loaded)
            return 1;

        EQOA_TileMesh sample;
        sample.setContext(&ctx);
        sample.m_geom = &inputGeom;
        sample.handleSettings();

        dtNavMesh* mesh = sample.handleBuild();
        if (mesh == nullptr)
            return 1;

        sample.saveAll(meshPathCString, mesh);
        delete mesh;
    }
    return 0;
}

 
