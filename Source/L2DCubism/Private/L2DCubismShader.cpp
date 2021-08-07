// Copyright 2020 demuyan
// SPDX-License-Identifier: MIT
// Licensed under the MIT Open Source License, for details please see license.txt or the website
// http://www.opensource.org/licenses/mit-license.php

#include "L2DCubismShader.h"
#include "Shader.h"
#include "Serialization/MemoryLayout.h"

// IMPLEMENT_GLOBAL_SHADER(FL2DCubismVertMasked, "/Plugin/L2DCubism/L2DCubismShader.usf", "MaskedVS", SF_Vertex);
// class FL2DCubismPixelMasked;

// mask generation
IMPLEMENT_SHADER_TYPE(, FL2DCubismVertSetupMask, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("SetupMaskVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelSetupMask, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("SetupMaskPS"), SF_Pixel);
// VertexShader
IMPLEMENT_SHADER_TYPE(, FL2DCubismVertNormal, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("NormalVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FL2DCubismVertMasked, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("MaskedVS"), SF_Vertex);
// PixelShader
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelNormal, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("NormalPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMasked, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("MaskedPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMaskedInverted, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("MaskedInvertedPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelNormalPremult, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("NormalPremultPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMaskedPremult, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("MaskedPremultPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMaskedInvertedPremult, TEXT("/Plugin/L2DCubism/L2DCubismShader.usf"), TEXT("MaskedInvertedPremultPS"), SF_Pixel);

