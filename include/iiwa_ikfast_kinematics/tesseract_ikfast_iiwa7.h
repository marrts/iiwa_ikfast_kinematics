#ifndef TESSERACT_IKFAST_IIWA7_H
#define TESSERACT_IKFAST_IIWA7_H

#include <Eigen/Geometry>
#include <vector>
#include <tesseract_kinematics/ikfast/ikfast_inv_kin.h>
#include <tesseract_kinematics/core/forward_kinematics.h>

namespace iiwa_ikfast_kinematics
{

class iiwa7Kinematics : public tesseract_kinematics::IKFastInvKin
{
public:
  iiwa7Kinematics(const tesseract_kinematics::ForwardKinematics::ConstPtr& fwd_kin,
                  const std::vector<std::vector<double>> free_joint_combos = {{0.0}});
};

}  // namespace iiwa_ikfast_kinematics
#endif // TESSERACT_IKFAST_IIWA7_H
