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

    private:
        std::vector<PhotonCamEstimator> m_photonCameras;
};