#pragma once
#include "GameObject.h"
#include "Transform2D.h"
#include "../Common/Vector2.h"

class GameObject2D : public GameObject {
public:
	GameObject2D(void) = default;
	virtual ~GameObject2D(void) override = default;

	/// @brief 親オブジェクトをセット
	/// @param parent 親オブジェクト
	void SetParent(std::weak_ptr<GameObject> parent) override;

	/// @brief 子オブジェクトを追加する
	/// @param child 子オブジェクト
	void AddChild(std::shared_ptr<GameObject> child) override;

	/// @brief 2DのゲームオブジェクトのTransformの参照を返す 
	/// @note 外部から中身を弄ることがあるのであえてconstを外してます
	/// @return 2DのTransform
	[[nodiscard]] Transform2D& GetTransform(void);
	
	/// @brief Transformに渡すデータをセットする
	/// @param localPos ローカル座標
	/// @param localRot ローカル角度(名前変かも)
	/// @param localScl ローカルスケール値(名前変かも)
	void SetTransformData( 
		const Vector2<float>& localPos, 
		float localRot, 
		const Vector2<float>& localScl
	);

	/// @brief このゲームオブジェクトの現在の座標(親の座標も計算済み)を返す
	/// @return 座標
	Vector2<float> GetWorldPos(void);
protected:
	// ゲームオブジェクトの基礎データ
	Transform2D transform_;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	// 派生クラスで定義 
	virtual void Init_GameObject2D(void) = 0;
	virtual void Update_GameObject2D(void) = 0;
	virtual void Release_GameObject2D(void) = 0;

private:
	/// @brief 親オブジェクトを考慮して現在のTransform(2D)のcurrentの値を計算する
	void CalculateTransform2D(void);

};
