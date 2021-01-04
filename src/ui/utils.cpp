/* Copyright (C) 2019, Nikolai Wuttke. All rights reserved.
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

#include "utils.hpp"

#include "loader/resource_loader.hpp"


namespace rigel::ui {

ImU32 toImgui(const base::Color& color) {
RIGEL_DISABLE_WARNINGS
  return IM_COL32(color.r, color.g, color.b, color.a);
RIGEL_RESTORE_WARNINGS
}


renderer::Texture fullScreenImageAsTexture(
  renderer::Renderer* pRenderer,
  const loader::ResourceLoader& resources,
  const std::string& imageName
) {
  return renderer::Texture(
    pRenderer,
    resources.loadStandaloneFullscreenImage(imageName));
}


engine::TiledTexture makeUiSpriteSheet(
  renderer::Renderer* pRenderer,
  const loader::ResourceLoader& resourceLoader,
  const loader::Palette16& palette
) {
  return engine::TiledTexture{
    renderer::Texture{
      pRenderer,
      resourceLoader.loadTiledFullscreenImage(
        "STATUS.MNI", palette)},
    pRenderer};
}


void drawText(
  const std::string_view text,
  const int x,
  const int y,
  const base::Color& color
) {
  auto pDrawList = ImGui::GetForegroundDrawList();
  pDrawList->AddText(
    {static_cast<float>(x), static_cast<float>(y)},
    toImgui(color),
    text.data(),
    text.data() + text.size());
}

}
