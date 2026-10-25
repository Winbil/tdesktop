/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <QtCore/QString>
#include <QtCore/QtGlobal>

namespace Core {

inline constexpr auto BuildIsCanary = false;
inline constexpr auto CanaryBuildCounter = quint32(0);
inline constexpr auto CanaryCommitHash = "";

[[nodiscard]] inline QString CanaryVersionSuffix() {
    return QString();
}

[[nodiscard]] inline QString CanaryTitleLabel() {
    return QString();
}

} // namespace Core
