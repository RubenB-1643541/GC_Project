#ifndef FROST_LIGHTS_HEADLAMP
#define FROST_LIGHTS_HEADLAMP

#include "Point3D.h"
#include <qopengl.h>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The HeadLamp class
 */
class HeadLamp {
public:
	HeadLamp();
	
    ////////////////////////////////////////////////////////
    /// Render
    ////////////////////////////////////////////////////////
    void openGlRender(GLenum light);

	////////////////////////////////////////////////////////
	/// Modify
	////////////////////////////////////////////////////////
	void setPosition(const Point3D position);
    void setConeAngle(const float degrees);
    void setRgba(const float r, const float g, const float b, const float a);
	
	////////////////////////////////////////////////////////
	/// Enabling and Disabling
	////////////////////////////////////////////////////////
	bool isEnabled() const;
	void isEnabled(const bool is_enabled);
	void toggle();
private:
    Point3D _position;
	
    float _cone_angle;
	bool _is_enabled;
	
	enum RGBA {
		R,
		G,
		B,
		A
    };
    float _rgba[4];
};

}
#endif FROST_LIGHTS_HEADLAMP
