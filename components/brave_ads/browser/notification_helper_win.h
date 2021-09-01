/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_ADS_BROWSER_NOTIFICATION_HELPER_WIN_H_
#define BRAVE_COMPONENTS_BRAVE_ADS_BROWSER_NOTIFICATION_HELPER_WIN_H_

#include "brave/components/brave_ads/browser/notification_helper.h"

#include <windows.ui.notifications.h>
#include <wrl/event.h>

#include "base/memory/weak_ptr.h"

namespace brave_ads {

class NotificationHelperWin
    : public NotificationHelper,
      public base::SupportsWeakPtr<NotificationHelperWin> {
 public:
  NotificationHelperWin(const NotificationHelperWin&) = delete;
  NotificationHelperWin& operator=(const NotificationHelperWin&) = delete;

  static NotificationHelperWin* GetInstanceImpl();

 private:
  friend struct base::DefaultSingletonTraits<NotificationHelperWin>;

  NotificationHelperWin();
  ~NotificationHelperWin() override;

  bool IsNotificationsEnabled();

  HRESULT InitializeToastNotifier();

  Microsoft::WRL::ComPtr<ABI::Windows::UI::Notifications::IToastNotifier>
      notifier_;

  // NotificationHelper:
  bool CanShowNativeNotifications() override;

  bool CanShowBackgroundNotifications() const override;

  bool ShowMyFirstAdNotification() override;
};

}  // namespace brave_ads

#endif  // BRAVE_COMPONENTS_BRAVE_ADS_BROWSER_NOTIFICATION_HELPER_WIN_H_
