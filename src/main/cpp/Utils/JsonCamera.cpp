#include <Utils/JsonCamera.h>

using namespace JsonCamera;

//Takes a filepath to a json file (including file extension) & returns a PhotonCamEstimator object for the camera described in the file.
 PhotonCamEstimator LoadCameraFromFile(std::filesystem::path filepath){
    std::fstream camStream(filepath);

    wpi::json jsonFile;

    camStream >> jsonFile;

}