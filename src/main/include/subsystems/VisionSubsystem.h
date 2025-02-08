#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <Utils/PhotonCamEstimator.h>

class VisionSubsystem : frc2::SubsystemBase {
    public:
        VisionSubsystem();

        //void GrabPoseTest();

    private:
        PhotonCamEstimator exampleCamEstimator;
};