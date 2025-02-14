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

namespace VisionConstants {

    //Max pose ambiguity (for single tag)
    constexpr double kMaxSingleTagAmbiguity = 0.2;
    constexpr double kMaxMultiTagAmbiguity = 0.3;

    //Max distance (for single tag)
    constexpr units::inch_t kMaxSingleTagDistance = 150_in;
    constexpr units::inch_t kMaxMultiTagDistance = 200_in;
  
    //Default standard deviations 
    constexpr wpi::array<double, 3U> kSingleTagStdDevs {3.75, 3.75, 7.5};
    constexpr wpi::array<double, 3U> kMultiTagStdDevs {0.75, 0.75, 1.5};

    //Standard deviations scale factor (scaled as: distance^2 * stdDevsScaleFactor)
    constexpr double kStdDevsScaleFactor = 1.0 / 30.0;

    
}