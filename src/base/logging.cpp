/* Copyright (C) 2020, Nikolai Wuttke. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "logging.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>


namespace rigel::base {

void initLogging(const std::string& logfilePath)
{
  auto console = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
  console->set_level(spdlog::level::warn);

  auto file = std::make_shared<spdlog::sinks::basic_file_sink_st>(
    logfilePath, true);
  file->set_level(spdlog::level::info);

  spdlog::set_default_logger(
    std::make_shared<spdlog::logger>(spdlog::logger{"combined", {console, file}}));
}

}
