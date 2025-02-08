#include <subsystems/VisionSubsystem.h>

VisionSubsystem::VisionSubsystem() : exampleCamEstimator("exampleName",
                                                         frc::AprilTagFieldLayout::LoadField(frc::AprilTagField::kDefaultField),
                                                         photon::PoseStrategy::MULTI_TAG_PNP_ON_COPROCESSOR,
                                                         frc::Transform3d()){
    
    

}

/*void VisionSubsystem::GrabPoseTest(){ //wip not finished

    auto poseEstimate; //idk the type aiden you made it really confusing when i tried to clean up the errors

    exampleCamEstimator.Update(); 

    frc::Pose3d tempValue = frc::Pose3d(0_in, 0_in, 0_in, frc::Rotation3d(0_deg, 0_deg, 0_deg));

    if(poseEstimate.has_value()){
         tempValue = poseEstimate.value().estimatedPose;
    }

    
    frc::SmartDashboard::PutNumber("Estimated Pose X: ", tempValue.X().value());
    frc::SmartDashboard::PutNumber("Estimated Pose Y: ", tempValue.Y().value());
    frc::SmartDashboard::PutNumber("Estimated Pose Z: ", tempValue.Z().value());

}
*/