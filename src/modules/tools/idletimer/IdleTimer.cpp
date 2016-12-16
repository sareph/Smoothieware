/*
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>.
*/

#include "libs/Module.h"
#include "libs/Kernel.h"
#include <math.h>
#include "IdleTimer.h"
#include "TemperatureControlPool.h"
#include "libs/Pin.h"
#include "modules/robot/Conveyor.h"
#include "PublicDataRequest.h"

//#define sensor_checksum                    CHECKSUM("sensor")

//#define readings_per_second_checksum       CHECKSUM("readings_per_second")

IdleTimer::IdleTimer(uint16_t name, int index)
{
}

IdleTimer::~IdleTimer()
{
}

void TemperatureControl::on_module_loaded()
{
}

void TemperatureControl::on_halt(void *arg)
{
}

void TemperatureControl::on_main_loop(void *argument)
{
}

void TemperatureControl::on_gcode_received(void *argument)
{
    Gcode *gcode = static_cast<Gcode *>(argument);
    if (gcode->has_m) {

    }
}

void TemperatureControl::on_second_tick(void *argument)
{
    // Check whether or not there is a temperature runaway issue, if so stop everything and report it
    if(THEKERNEL->is_halted()) return;

    // see if runaway detection is enabled
    if(this->runaway_heating_timeout == 0 && this->runaway_range == 0) return;

}