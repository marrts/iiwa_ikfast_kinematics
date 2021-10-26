#ifndef TESSERACT_IKFAST_IIWA7_FACTORIES_H
#define TESSERACT_IKFAST_IIWA7_FACTORIES_H

#include <tesseract_kinematics/core/kinematics_plugin_factory.h>

namespace iiwa_ikfast_kinematics
{
class iiwa7InvKinFactory : public tesseract_kinematics::InvKinFactory
{
  tesseract_kinematics::InverseKinematics::UPtr create(const std::string& solver_name,
                                                       const tesseract_scene_graph::SceneGraph& scene_graph,
                                                       const tesseract_scene_graph::SceneState& scene_state,
                                                       const tesseract_kinematics::KinematicsPluginFactory& plugin_factory,
                                                       const YAML::Node& config) const override final;
};
} // namespace iiwa_ikfast_kinematics


#endif // TESSERACT_IKFAST_IIWA7_FACTORIES_H
