// Copyright 2020 demuyan
// SPDX-License-Identifier: MIT
// Licensed under the MIT Open Source License, for details please see license.txt or the website
// http://www.opensource.org/licenses/mit-license.php

#include "L2DCubismShader.h"
#include "Shader.h"
#include "Serialization/MemoryLayout.h"

// IMPLEMENT_GLOBAL_SHADER(FL2DCubismVertMasked, "/Shader/L2DCubismShader.usf", "MaskedVS", SF_Vertex);
// class FL2DCubismPixelMasked;

// mask generation
IMPLEMENT_SHADER_TYPE(, FL2DCubismVertSetupMask, TEXT("/Shader/L2DCubismShader.usf"), TEXT("SetupMaskVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelSetupMask, TEXT("/Shader/L2DCubismShader.usf"), TEXT("SetupMaskPS"), SF_Pixel);
// VertexShader
IMPLEMENT_SHADER_TYPE(, FL2DCubismVertNormal, TEXT("/Shader/L2DCubismShader.usf"), TEXT("NormalVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FL2DCubismVertMasked, TEXT("/Shader/L2DCubismShader.usf"), TEXT("MaskedVS"), SF_Vertex);
// PixelShader
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelNormal, TEXT("/Shader/L2DCubismShader.usf"), TEXT("NormalPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMasked, TEXT("/Shader/L2DCubismShader.usf"), TEXT("MaskedPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMaskedInverted, TEXT("/Shader/L2DCubismShader.usf"), TEXT("MaskedInvertedPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelNormalPremult, TEXT("/Shader/L2DCubismShader.usf"), TEXT("NormalPremultPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMaskedPremult, TEXT("/Shader/L2DCubismShader.usf"), TEXT("MaskedPremultPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FL2DCubismPixelMaskedInvertedPremult, TEXT("/Shader/L2DCubismShader.usf"), TEXT("MaskedInvertedPremultPS"), SF_Pixel);

