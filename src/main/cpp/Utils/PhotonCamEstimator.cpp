#include "Utils/PhotonCamEstimator.h"

PhotonCamEstimator::PhotonCamEstimator(std::string name, frc::AprilTagFieldLayout aprilTags, photon::PoseStrategy poseStrategy, frc::Transform3d robotToCam) : photon::PhotonCamera(name), photon::PhotonPoseEstimator(aprilTags, poseStrategy, robotToCam){
    
}

std::vector <std::optional<photon::EstimatedRobotPose>> PhotonCamEstimator::Update(){
    m_results = photon::PhotonCamera::GetAllUnreadResults();

    for (auto result : m_results){
        m_robotPositions.push_back(photon::PhotonPoseEstimator::Update(result));
    }

    return m_robotPositions;

}