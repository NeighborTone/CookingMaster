
namespace easing
{
	// t=経過時間、b=始点、c=終点ー始点、d=持続時間
	float BounceOut(float t, float b, float c, float d) {

				if ((t /= d) < (1 / 2.75f)) {
					return c*(7.5625f*t*t) + b;
				}
				else if (t < (2 / 2.75f)) {
					t -= (1.5f / 2.75f);
					return c*(7.5625f*t*t + .75f) + b;
				}
				else if (t < (2.5f / 2.75f)) {
					t -= (2.25f / 2.75f);
					return c*(7.5625f*t*t + .9375f) + b;
				}
				else {
					t -= (2.625f / 2.75f);
					return c*(7.5625f*t*t + .984375f) + b;
				}
	}
	float BounceIn(float t, float b, float c, float d) {
		return c - BounceOut(d - t, 0, c, d) + b;
	}
	
	float BounceInOut(float t, float b, float c, float d) {
		if (t < d / 2) return BounceIn(t * 2, 0, c, d) * .5f + b;
		else return BounceOut(t * 2 - d, 0, c, d) * .5f + c*.5f + b;
	}
}