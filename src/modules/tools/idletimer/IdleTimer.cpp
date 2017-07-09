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

#include "checksumm.h"
#include "Gcode.h"

//#define sensor_checksum                    CHECKSUM("sensor")

//#define readings_per_second_checksum       CHECKSUM("readings_per_second")

IdleTimer::IdleTimer() : idle_time(0)
{
}

IdleTimer::~IdleTimer()
{
}

void IdleTimer::on_module_loaded()
{
}

void IdleTimer::on_halt(void *arg)
{
}

void IdleTimer::on_main_loop(void *argument)
{
}

void IdleTimer::on_gcode_received(void *argument)
{
    Gcode *gcode = static_cast<Gcode *>(argument);
    if (gcode->has_g) {
		idle_time = 0;
    }
}

void IdleTimer::on_second_tick(void *argument)
{
	++idle_time;
}