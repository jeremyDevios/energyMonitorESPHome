#pragma once
#include "esphome/core/component.h"
#include "esphome/components/lvgl/arc.h"

namespace esphome {
namespace arc_angle_updater {

class ArcAngleUpdater : public Component {
 public:
  void setup() override {
    // Create the arc widget
    arc_ = new esphome::lvgl::Arc();
    arc_->set_x(0);
    arc_->set_y(0);
    arc_->set_width(220);
    arc_->set_height(220);
    arc_->set_start_angle(160);
    arc_->set_end_angle(300);
    arc_->set_line_width(10);
    arc_->set_arc_color(0xFF2626);
    arc_->set_align(esphome::lvgl::ALIGN_CENTER);
    arc_->set_parent(nullptr);  // Add to root
  }

  void loop() override {
    if (!arc_ || !arc_->lv_obj()) return;
    int angle = 160 + (rand() % 200);  // Random angle between 160 and 360
    arc_->lv_obj()->set_angle_end(angle);
    delay(500);  // Slow down updates
  }

 protected:
  esphome::lvgl::Arc *arc_{nullptr};
};

}  // namespace arc_angle_updater
}  // namespace esphome

ESPHOME_EXTERNAL_COMPONENT_REGISTER(esphome::arc_angle_updater::ArcAngleUpdater, arc_angle_updater, "arc_angle_updater");
