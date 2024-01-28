// Settings.h
#include "EQOA_TileMesh.h"
#include <iostream>

class Settings
{
public:
    std::string Path = "D:\\ESF - file - format\\Tunaria_FixOrigin\\";
    std::string meshFile;
    int minFile = 87;
    int maxFile = 87;

    float cellSize = 0.1f;
    float cellHeight = 0.1f;
    float agentHeight = 2.0f;
    float agentRadius = 0.6f;
    float agentMaxClimb = 0.9f;
    float agentMaxSlope = 60.0f;
    float regionMinSize = 0.25f;
    float regionMergeSize = 20.0f;
    float edgeMaxLen = 6.0f;
    float edgeMaxError = 1.0f;
    float vertsPerPoly = 6.0f;
    float detailSampleDist = 3.0f;
    float detailSampleMaxError = 0.5f;
    float tileSize = 40.0f;
    int partitionType = SAMPLE_PARTITION_WATERSHED;

    static Settings& getInstance() {
        static Settings instance;
        return instance;
    }
};
