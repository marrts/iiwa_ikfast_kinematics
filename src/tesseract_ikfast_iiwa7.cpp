/*
 * Software License Agreement (Apache License)
 *
 * Copyright (c) 2016, Southwest Research Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iiwa_ikfast_kinematics/impl/iiwa7_link3free.hpp>  // generated from ikfast for this robot
#include <iiwa_ikfast_kinematics/tesseract_ikfast_iiwa7.h>
#include <tesseract_kinematics/ikfast/impl/ikfast_inv_kin.hpp>

namespace iiwa_ikfast_kinematics
{
iiwa7Kinematics::iiwa7Kinematics(const std::string base_link_name,
                                 const std::string tip_link_name,
                                 const std::vector<std::string> joint_names,
                                 const std::string solver_name,
      const std::vector<std::vector<double>> free_joint_combos)
  : IKFastInvKin(base_link_name,
                 tip_link_name,
                 joint_names,
                 solver_name,
                 free_joint_combos)
{
}

}  // namespace iiwa_ikfast_kinematics

