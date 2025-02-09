#pragma once

#include <vector>

#include <photon/PhotonCamera.h>

#include <frc/Filesystem.h>
#include <filesystem>

#include <iostream>
#include <fstream>

#include <wpi/json.h>

#include "Utils/PhotonCamEstimator.h"

namespace JsonCamera{
        PhotonCamEstimator LoadCameraFromFile();
        std::vector<PhotonCamEstimator> LoadCameraFromFolder();
};