import esphome.codegen as cg
import esphome.config_validation as cv
import esphome.core as core
import esphome.core.config as cfg
from esphome.core import CORE, coroutine_with_priority
from esphome.const import (
    CONF_ID,
    CONF_BRIGHTNESS
)

CODEOWNERS = ["@JLE"]

LVGL_BUILD_FLAGS = [
    "-D LV_USE_DEV_VERSION=1",
    "-D LV_LVGL_H_INCLUDE_SIMPLE=1",
]

esp32eyes_ns = cg.esphome_ns.namespace("esp32eyes")
Esp32EyesComponent = esp32eyes_ns.class_("Esp32EyesComponent", cg.Component)

# Add esp32-eyes source files and libraries at the module level
#cg.add_build_flag("-lSPI")   # Ensure SPI is linked
#cg.add_build_flag("-lWire")  # Ensure Wire is linked (for I2C, sometimes needed)
#cg.add_library("olikraus/U8g2", "^2.34.22")  # Add u8g2 dependency
# Add any other required build flags or libraries

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(Esp32EyesComponent),
        # Add any esp32-eyes specific configuration options here
    }
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    # Add any esp32-eyes specific initialization here
    #whereami = os.path.realpath(__file__)
    #component_dir = os.path.dirname(whereami)

    #lv_conf_path = os.path.join(component_dir, 'lv_conf.h')
    #core.CORE.add_job(cfg.add_includes, [lv_conf_path])
