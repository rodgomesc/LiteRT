# Copyright 2025 Google LLC.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("//tflite/experimental/litert/build_common:tfl_model_gen.bzl", "tfl_model_gen")

package(
    # copybara:uncomment default_applicable_licenses = ["@org_tensorflow//tensorflow:license"],
    default_visibility = ["//tflite/experimental/litert:__subpackages__"],
)

cc_test(
    name = "gen_device_test",
    srcs = ["gen_device_test.cc"],
    copts = ["-DGOOGLE_COMMANDLINEFLAGS_FULL_API=1"],
    data = [":single_op_models"],
    linkopts = select({
        "@org_tensorflow//tensorflow:android": ["-landroid"],
        "//conditions:default": [],
    }),
    deps = [
        ":gen_device_test_lib",
        "//tflite/experimental/litert/c:litert_logging",
        "//tflite/experimental/litert/cc:litert_environment",
        "//tflite/experimental/litert/cc:litert_model",
        "//tflite/experimental/litert/test:common",
        "//tflite/experimental/litert/test:matchers",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/strings:str_format",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/types:span",
        "@com_google_googletest//:gtest",
    ],
)

cc_library(
    name = "gen_device_test_lib",
    testonly = True,
    hdrs = ["gen_device_test_lib.h"],
    deps = [
        "//tflite/experimental/litert/c:litert_common",
        "//tflite/experimental/litert/cc:litert_compiled_model",
        "//tflite/experimental/litert/cc:litert_environment",
        "//tflite/experimental/litert/cc:litert_model",
        "//tflite/experimental/litert/cc:litert_tensor_buffer",
        "//tflite/experimental/litert/core/model",
        "//tflite/experimental/litert/test:matchers",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_googletest//:gtest",
    ],
)

filegroup(
    name = "classic_ml_models",
    srcs = glob(["classic_ml_models/*.tflite"]),
)

tfl_model_gen(
    name = "single_op_models",
    srcs = glob(["single_op_models/*.mlir"]),
    subdir = "single_op_models",
)
