//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef EQOATILEMESH_H
#define EQOATILEMESH_H

#include "Sample.h"
#include "DetourNavMesh.h"
#include "Recast.h"
#include "ChunkyTriMesh.h"
#include "DetourNavMeshQuery.h" 

class EQOA_TileMesh : public Sample
{
protected:
	bool m_keepInterResults = false;
	bool m_buildAll = true;
	float m_totalBuildTimeMs;

	unsigned char* m_triareas;
	rcHeightfield* m_solid;
	rcCompactHeightfield* m_chf;
	rcContourSet* m_cset;
	rcPolyMesh* m_pmesh;
	rcPolyMeshDetail* m_dmesh;
	rcConfig m_cfg;	
	
	int m_maxTiles;
	int m_maxPolysPerTile;
	float m_tileSize = 200;
	
	unsigned int m_tileCol;
	float m_lastBuiltTileBmin[3];
	float m_lastBuiltTileBmax[3];
	float m_tileBuildTime;
	float m_tileMemUsage;
	int m_tileTriCount;

 	unsigned char* buildTileMesh(const int tx, const int ty, const float* bmin, const float* bmax, int& dataSize);
	
//	void saveAll(const char* path, const dtNavMesh* mesh);
	
public:
	EQOA_TileMesh();

    class InputGeom* m_geom;
    class dtNavMesh* m_navMesh;
    class dtNavMeshQuery* m_navQuery;
    class dtCrowd* m_crowd;
	
	virtual void handleSettings();
	virtual dtNavMesh* handleBuild();
	virtual void collectSettings(struct BuildSettings& settings);
	
	void getTilePos(const float* pos, int& tx, int& ty);
	void buildAllTiles();

    enum SamplePartitionType
    {
        SAMPLE_PARTITION_WATERSHED,
        SAMPLE_PARTITION_MONOTONE,
        SAMPLE_PARTITION_LAYERS
    };

private:
	// Explicitly disabled copy constructor and copy assignment operator.
	EQOA_TileMesh(const EQOA_TileMesh&);
	EQOA_TileMesh& operator=(const EQOA_TileMesh&);

};

#endif // EQOATILEMESH_H
