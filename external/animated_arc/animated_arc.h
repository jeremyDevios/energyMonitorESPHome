#include "esphome.h"
#include "lvgl.h"

class AnimatedArc : public Component, public SensorListener {
 public:
  AnimatedArc(lvgl::Arc *arc, Sensor *source, uint16_t duration_ms = 500, uint16_t step_ms = 20)
    : arc_(arc), source_(source), duration_(duration_ms), step_(step_ms) {
    source_->add_on_state_callback([this](float state) {
      this->target_value_ = static_cast<int>(state);
      this->start_animation_ = true;
    });
  }

  void setup() override {
    current_value_ = target_value_ = static_cast<int>(source_->state);
  }

  void loop() override {
    if (!start_animation_) return;

    uint32_t now = millis();
    if (now - last_step_ < step_) return;
    last_step_ = now;

    if (current_value_ == target_value_) {
      start_animation_ = false;
      return;
    }

    // Animation step: ease toward the target
    if (current_value_ < target_value_) current_value_++;
    else current_value_--;

    lv_arc_set_value(arc_->get_lv_obj(), current_value_);
  }

 protected:
  lvgl::Arc *arc_;
  Sensor *source_;
  int current_value_{0};
  int target_value_{0};
  uint16_t duration_;
  uint16_t step_;
  uint32_t last_step_{0};
  bool start_animation_{false};
};
