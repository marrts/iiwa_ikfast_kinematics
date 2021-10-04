# iiwa_ikfast_kinematics
tesseract_ikfast solvers for iiwa robots

NOTE: This IKFast implementation is setup to plan to a TCP that is 0.02485 meters past the iiwa_link_ee in the z direction. 
The transform can be achieved by adding the following to a URDF.

```
  <link name="iiwa_ikfast_tcp_link"/>
  <joint name="to_ikfast_link" type="fixed">
      <origin xyz="0.0 0.0 0.02485" rpy="0.0 0.0 0.0"/>
      <parent link="iiwa_link_ee"/>
      <child link="iiwa_ikfast_tcp_link"/>
  </joint>
```
