#pragma once

#include <Utils/JsonCamera.h>
#include <frc/Filesystem.h>
#include <filesystem>

#include <string>
#include <vector>

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <Utils/PhotonCamEstimator.h>

class VisionSubsystem : frc2::SubsystemBase {
    public:
        VisionSubsystem();
    
        std::vector<photon::EstimatedRobotPose> GetVisionEstimate();

        //Eigen::Matrix<double, 3, 1> GetEstimationStdDevs(photon::EstimatedRobotPose pose); //Implement StdDev later

    private:
        std::vector<PhotonCamEstimator> m_photonCameras;
        std::vector<photon::EstimatedRobotPose> m_visionEst;
};