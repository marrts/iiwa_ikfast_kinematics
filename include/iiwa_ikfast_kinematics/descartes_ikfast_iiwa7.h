#ifndef DESCARTES_IKFAST_IIWA7_H
#define DESCARTES_IKFAST_IIWA7_H

#include <descartes_ikfast/ikfast_kinematics.h>
#include <descartes_ikfast/impl/ikfast_kinematics.hpp>

namespace iiwa_ikfast_kinematics
{
template <typename FloatType>
class iiwa7Kinematics : public descartes_light::IKFastKinematics<FloatType>
{
public:
  iiwa7Kinematics(const Eigen::Transform<FloatType, 3, Eigen::Isometry>& world_to_robot_base,
                  const Eigen::Transform<FloatType, 3, Eigen::Isometry>& tool0_to_tip,
                  const descartes_light::IsValidFn<FloatType>& is_valid_fn,
                  const descartes_light::GetRedundantSolutionsFn<FloatType>& redundant_sol_fn)
    : descartes_light::IKFastKinematics<FloatType>(world_to_robot_base, tool0_to_tip, is_valid_fn, redundant_sol_fn)
  {
  }
};

using iiwa7KinematicsD = iiwa7Kinematics<double>;
using iiwa7KinematicsF = iiwa7Kinematics<float>;

}  // namespace iiwa_ikfast_kinematics
#endif // DESCARTES_IKFAST_IIWA7_H
