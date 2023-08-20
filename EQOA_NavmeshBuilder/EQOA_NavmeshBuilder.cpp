// EQOA_NavmeshBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "InputGeom.h"
#include "EQOA_TileMesh.h"

rcContext contex;
BuildContext ctx;
InputGeom inputGeom;

int main()
{
    std::string filePath = "D:\\ESF-file-format\\Tunaria_FixOrigin\\Qeynos.obj";
    std::string meshPath = "D:\\ESF-file-format\\Tunaria_FixOrigin\\Qeynos.bin";
    const char* meshPathCString = meshPath.c_str();
    bool loaded = inputGeom.load(&contex, filePath);

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
    return 0;
}

 
