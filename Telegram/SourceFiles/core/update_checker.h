/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "mtproto/dedicated_file_loader.h"
#include "base/weak_ptr.h"

#include <rpl/never.h>

#include <QtCore/QString>

namespace Main {
class Session;
} // namespace Main

namespace Core {

// Windows-only personal fork: update delivery is intentionally not present.
// These tiny inline no-ops preserve source compatibility with upstream UI code
// while allowing the compiler to remove updater-only branches completely.
[[nodiscard]] inline constexpr bool UpdaterDisabled() {
    return true;
}
inline void SetUpdaterDisabledAtStartup() {
}

class UpdateChecker final {
public:
    enum class State {
        None,
        Download,
        Ready,
    };
    using Progress = MTP::AbstractDedicatedLoader::Progress;

    UpdateChecker() = default;

    [[nodiscard]] rpl::producer<> checking() const {
        return rpl::never<>();
    }
    [[nodiscard]] rpl::producer<> isLatest() const {
        return rpl::never<>();
    }
    [[nodiscard]] rpl::producer<Progress> progress() const {
        return rpl::never<Progress>();
    }
    [[nodiscard]] rpl::producer<> failed() const {
        return rpl::never<>();
    }
    [[nodiscard]] rpl::producer<> ready() const {
        return rpl::never<>();
    }

    void start(bool = false) {
    }
    void stop() {
    }
    void test() {
    }
    void setMtproto(base::weak_ptr<Main::Session>) {
    }

    [[nodiscard]] State state() const {
        return State::None;
    }
    [[nodiscard]] int already() const {
        return 0;
    }
    [[nodiscard]] int size() const {
        return 0;
    }
    [[nodiscard]] bool percent() const {
        return false;
    }
};

[[nodiscard]] inline constexpr bool checkReadyUpdate() {
    return false;
}
inline void UpdateApplication() {
}
[[nodiscard]] inline QString countAlphaVersionSignature(uint64) {
    return QString();
}

} // namespace Core
