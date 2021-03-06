#ifndef RENDER_CONFIG_H
#define RENDER_CONFIG_H

#include "common-util.h"

#include <string>

namespace example {

struct RenderConfig {
  // framebuffer
  int width;
  int height;

  // camera
  float eye[3];
  float up[3];
  float look_at[3];
  float fov;  // vertical fov in degree.

  // render pass
  int pass = 0;
  int max_passes = 65535;

  // Scene input info
  std::string obj_filename;
  std::string eson_filename;
  std::string bvh_filename;
  float scene_scale;

  // plane parameter
  bool gen_plane = false;
  int u_div = 128;
  int v_div = 128;
  float plane_scale[3] = {1.0f, 1.0f, 1.0f};

  // vdisp parameter.
  VDispSpace vdisp_space;
  float vdisp_scale = 1.0f;
  bool area_weighting = true; // Consider polygon area when recomputing normals from displaced mesh.

};

/// Loads config from JSON file.
bool LoadRenderConfig(example::RenderConfig *config, const char *filename);

}  // namespace

#endif  // RENDER_CONFIG_H
