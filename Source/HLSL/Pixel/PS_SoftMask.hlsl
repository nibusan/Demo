#include "PixelShader_Header.hlsli"

Texture2D maskTex : register(t1);
SamplerState maskTexSampler : register(s1);

// �萔�o�b�t�@
cbuffer buff : register(b0)
{
	// �}�X�N�̋���(?)
	// �f�t�H���g��1.0f�ł�
	float maskPow;
	
	// ��
	float3 padding;
}

float4 main(PS_INPUT input) : SV_TARGET
{
	// �e�e�N�X�`���̐F
	float4 color = tex.Sample(texSampler, input.uv);
	float4 maskColor = maskTex.Sample(maskTexSampler, input.uv);
	
	// �\�t�g�}�X�N�̉摜�̐F�����C���e�N�X�`���̓����x�Ƃ��Ďg��
	// �}�X�N�摜�͔����Ȃ̂œK����r���w�肵�Ă܂�
	color.a = maskColor.r * maskPow;
	
	return color;
}