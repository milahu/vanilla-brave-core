/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_AD_EVENTS_AD_EVENT_UNITTEST_UTIL_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_AD_EVENTS_AD_EVENT_UNITTEST_UTIL_H_

#include <string>

#include "bat/ads/internal/ad_events/ad_event_info.h"
#include "bat/ads/internal/bundle/creative_ad_info.h"

namespace ads {

AdEventInfo GetAdEvent(
    const CreativeAdInfo& creative_ad,
    const ConfirmationType confirmation_type,
    const base::Time& timestamp);

}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_AD_EVENTS_AD_EVENT_UNITTEST_UTIL_H_
