#include "PixelShader_Header.hlsli"

// HSVをRGBに変換(Kamoshikaさん作)
float3 HSV2RGB(float h, float s, float v)
{
	float3 rgb = frac(h + float3(0.0f, 2.0f, 1.0f) / 3.0f) * 6.0f - 3.0f;
	rgb = saturate(abs(rgb) - 1.0f);
	rgb = (rgb - 1.0f) * s + 1.0f;
	rgb *= v;
	return rgb;
}

// 定数バッファ
cbuffer buff : register(b0)
{
	// 時間
	float time;
	
	// 空白
	float3 padding;
}

float4 main(PS_INPUT input) : SV_TARGET
{
	// メインテクスチャの色
	float4 color = tex.Sample(texSampler, input.uv);
	
	// 虹色を乗算する
	color *= float4(HSV2RGB(time + input.uv.y, 1.0f, 1.0f), 1.0f);
	
	return color;
}