// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "brave/browser/brave_ads/brave_ads_driver_private.h"

#include <utility>

namespace brave_ads {

BraveAdsDriverPrivate::BraveAdsDriverPrivate() = default;

BraveAdsDriverPrivate::~BraveAdsDriverPrivate() = default;

void BraveAdsDriverPrivate::RequestAdsEnabled(
    RequestAdsEnabledCallback callback) {
  std::move(callback).Run(false);
}

}  // namespace brave_ads
