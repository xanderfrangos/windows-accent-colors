#include <napi.h>
#pragma comment(lib, "windowsapp")
#include <winrt/Windows.UI.ViewManagement.h>

using namespace winrt;
using namespace Windows::UI::ViewManagement;

Napi::Object getAccentObject(UIColorType colorType, const Napi::CallbackInfo &info) {
    UISettings const ui_settings {};
    auto const color { ui_settings.GetColorValue(colorType) };

    Napi::Object accent = Napi::Object::New(info.Env());
    accent.Set("r", Napi::Number::New(info.Env(), color.R));
    accent.Set("g", Napi::Number::New(info.Env(), color.G));
    accent.Set("b", Napi::Number::New(info.Env(), color.B));

    return accent;
}

Napi::Object getAccentColors(const Napi::CallbackInfo &info)
{
    Napi::Object colors = Napi::Object::New(info.Env());

    colors.Set("accent", getAccentObject(UIColorType::Accent, info));

    colors.Set("accentDark1", getAccentObject(UIColorType::AccentDark1, info));
    colors.Set("accentDark2", getAccentObject(UIColorType::AccentDark2, info));
    colors.Set("accentDark3", getAccentObject(UIColorType::AccentDark3, info));

    colors.Set("accentLight1", getAccentObject(UIColorType::AccentLight1, info));
    colors.Set("accentLight2", getAccentObject(UIColorType::AccentLight2, info));
    colors.Set("accentLight3", getAccentObject(UIColorType::AccentLight3, info));

    colors.Set("background", getAccentObject(UIColorType::Background, info));
    colors.Set("foreground", getAccentObject(UIColorType::Foreground, info));

    return colors;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "getAccentColors"),
                Napi::Function::New(env, getAccentColors));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);