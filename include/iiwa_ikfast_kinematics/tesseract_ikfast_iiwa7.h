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
  iiwa7Kinematics(const std::string base_link_name,
                  const std::string tip_link_name,
                  const std::vector<std::string> joint_names,
                  const std::string solver_name = "IKFastInvKin",
                  const std::vector<std::vector<double>> free_joint_combos = {{0.0}});
};

}  // namespace iiwa_ikfast_kinematics
#endif // TESSERACT_IKFAST_IIWA7_H
