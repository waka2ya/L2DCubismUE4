// Copyright 2020 demuyan
// SPDX-License-Identifier: MIT
// Licensed under the MIT Open Source License, for details please see license.txt or the website
// http://www.opensource.org/licenses/mit-license.php

#pragma once

#include "CoreMinimal.h"
#include "ShaderParameters.h"
#include "Shader.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"

class FL2DCubismShader : public FGlobalShader
{
    DECLARE_INLINE_TYPE_LAYOUT(FL2DCubismShader, NonVirtual);
    // DECLARE_EXPORTED_TYPE_LAYOUT(FL2DCubismShader, L2DCUBISM_API, NonVirtual);
public:
    FL2DCubismShader() {}

    FL2DCubismShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
        : FGlobalShader(Initializer)
    {
        ProjectMatrix.Bind(Initializer.ParameterMap, TEXT("projectMatrix"));
        ClipMatrix.Bind(Initializer.ParameterMap, TEXT("clipMatrix"));
        BaseColor.Bind(Initializer.ParameterMap, TEXT("baseColor"));
        ChannelFlag.Bind(Initializer.ParameterMap, TEXT("channelFlag") );

        MainTexture.Bind(Initializer.ParameterMap, TEXT("mainTexture"));
        MainSampler.Bind(Initializer.ParameterMap, TEXT("mainSampler"));
        MaskTexture.Bind(Initializer.ParameterMap, TEXT("maskTexture"));
    }

    template<typename TShaderRHIParamRef>
    void SetParameters(
        FRHICommandList& RHICmdList, 
        const TShaderRHIParamRef ShaderRHI, 
        const FMatrix44f& InProjectMatrix,
        const FMatrix44f& InClipMatrix,
        const FVector4f& InBaseColor,
        const FVector4f& InChannelFlag,
        FTextureRHIRef InMainTexture,
        FTextureRHIRef InMaskTexture
        )
    {
        SetShaderValue(RHICmdList, ShaderRHI, ProjectMatrix, InProjectMatrix);
        SetShaderValue(RHICmdList, ShaderRHI, ClipMatrix, InClipMatrix);
        SetShaderValue(RHICmdList, ShaderRHI, BaseColor, InBaseColor);
        SetShaderValue(RHICmdList, ShaderRHI, ChannelFlag, InChannelFlag);

        SetTextureParameter(RHICmdList, ShaderRHI, MainTexture, InMainTexture);
        SetSamplerParameter(RHICmdList, ShaderRHI, MainSampler, TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI());
        SetTextureParameter(RHICmdList, ShaderRHI, MaskTexture, InMaskTexture);
    }
    
    //// FShader interface.
    //virtual bool Serialize(FArchive& Ar) override
    //{
    //    bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
    //    Ar  << ProjectMatrix
    //        << ClipMatrix
    //        << BaseColor
    //        << ChannelFlag
    //        << MainTexture
    //        << MainSampler;
    //    Ar << MaskTexture;

    //    return bShaderHasOutdatedParameters;
    //}
    
    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
    {
        FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
    }
    
protected:
    /*FShaderParameter ProjectMatrix;
    FShaderParameter ClipMatrix;
    FShaderParameter BaseColor;
    FShaderParameter ChannelFlag;*/
    LAYOUT_FIELD(FShaderParameter, ProjectMatrix);
    LAYOUT_FIELD(FShaderParameter, ClipMatrix);
    LAYOUT_FIELD(FShaderParameter, BaseColor);
    LAYOUT_FIELD(FShaderParameter, ChannelFlag);

    //FShaderResourceParameter MainTexture;
    //FShaderResourceParameter MainSampler;
    //FShaderResourceParameter MaskTexture;
	LAYOUT_FIELD(FShaderResourceParameter, MainTexture);
	LAYOUT_FIELD(FShaderResourceParameter, MainSampler);
	LAYOUT_FIELD(FShaderResourceParameter, MaskTexture);
};

class FL2DCubismVertNormal : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismVertNormal);
public:
	FL2DCubismVertNormal() {}

	FL2DCubismVertNormal(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{}
};


class FL2DCubismVertMasked : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismVertMasked);
public:
	FL2DCubismVertMasked() {}

	FL2DCubismVertMasked(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{}
};

class FL2DCubismPixelNormal : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismPixelNormal);
public:
	FL2DCubismPixelNormal() {}

	FL2DCubismPixelNormal(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{
	}
};

class FL2DCubismPixelMasked : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismPixelMasked);
public:
	FL2DCubismPixelMasked() {}

	FL2DCubismPixelMasked(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{
	}
};


class FL2DCubismPixelMaskedInverted : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismPixelMaskedInverted);
public:
	FL2DCubismPixelMaskedInverted() {}

	FL2DCubismPixelMaskedInverted(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{
	}
};

class FL2DCubismPixelMaskedPremult : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismPixelMaskedPremult);
public:
	FL2DCubismPixelMaskedPremult() {}

	FL2DCubismPixelMaskedPremult(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{
	}
};

class FL2DCubismPixelNormalPremult : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismPixelNormalPremult);
public:
	FL2DCubismPixelNormalPremult() {}

	FL2DCubismPixelNormalPremult(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{
	}
};


class FL2DCubismPixelMaskedInvertedPremult : public FL2DCubismShader
{
	DECLARE_GLOBAL_SHADER(FL2DCubismPixelMaskedInvertedPremult);
public:
	FL2DCubismPixelMaskedInvertedPremult() {}

	FL2DCubismPixelMaskedInvertedPremult(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FL2DCubismShader(Initializer)
	{
	}
};


class FL2DCubismMaskShader : public FGlobalShader
{
    DECLARE_INLINE_TYPE_LAYOUT(FL2DCubismMaskShader, NonVirtual);
    // DECLARE_EXPORTED_TYPE_LAYOUT(FL2DCubismMaskShader, L2DCUBISM_API, NonVirtual);
public:
    FL2DCubismMaskShader() {}

    FL2DCubismMaskShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
        : FGlobalShader(Initializer)
    {
        ProjectMatrix.Bind(Initializer.ParameterMap, TEXT("projectMatrix"));
        BaseColor.Bind(Initializer.ParameterMap, TEXT("baseColor"));
        ChannelFlag.Bind(Initializer.ParameterMap, TEXT("channelFlag"));

        MainTexture.Bind(Initializer.ParameterMap, TEXT("mainTexture"));
        MainSampler.Bind(Initializer.ParameterMap, TEXT("mainSampler"));
    }

    template<typename TShaderRHIParamRef>
    void SetParameters(
        FRHICommandList& RHICmdList,
        const TShaderRHIParamRef ShaderRHI,
        const FMatrix44f& InProjectMatrix,
        const FVector4f& InBaseColor,
        const FVector4f& InChannelFlag,
        FTextureRHIRef InMainTexture
    )
    {
        SetShaderValue(RHICmdList, ShaderRHI, ProjectMatrix, InProjectMatrix);
        SetShaderValue(RHICmdList, ShaderRHI, BaseColor, InBaseColor);
        SetShaderValue(RHICmdList, ShaderRHI, ChannelFlag, InChannelFlag);

        SetTextureParameter(RHICmdList, ShaderRHI, MainTexture, InMainTexture);
        SetSamplerParameter(RHICmdList, ShaderRHI, MainSampler, TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Wrap, AM_Wrap>::GetRHI());
    }

    //// FShader interface.
    //virtual bool Serialize(FArchive& Ar) override
    //{
    //    bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
    //    Ar << ProjectMatrix;
    //    Ar << BaseColor;
    //    Ar << ChannelFlag;
    //    Ar << MainTexture;
    //    Ar << MainSampler;

    //    return bShaderHasOutdatedParameters;
    //}

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
    {
        FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
    }

protected:
    /*FShaderParameter ProjectMatrix;
    FShaderParameter BaseColor;
    FShaderParameter ChannelFlag;*/
    LAYOUT_FIELD(FShaderParameter, ProjectMatrix);
    LAYOUT_FIELD(FShaderParameter, BaseColor);
    LAYOUT_FIELD(FShaderParameter, ChannelFlag);

    /*FShaderResourceParameter MainTexture;
    FShaderResourceParameter MainSampler;*/

	LAYOUT_FIELD(FShaderResourceParameter, MainTexture);
	LAYOUT_FIELD(FShaderResourceParameter, MainSampler);
};


class FL2DCubismVertSetupMask : public FL2DCubismMaskShader
{
    DECLARE_GLOBAL_SHADER(FL2DCubismVertSetupMask);
public:
    FL2DCubismVertSetupMask() {}

    FL2DCubismVertSetupMask(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
        : FL2DCubismMaskShader(Initializer)
    {}
};

class FL2DCubismPixelSetupMask : public FL2DCubismMaskShader
{
    DECLARE_GLOBAL_SHADER(FL2DCubismPixelSetupMask);
public:
    FL2DCubismPixelSetupMask() {}

    FL2DCubismPixelSetupMask(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
        : FL2DCubismMaskShader(Initializer)
    {}
};


