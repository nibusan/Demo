#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "../../../Common/Vector2.h"

class GameObject2D : public GameObject {
public:
	GameObject2D(void) = default;
	GameObject2D(const Vector2<float>& pos, const Vector2<float>& rot, const Vector2<float>& scl);
	virtual ~GameObject2D(void) override = default;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Draw_GameObject(void) override;
	void Release_GameObject(void) override;

	/// @brief 2DのゲームオブジェクトのTransformを返す 
	/// @return 2DのTransform
	[[nodiscard]] const Transform<Vector2<float>>& GetTransform(void) const;
	
	/// @brief 2DのゲームオブジェクトのTransformを返す 
	/// @param 2DのTransform
	void SetTransform(const Transform<Vector2<float>>& transform);
protected:
	// ゲームオブジェクトの基礎データ
	Transform<Vector2<float>> transform_;
};

