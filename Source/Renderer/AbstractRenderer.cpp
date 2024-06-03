#include "AbstractRenderer.h"

AbstractRenderer::AbstractRenderer(void) : 
defaultScreenHadle_(-1),
useLocalPos_(false){}

AbstractRenderer::AbstractRenderer(bool useLocalPos) : 
defaultScreenHadle_(-1),
useLocalPos_(useLocalPos){}

bool AbstractRenderer::UseLocalPos(void) const {
	return useLocalPos_;
}

void AbstractRenderer::SetUseLocalPos(bool flag) {
	useLocalPos_ = flag;
}
