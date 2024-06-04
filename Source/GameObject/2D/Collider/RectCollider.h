#pragma once
#include "AbstractCollider.h"

/// @brief ��`�̃R���C�_�[�N���X�ł�
class RectCollider : public AbstractCollider {
public:
	RectCollider(void);
	~RectCollider(void) override = default;

	RectCollider(const Vector2<float>& centerPos, const Vector2<float>& size);

	bool IsContains(const Vector2<float>& point) const override;
	const Vector2<float>& GetSize(void) const;
private:
	// ��`�̃T�C�Y(Width : Height)
	Vector2<float> size_;

};

