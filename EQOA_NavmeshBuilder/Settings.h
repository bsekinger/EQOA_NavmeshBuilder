// Settings.h
#include "EQOA_TileMesh.h"
#include <iostream>

class Settings
{
public:
    std::string Path = "D:\\ESF-file-format\\Tunaria_FixOrigin\\";
    std::string meshFile;
    int minFile = 166;
    int maxFile = 174;
    float cellSize = 0.25f;
    float cellHeight = 0.25f;
    float agentHeight = 2.0f;
    float agentRadius = 0.6f;
    float agentMaxClimb = 0.9f;
    float agentMaxSlope = 60.0f;
    float regionMinSize = 0.25f;
    float regionMergeSize = 20.0f;
    float edgeMaxLen = 12.0f;
    float edgeMaxError = 1.3f;
    float vertsPerPoly = 6.0f;
    float detailSampleDist = 6.0f;
    float detailSampleMaxError = 1.0f;
    float tileSize = 400.0f;
    int partitionType = SAMPLE_PARTITION_WATERSHED;

    static Settings& getInstance() {
        static Settings instance;
        return instance;
    }
};
