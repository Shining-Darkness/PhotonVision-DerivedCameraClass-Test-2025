// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/geometry/Transform3d.h>
#include <frc/geometry/Rotation3d.h>

#include <photon/PhotonCamera.h>

#include <vector>
#include <string>

#include <units/length.h>
#include <units/angle.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants

namespace PhotonVisionConstants {
    
inline std::vector<std::pair<std::string, frc::Transform3d>> kCameraInfo = {{"FrontLeftCamera",  frc::Transform3d(0_in, 0_in, 0_in, frc::Rotation3d(0_deg, 0_deg, 0_deg))},
                                                                           {"FrontRightCamera",  frc::Transform3d(0_in, 0_in, 0_in, frc::Rotation3d(0_deg, 0_deg, 0_deg))}};

 
}