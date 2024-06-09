#include "PixelShader_Header.hlsli"

Texture2D maskTex : register(t1);
SamplerState maskTexSampler : register(s1);

// 定数バッファ
cbuffer buff : register(b0)
{
	// マスクの強さ(?)
	// デフォルトは1.0fです
	float maskPow;
	
	// 空白
	float3 padding;
}

float4 main(PS_INPUT input) : SV_TARGET
{
	// 各テクスチャの色
	float4 color = tex.Sample(texSampler, input.uv);
	float4 maskColor = maskTex.Sample(maskTexSampler, input.uv);
	
	// ソフトマスクの画像の色をメインテクスチャの透明度として使う
	// マスク画像は白黒なので適当にrを指定してます
	color.a = maskColor.r * maskPow;
	
	return color;
}