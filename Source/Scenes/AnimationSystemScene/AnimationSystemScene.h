#pragma once
#include "../AbstractScene.h"

class AnimationSystemScene : AbstractScene {
public:
	AnimationSystemScene(void);
	~AnimationSystemScene(void) override = default;

	void Init(void) override;
	void Update(void) override;
	void Release(void) override;

private:

};