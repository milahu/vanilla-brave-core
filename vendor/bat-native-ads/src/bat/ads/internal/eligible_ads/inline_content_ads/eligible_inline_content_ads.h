/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_ELIGIBLE_ADS_INLINE_CONTENT_ADS_ELIGIBLE_INLINE_CONTENT_ADS_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_ELIGIBLE_ADS_INLINE_CONTENT_ADS_ELIGIBLE_INLINE_CONTENT_ADS_H_

#include <string>

#include "bat/ads/internal/ad_events/ad_event_info.h"
#include "bat/ads/internal/bundle/creative_inline_content_ad_info.h"
#include "bat/ads/internal/frequency_capping/frequency_capping_aliases.h"
#include "third_party/abseil-cpp/absl/types/optional.h"

namespace ads {

using GetForFeaturesCallback =
    std::function<void(const bool,
                       const absl::optional<CreativeInlineContentAdInfo>)>;

namespace ad_targeting {
struct UserModelInfo;
namespace geographic {
class SubdivisionTargeting;
}  // namespace geographic
}  // namespace ad_targeting

namespace resource {
class AntiTargeting;
}  // namespace resource

namespace inline_content_ads {

using GetForSegmentsCallback =
    std::function<void(const bool, const CreativeInlineContentAdList&)>;

class EligibleAds {
 public:
  EligibleAds(
      ad_targeting::geographic::SubdivisionTargeting* subdivision_targeting,
      resource::AntiTargeting* anti_targeting);

  ~EligibleAds();

  void SetLastServedAd(const CreativeAdInfo& creative_ad);

  void Get(const ad_targeting::UserModelInfo& user_model,
           const std::string& dimensions,
           GetEligibleAdsCallback callback);

  void GetForFeatures(const SegmentList& interest_segments,
                      const SegmentList& intent_segments,
                      const std::string& dimensions,
                      GetForFeaturesCallback callback);

 private:
  ad_targeting::geographic::SubdivisionTargeting*
      subdivision_targeting_;  // NOT OWNED

  resource::AntiTargeting* anti_targeting_resource_;  // NOT OWNED

  CreativeAdInfo last_served_creative_ad_;

  void GetEligibleAds(const SegmentList& interest_segments,
                      const SegmentList& intent_segments,
                      const AdEventList& ad_events,
                      const BrowsingHistoryList& browsing_history,
                      const std::string& dimensions,
                      GetForFeaturesCallback callback) const;

  void ChooseAd(const CreativeInlineContentAdList& eligible_ads,
                const AdEventList& ad_events,
                const SegmentList& interest_segments,
                const SegmentList& intent_segments,
                GetForFeaturesCallback callback) const;

  void GetForParentChildSegments(const ad_targeting::UserModelInfo& user_model,
                                 const std::string& dimensions,
                                 const AdEventList& ad_events,
                                 const BrowsingHistoryList& browsing_history,
                                 GetForSegmentsCallback callback) const;

  void GetForParentSegments(const ad_targeting::UserModelInfo& user_model,
                            const std::string& dimensions,
                            const AdEventList& ad_events,
                            const BrowsingHistoryList& browsing_history,
                            GetForSegmentsCallback callback) const;

  void GetForUntargeted(const std::string& dimensions,
                        const AdEventList& ad_events,
                        const BrowsingHistoryList& browsing_history,
                        GetForSegmentsCallback callback) const;

  CreativeInlineContentAdList FilterIneligibleAds(
      const CreativeInlineContentAdList& ads,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history) const;

  CreativeInlineContentAdList ApplyFrequencyCapping(
      const CreativeInlineContentAdList& ads,
      const CreativeAdInfo& last_served_creative_ad,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history) const;
};

}  // namespace inline_content_ads
}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_ELIGIBLE_ADS_INLINE_CONTENT_ADS_ELIGIBLE_INLINE_CONTENT_ADS_H_
