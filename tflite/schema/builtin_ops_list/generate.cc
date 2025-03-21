/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <iostream>

#include "tflite/schema/builtin_ops_list/generator.h"

// This executable is used to generate builtin_ops.h in TensorFlow Lite.
// Please see README.md for more details.
int main() {
  if (!tflite::builtin_ops_list::GenerateHeader(std::cout)) {
    std::cerr << "Failed to generate the header file.\n";
  }
  return 0;
}
