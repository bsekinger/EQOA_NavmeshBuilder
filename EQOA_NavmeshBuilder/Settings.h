// Settings.h
#include "EQOA_TileMesh.h"
#include <iostream>

class Settings
{
public:
    std::string Path = "D:\\ESF-file-format\\Tunaria_FixOrigin\\";
    std::string meshFile;
    int minFile = 84;
    int maxFile = 84;

    // settings changes to fix small ramp up towers to connect to the main mesh (Freeport guard towers)
    float cellSize = 0.25f;
    float cellHeight = 0.1f;
    float agentHeight = 2.0f;
    float agentRadius = 0.2f;
    float agentMaxClimb = 1.0f;
    float agentMaxSlope = 60.0f;
    float regionMinSize = 8.0f;  // 8.0f
    float regionMergeSize = 20.0f; // 20.0f;
    float edgeMaxLen = 12.0f; // 12.0f;
    float edgeMaxError = 1.3f; // 1.3f;
    float vertsPerPoly = 6.0f;
    float detailSampleDist = 6.0f; // 6.0f;
    float detailSampleMaxError = 1.0f;
    float tileSize = 200.0f;
    int partitionType = SAMPLE_PARTITION_LAYERS;

    static Settings& getInstance() {
        static Settings instance;
        return instance;
    }
};
