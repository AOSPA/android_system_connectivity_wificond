/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "wificond/scanning/pno_network.h"

#include <android-base/logging.h>

#include "wificond/parcelable_utils.h"

using android::status_t;

namespace android {
namespace net {
namespace wifi {
namespace nl80211 {

status_t PnoNetwork::writeToParcel(::android::Parcel* parcel) const {
  RETURN_IF_FAILED(parcel->writeInt32(is_hidden_ ? 1 : 0));
  RETURN_IF_FAILED(parcel->writeByteVector(ssid_));
  RETURN_IF_FAILED(parcel->writeInt32Vector(frequencies_));
  return ::android::OK;
}

status_t PnoNetwork::readFromParcel(const ::android::Parcel* parcel) {
  int32_t is_hidden = 0;
  RETURN_IF_FAILED(parcel->readInt32(&is_hidden));
  is_hidden_ = (is_hidden != 0);
  RETURN_IF_FAILED(parcel->readByteVector(&ssid_));
  RETURN_IF_FAILED(parcel->readInt32Vector(&frequencies_));
  return ::android::OK;
}

}  // namespace nl80211
}  // namespace wifi
}  // namespace net
}  // namespace android
