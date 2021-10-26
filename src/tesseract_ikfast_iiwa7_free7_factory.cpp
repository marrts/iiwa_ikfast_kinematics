
#include <iiwa_ikfast_kinematics/tesseract_ikfast_iiwa7_free7_factory.h>
#include <iiwa_ikfast_kinematics/tesseract_ikfast_iiwa7.h>

namespace iiwa_ikfast_kinematics
{
tesseract_kinematics::InverseKinematics::UPtr iiwa7Free7InvKinFactory::create(const std::string& solver_name,
                                                                              const tesseract_scene_graph::SceneGraph& scene_graph,
                                                                              const tesseract_scene_graph::SceneState& scene_state,
                                                                              const tesseract_kinematics::KinematicsPluginFactory& plugin_factory,
                                                                              const YAML::Node& config) const
{
  std::string base_link;
  std::string tip_link;
  std::vector<std::vector<double>> free_joint_combos;
  tesseract_scene_graph::ShortestPath path;

  try
  {
    if (YAML::Node n = config["base_link"])
      base_link = n.as<std::string>();
    else
      throw std::runtime_error("iiwa7InvKinFactory, missing 'base_link' entry");

    if (YAML::Node n = config["tip_link"])
      tip_link = n.as<std::string>();
    else
      throw std::runtime_error("iiwa7InvKinFactory, missing 'tip_link' entry");

    if (YAML::Node free_joint_lists = config["params"])
    {
      double min_joint_val;
      double max_joint_val;
      int num_steps;
      if (YAML::Node n = free_joint_lists["min_joint_value"])
        min_joint_val = n.as<double>();
      else
        throw std::runtime_error("iiwa7InvKinFactory, missing 'min_joint_value' entry");

      if (YAML::Node n = free_joint_lists["max_joint_value"])
        max_joint_val = n.as<double>();
      else
        throw std::runtime_error("iiwa7InvKinFactory, missing 'max_joint_value' entry");

      if (YAML::Node n = free_joint_lists["num_steps"])
        num_steps = n.as<int>();
      else
        throw std::runtime_error("iiwa7InvKinFactory, missing 'num_steps' entry");

      double step_size = (max_joint_val - min_joint_val)/static_cast<double>(num_steps);

      double curr_j_val = min_joint_val;
      while (curr_j_val <= max_joint_val)
      {
        free_joint_combos.push_back({curr_j_val});
        curr_j_val += step_size;
      }
    }

    path = scene_graph.getShortestPath(base_link, tip_link);
  }
  catch (const std::exception& e)
  {
    CONSOLE_BRIDGE_logError("iiwa7InvKinFactory: Failed to parse yaml config data! Details: %s", e.what());
    return nullptr;
  }

  return std::make_unique<iiwa7Kinematics>(base_link, tip_link, path.active_joints, solver_name, free_joint_combos);
}

}

TESSERACT_ADD_PLUGIN(iiwa_ikfast_kinematics::iiwa7Free7InvKinFactory, iiwa7Free7InvKinFactory);
