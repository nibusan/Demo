#pragma once
#include "../GameObject.h"
#include "Transform3D.h"
#include "../../Common/Vector3.h"

class GameObject3D : public GameObject {
public:
	GameObject3D(void) = default;
	virtual ~GameObject3D(void) override = default;

	/// @brief 子オブジェクトを追加する
	/// @param child 子オブジェクト
	void AddChild(std::shared_ptr<GameObject> child) override;

	/// @brief 3DのゲームオブジェクトのTransformの参照を返す 
	/// @note 外部から中身を弄ることがあるのであえてconstを外してます
	/// @return 3DのTransform
	[[nodiscard]] Transform3D& GetTransform(void);
	
	/// @brief Transformに渡すデータをセットする
	/// @param localPos ローカル座標
	/// @param localRot ローカル角度(名前変かも)
	/// @param localScl ローカルスケール値(名前変かも)
	void SetTransformData( 
		const Vector3<float>& localPos, 
		const Vector3<float>& localRot, 
		const Vector3<float>& localScl
	);
protected:
	// ゲームオブジェクトの基礎データ
	Transform3D transform_;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	// 派生クラスで定義 
	virtual void Init_GameObject3D(void) = 0;
	virtual void Update_GameObject3D(void) = 0;
	virtual void Release_GameObject3D(void) = 0;

	/// @brief 親オブジェクトをセット
	/// @param parent 親オブジェクト
	void SetParent(std::weak_ptr<GameObject> parent) override;
private:
	/// @brief 親オブジェクトを考慮して現在のTransform(3D)のcurrentの値を計算する
	void CalculateTransform3D(void);

};