#include <subsystems/VisionSubsystem.h>

VisionSubsystem::VisionSubsystem(){
    std::filesystem::path cameraPath = frc::filesystem::GetDeployDirectory().append("\\PhotonCameras\\");
    m_photonCameras = JsonCamera::LoadCamerasFromFolder(cameraPath, frc::AprilTagFieldLayout::LoadField(frc::AprilTagField::kDefaultField));
}

std::vector<photon::EstimatedRobotPose> VisionSubsystem::GetVisionEstimate(){

    //Make sure the m_visionEst is empty before we start
    m_visionEst.clear();

    //First loop is not range based due to a copy error (Needs to be fixed in the future. I think I need a copy constructor.)
    for (int i = 0; i < m_photonCameras.size(); i++){
        //Loop through each estimated position returned from the Update() method
        for (auto position : m_photonCameras[i].Update()){
            //Check if the std::optional has a value
            if(position.has_value()){
                //Create a temporary variable for the postion.value() so we dont repeatedly call it
                auto poseVal = position.value();
                //Check if the estimate was made using 2 or more targets
                if(poseVal.targetsUsed.size() >= 2){
                    //Add the position to the m_visionEst vect
                    m_visionEst.push_back(poseVal);
                }
                else if(poseVal.targetsUsed[0].GetPoseAmbiguity() <= .2){ //If the number of tags used isnt >= 2 then we know the number of tags used is 1. Therefore, we can simply check if the one target at index [0] used had an ambiguity of less than 2.
                    //Add the position to the m_visionEst vect
                    m_visionEst.push_back(poseVal);
                }
            }
        }
    }  
    return m_visionEst;  
}

/* Implement StdDev Later
Eigen::Matrix<double, 3, 1> VisionSubsystem::GetEstimationStdDevs(photon::EstimatedRobotPose pose){
    if()
}*/
