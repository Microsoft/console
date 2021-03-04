/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- AppearanceConfig

Abstract:
- The implementation of the AppearanceConfig winrt class. Provides settings related
  to the appearance of the terminal, in both terminal control and terminal core.

Author(s):
- Pankaj Bhojwani - Nov 2020

--*/

#pragma once

#include "pch.h"
#include "AppearanceConfig.g.h"
#include "JsonUtils.h"
#include "../inc/cppwinrt_utils.h"
#include "IInheritable.h"
#include "Profile.h"

namespace winrt::Microsoft::Terminal::Settings::Model::implementation
{
    struct AppearanceConfig : AppearanceConfigT<AppearanceConfig>, IInheritable<Profile>
    {
    public:
        AppearanceConfig();

        static winrt::com_ptr<AppearanceConfig> CopyAppearance(const winrt::com_ptr<AppearanceConfig> source);
        Json::Value ToJson() const;

        void LayerJson(const Json::Value& json);
        winrt::hstring ExpandedBackgroundImagePath();

        GETSET_SETTING(Model::IAppearanceConfig, ConvergedAlignment, BackgroundImageAlignment, ConvergedAlignment::Horizontal_Center | ConvergedAlignment::Vertical_Center);

        GETSET_SETTING(Model::IAppearanceConfig, uint32_t, CursorHeight, DEFAULT_CURSOR_HEIGHT);
        GETSET_SETTING(Model::IAppearanceConfig, hstring, ColorSchemeName, L"Campbell");
        GETSET_NULLABLE_SETTING(Model::IAppearanceConfig, Windows::UI::Color, Foreground, nullptr);
        GETSET_NULLABLE_SETTING(Model::IAppearanceConfig, Windows::UI::Color, Background, nullptr);
        GETSET_NULLABLE_SETTING(Model::IAppearanceConfig, Windows::UI::Color, SelectionBackground, nullptr);
        GETSET_NULLABLE_SETTING(Model::IAppearanceConfig, Windows::UI::Color, CursorColor, nullptr);
        GETSET_SETTING(Model::IAppearanceConfig, Microsoft::Terminal::TerminalControl::CursorStyle, CursorShape, Microsoft::Terminal::TerminalControl::CursorStyle::Bar);
        GETSET_SETTING(Model::IAppearanceConfig, hstring, BackgroundImagePath);

        GETSET_SETTING(Model::IAppearanceConfig, double, BackgroundImageOpacity, 1.0);
        GETSET_SETTING(Model::IAppearanceConfig, Windows::UI::Xaml::Media::Stretch, BackgroundImageStretchMode, Windows::UI::Xaml::Media::Stretch::UniformToFill);

    private:
    };
}

namespace winrt::Microsoft::Terminal::Settings::Model::factory_implementation
{
    BASIC_FACTORY(AppearanceConfig);
}