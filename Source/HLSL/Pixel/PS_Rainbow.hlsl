#include "PixelShader_Header.hlsli"

// HSV��RGB�ɕϊ�(Kamoshika�����)
float3 HSV2RGB(float h, float s, float v)
{
	float3 rgb = frac(h + float3(0.0f, 2.0f, 1.0f) / 3.0f) * 6.0f - 3.0f;
	rgb = saturate(abs(rgb) - 1.0f);
	rgb = (rgb - 1.0f) * s + 1.0f;
	rgb *= v;
	return rgb;
}

// �萔�o�b�t�@
cbuffer buff : register(b0)
{
	// ����
	float time;
	
	// ��
	float3 padding;
}

float4 main(PS_INPUT input) : SV_TARGET
{
	// ���C���e�N�X�`���̐F
	float4 color = tex.Sample(texSampler, input.uv);
	
	// ���F����Z����
	color *= float4(HSV2RGB(time + input.uv.y, 1.0f, 1.0f), 1.0f);
	
	return color;
}