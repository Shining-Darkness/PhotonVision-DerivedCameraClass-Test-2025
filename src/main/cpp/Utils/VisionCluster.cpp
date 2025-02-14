#include <Utils/VisionCluster.h>

using namespace VisionConstants;

VisionCluster::VisionCluster(){
    std::filesystem::path cameraPath = frc::filesystem::GetDeployDirectory().append("\\PhotonCameras\\");
    m_photonCameras = JsonCamera::LoadCamerasFromFolder(cameraPath, frc::AprilTagFieldLayout::LoadField(frc::AprilTagField::kDefaultField));
}

std::vector<VisionPoseResult> VisionCluster::GetVisionEstimates(){

    //Make sure the m_visionEst is empty before we start
    m_visionEst.clear();

    //First loop is not range based due to a copy error (Needs to be fixed in the future. I think I need a copy constructor.)
    for (int i = 0; i < m_photonCameras.size(); i++){
        //Loop through each estimated position returned from the Update() method
        for (auto position : m_photonCameras[i].Update()){

                auto filteredEstimate = FilterVisionEstimate(position);

                if(filteredEstimate.has_value()){
                    filteredEstimate.value().estimatedPose;
                }
            }
        }
    return m_visionEst;  
}

//Takes an estimated robot pose and filters it returning a vision pose result containing the position, and the position std devs
std::optional<VisionPoseResult> VisionCluster::FilterVisionEstimate(std::optional<photon::EstimatedRobotPose> estimatedPosition){
    //Check if the std::optional has a value
    if(estimatedPosition.has_value()){

        photon::EstimatedRobotPose poseVal = estimatedPosition.value();

        wpi::array<double, 3> stdDevs = {std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), std::numeric_limits<double>::max()};

        //Create a variable to hold the average distance and ambiguity
        units::inch_t avgDistance;
        double avgAmbiguity;
                        
        unsigned int numTargets = poseVal.targetsUsed.size();

        for(auto target : poseVal.targetsUsed){
            avgDistance += target.GetBestCameraToTarget().Translation().ToTranslation2d().Norm();
            avgAmbiguity += target.GetPoseAmbiguity();
        }

        avgDistance /= numTargets;
        avgAmbiguity /= numTargets;

        if(numTargets > 1 && avgAmbiguity <= kMaxMultiTagAmbiguity && avgDistance <= kMaxMultiTagDistance){
            stdDevs = kMultiTagStdDevs; 
        }
        else if(numTargets == 1 && avgAmbiguity <= kMaxSingleTagAmbiguity && avgDistance <= kMaxSingleTagDistance){
            stdDevs = kSingleTagStdDevs;
        }
        else {
            // Discard pose estimation otherwise
            return std::nullopt;
        }

        // Scale standard deviations by average tag distance squared
        double scaleFactor = 1.0 + (avgDistance.value() * avgDistance.value() * kStdDevsScaleFactor);
        for(double& stdDev : stdDevs){
            stdDev *= scaleFactor;
        }
            return VisionPoseResult {poseVal, stdDevs};
    }

    return std::nullopt;
}

