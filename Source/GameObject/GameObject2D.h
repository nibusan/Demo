#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "../Common/Vector2.h"

class GameObject2D : public GameObject {
public:
	GameObject2D(void) = default;
	virtual ~GameObject2D(void) override = default;

	/// @brief 2DのゲームオブジェクトのTransformを返す 
	/// @return 2DのTransform
	[[nodiscard]] const Transform<Vector2<float>>& GetTransform(void) const;
	
	/// @brief Transformに渡すデータをセットする
	/// @param pos 座標
	/// @param localPos ローカル座標
	/// @param rot 角度
	/// @param localRot ローカル角度(名前変かも)
	/// @param scl スケール値
	/// @param localScl ローカルスケール値(名前変かも)
	void SetTransformData(
		const Vector2<float>& pos, 
		const Vector2<float>& localPos, 
		const Vector2<float>& rot, 
		const Vector2<float>& localRot, 
		const Vector2<float>& scl,
		const Vector2<float>& localScl
	);
protected:
	// ゲームオブジェクトの基礎データ
	Transform<Vector2<float>> transform_;

	virtual void Init_GameObject(void) = 0;
	virtual void Update_GameObject(void) = 0;
	virtual void Release_GameObject(void) = 0;
};
